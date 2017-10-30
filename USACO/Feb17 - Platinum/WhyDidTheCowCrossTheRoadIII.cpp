/*
Author:
Prob:
Link:
Tag:
Comp:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair<ii, int>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define cl(a) a.clear()

#define vi vector<int>
#define vii vector<ii>

#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)

const int MAX = 1e6 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

#ifndef MAX_INT
#define MAX_INT INT_MAX // some architechturs define INT_MAX not MAX_INT
#endif

// The Interval class is an Abstract Base Class.  This means that no
// instance of the Interval class can exist.  Only classes which
// inherit from the Interval class can exist.  Furthermore any class
// which inherits from the Interval class must define the member
// functions GetLowPoint and GetHighPoint.
//
// The GetLowPoint should return the lowest point of the interval and
// the GetHighPoint should return the highest point of the interval.  

class Interval {
public:
		Interval();
		virtual ~Interval();
		virtual int GetLowPoint() const = 0;
		virtual int GetHighPoint() const = 0;
		virtual void Print() const;
};

class IntervalTreeNode {
		friend class IntervalTree;
public:
		void Print(IntervalTreeNode*,
						IntervalTreeNode*) const;
		IntervalTreeNode();
		IntervalTreeNode(Interval *);
		~IntervalTreeNode();
protected:
		Interval * storedInterval;
		int key;
		int high;
		int maxHigh;
		int red; /* if red=0 then the node is black */
		IntervalTreeNode * left;
		IntervalTreeNode * right;
		IntervalTreeNode * parent;
};

struct it_recursion_node {
public:
		/*  this structure stores the information needed when we take the */
		/*  right branch in searching for intervals but possibly come back */
		/*  and check the left branch as well. */

		IntervalTreeNode * start_node;
		unsigned int parentIndex;
		int tryRightBranch;
} ;


class IntervalTree {
public:
		IntervalTree();
		~IntervalTree();
		void Print() const;
		Interval * DeleteNode(IntervalTreeNode *);
		IntervalTreeNode * Insert(Interval *);
		IntervalTreeNode * GetPredecessorOf(IntervalTreeNode *) const;
		IntervalTreeNode * GetSuccessorOf(IntervalTreeNode *) const;
		TemplateStack<void *> * Enumerate(int low, int high) ;
		TemplateStack<void *> * EnumerateContained(int low, int high) ;
		void CheckAssumptions() const;
protected:
		/*  A sentinel is used for root and for nilNode.  These sentinels are */
		/*  created when ITTreeCreate is called.  root->left should always */
		/*  point to the node which is the root of the tree.  `nilNode` points to a */
		/*  node which should always be black, but has arbitrary children and */
		/*  parent and no key or info.  The point of using these sentinels is so */
		/*  that the root and nilNode nodes do not require special cases in the code */
		IntervalTreeNode * root;
		IntervalTreeNode * nilNode;
		void LeftRotate(IntervalTreeNode *);
		void RightRotate(IntervalTreeNode *);
		void TreeInsertHelp(IntervalTreeNode *);
		void TreePrintHelper(IntervalTreeNode *) const;
		void FixUpMaxHigh(IntervalTreeNode *);
		void DeleteFixUp(IntervalTreeNode *);
		void CheckMaxHighFields(IntervalTreeNode *) const;
		int CheckMaxHighFieldsHelper(IntervalTreeNode * y, 
			const int currentHigh,
			int match) const;
private:
		unsigned int recursionNodeStackSize;
		it_recursion_node * recursionNodeStack;
		unsigned int currentParent;
		unsigned int recursionNodeStackTop;
};


// If the symbol CHECK_INTERVAL_TREE_ASSUMPTIONS is defined then the
// code does a lot of extra checking to make sure certain assumptions
// are satisfied.  This only needs to be done if you suspect bugs are
// present or if you make significant changes and want to make sure
// your changes didn't mess anything up.
// #define CHECK_INTERVAL_TREE_ASSUMPTIONS 1


const int MIN_INT=-MAX_INT;

// define a function to find the maximum of two objects.
#define ITMax(a, b) ( (a > b) ? a : b )

IntervalTreeNode::IntervalTreeNode(){
}

IntervalTreeNode::IntervalTreeNode(Interval * newInterval) 
	: storedInterval (newInterval) ,
		key(newInterval->GetLowPoint()), 
		high(newInterval->GetHighPoint()) , 
		maxHigh(high) {
}
IntervalTreeNode::~IntervalTreeNode(){
}
Interval::Interval(){
}
Interval::~Interval(){
}
void Interval::Print() const {
	cout << "No Print Method defined for instance of Interval" << endl;
}

IntervalTree::IntervalTree()
{
	nilNode = new IntervalTreeNode;
	nilNode->left = nilNode->right = nilNode->parent = nilNode;
	nilNode->red = 0;
	nilNode->key = nilNode->high = nilNode->maxHigh = MIN_INT;
	nilNode->storedInterval = NULL;
	
	root = new IntervalTreeNode;
	root->parent = root->left = root->right = nilNode;
	root->key = root->high = root->maxHigh = MAX_INT;
	root->red=0;
	root->storedInterval = NULL;

	/* the following are used for the Enumerate function */
	recursionNodeStackSize = 128;
	recursionNodeStack = (it_recursion_node *) 
		SafeMalloc(recursionNodeStackSize*sizeof(it_recursion_node));
	recursionNodeStackTop = 1;
	recursionNodeStack[0].start_node = NULL;
	
}

/***********************************************************************/
/*  FUNCTION:  LeftRotate */
/**/
/*  INPUTS:  the node to rotate on */
/**/
/*  OUTPUT:  None */
/**/
/*  Modifies Input: this, x */
/**/
/*  EFFECTS:  Rotates as described in _Introduction_To_Algorithms by */
/*            Cormen, Leiserson, Rivest (Chapter 14).  Basically this */
/*            makes the parent of x be to the left of x, x the parent of */
/*            its parent before the rotation and fixes other pointers */
/*            accordingly. Also updates the maxHigh fields of x and y */
/*            after rotation. */
/***********************************************************************/

void IntervalTree::LeftRotate(IntervalTreeNode* x) {
	IntervalTreeNode* y;
	
	/*  I originally wrote this function to use the sentinel for */
	/*  nilNode to avoid checking for nilNode.  However this introduces a */
	/*  very subtle bug because sometimes this function modifies */
	/*  the parent pointer of nilNode.  This can be a problem if a */
	/*  function which calls LeftRotate also uses the nilNode sentinel */
	/*  and expects the nilNode sentinel's parent pointer to be unchanged */
	/*  after calling this function.  For example, when DeleteFixUP */
	/*  calls LeftRotate it expects the parent pointer of nilNode to be */
	/*  unchanged. */

	y=x->right;
	x->right=y->left;

	if (y->left != nilNode) y->left->parent=x; /* used to use sentinel here */
	/* and do an unconditional assignment instead of testing for nilNode */
	
	y->parent=x->parent;   

	/* instead of checking if x->parent is the root as in the book, we */
	/* count on the root sentinel to implicitly take care of this case */
	if( x == x->parent->left) {
		x->parent->left=y;
	} else {
		x->parent->right=y;
	}
	y->left=x;
	x->parent=y;

	x->maxHigh=ITMax(x->left->maxHigh,ITMax(x->right->maxHigh,x->high));
	y->maxHigh=ITMax(x->maxHigh,ITMax(y->right->maxHigh,y->high));
#ifdef CHECK_INTERVAL_TREE_ASSUMPTIONS
	CheckAssumptions();
#elif defined(DEBUG_ASSERT)
	Assert(!nilNode->red,C_TEXT("nilNode not red in ITLeftRotate"));
	Assert((nilNode->maxHigh=MIN_INT),
		C_TEXT("nilNode->maxHigh != MIN_INT in ITLeftRotate"));
#endif
}


/***********************************************************************/
/*  FUNCTION:  RightRotate */
/**/
/*  INPUTS:  node to rotate on */
/**/
/*  OUTPUT:  None */
/**/
/*  Modifies Input?: this, y */
/**/
/*  EFFECTS:  Rotates as described in _Introduction_To_Algorithms by */
/*            Cormen, Leiserson, Rivest (Chapter 14).  Basically this */
/*            makes the parent of x be to the left of x, x the parent of */
/*            its parent before the rotation and fixes other pointers */
/*            accordingly. Also updates the maxHigh fields of x and y */
/*            after rotation. */
/***********************************************************************/


void IntervalTree::RightRotate(IntervalTreeNode* y) {
	IntervalTreeNode* x;

	/*  I originally wrote this function to use the sentinel for */
	/*  nilNode to avoid checking for nilNode.  However this introduces a */
	/*  very subtle bug because sometimes this function modifies */
	/*  the parent pointer of nilNode.  This can be a problem if a */
	/*  function which calls LeftRotate also uses the nilNode sentinel */
	/*  and expects the nilNode sentinel's parent pointer to be unchanged */
	/*  after calling this function.  For example, when DeleteFixUP */
	/*  calls LeftRotate it expects the parent pointer of nilNode to be */
	/*  unchanged. */

	x=y->left;
	y->left=x->right;

	if (nilNode != x->right)  x->right->parent=y; /*used to use sentinel here */
	/* and do an unconditional assignment instead of testing for nilNode */

	/* instead of checking if x->parent is the root as in the book, we */
	/* count on the root sentinel to implicitly take care of this case */
	x->parent=y->parent;
	if( y == y->parent->left) {
		y->parent->left=x;
	} else {
		y->parent->right=x;
	}
	x->right=y;
	y->parent=x;

	y->maxHigh=ITMax(y->left->maxHigh,ITMax(y->right->maxHigh,y->high));
	x->maxHigh=ITMax(x->left->maxHigh,ITMax(y->maxHigh,x->high));
#ifdef CHECK_INTERVAL_TREE_ASSUMPTIONS
	CheckAssumptions();
#elif defined(DEBUG_ASSERT)
	Assert(!nilNode->red,C_TEXT("nilNode not red in ITRightRotate"));
	Assert((nilNode->maxHigh=MIN_INT),
		C_TEXT("nilNode->maxHigh != MIN_INT in ITRightRotate"));
#endif
}

/***********************************************************************/
/*  FUNCTION:  TreeInsertHelp  */
/**/
/*  INPUTS:  z is the node to insert */
/**/
/*  OUTPUT:  none */
/**/
/*  Modifies Input:  this, z */
/**/
/*  EFFECTS:  Inserts z into the tree as if it were a regular binary tree */
/*            using the algorithm described in _Introduction_To_Algorithms_ */
/*            by Cormen et al.  This function is only intended to be called */
/*            by the InsertTree function and not by the user */
/***********************************************************************/

void IntervalTree::TreeInsertHelp(IntervalTreeNode* z) {
	/*  This function should only be called by InsertITTree (see above) */
	IntervalTreeNode* x;
	IntervalTreeNode* y;
		
	z->left=z->right=nilNode;
	y=root;
	x=root->left;
	while( x != nilNode) {
		y=x;
		if ( x->key > z->key) { 
			x=x->left;
		} else { /* x->key <= z->key */
			x=x->right;
		}
	}
	z->parent=y;
	if ( (y == root) ||
				(y->key > z->key) ) { 
		y->left=z;
	} else {
		y->right=z;
	}


#if defined(DEBUG_ASSERT)
	Assert(!nilNode->red,C_TEXT("nilNode not red in ITTreeInsertHelp"));
	Assert((nilNode->maxHigh=MIN_INT),
		C_TEXT("nilNode->maxHigh != MIN_INT in ITTreeInsertHelp"));
#endif
}


/***********************************************************************/
/*  FUNCTION:  FixUpMaxHigh  */
/**/
/*  INPUTS:  x is the node to start from*/
/**/
/*  OUTPUT:  none */
/**/
/*  Modifies Input:  this */
/**/
/*  EFFECTS:  Travels up to the root fixing the maxHigh fields after */
/*            an insertion or deletion */
/***********************************************************************/

void IntervalTree::FixUpMaxHigh(IntervalTreeNode * x) {
	while(x != root) {
		x->maxHigh=ITMax(x->high,ITMax(x->left->maxHigh,x->right->maxHigh));
		x=x->parent;
	}
#ifdef CHECK_INTERVAL_TREE_ASSUMPTIONS
	CheckAssumptions();
#endif
}

/*  Before calling InsertNode  the node x should have its key set */

/***********************************************************************/
/*  FUNCTION:  InsertNode */
/**/
/*  INPUTS:  newInterval is the interval to insert*/
/**/
/*  OUTPUT:  This function returns a pointer to the newly inserted node */
/*           which is guarunteed to be valid until this node is deleted. */
/*           What this means is if another data structure stores this */
/*           pointer then the tree does not need to be searched when this */
/*           is to be deleted. */
/**/
/*  Modifies Input: tree */
/**/
/*  EFFECTS:  Creates a node node which contains the appropriate key and */
/*            info pointers and inserts it into the tree. */
/***********************************************************************/

IntervalTreeNode * IntervalTree::Insert(Interval * newInterval)
{
	IntervalTreeNode * y;
	IntervalTreeNode * x;
	IntervalTreeNode * newNode;

	x = new IntervalTreeNode(newInterval);
	TreeInsertHelp(x);
	FixUpMaxHigh(x->parent);
	newNode = x;
	x->red=1;
	while(x->parent->red) { /* use sentinel instead of checking for root */
		if (x->parent == x->parent->parent->left) {
			y=x->parent->parent->right;
			if (y->red) {
	x->parent->red=0;
	y->red=0;
	x->parent->parent->red=1;
	x=x->parent->parent;
			} else {
	if (x == x->parent->right) {
		x=x->parent;
		LeftRotate(x);
	}
	x->parent->red=0;
	x->parent->parent->red=1;
	RightRotate(x->parent->parent);
			} 
		} else { /* case for x->parent == x->parent->parent->right */
							/* this part is just like the section above with */
							/* left and right interchanged */
			y=x->parent->parent->left;
			if (y->red) {
	x->parent->red=0;
	y->red=0;
	x->parent->parent->red=1;
	x=x->parent->parent;
			} else {
	if (x == x->parent->left) {
		x=x->parent;
		RightRotate(x);
	}
	x->parent->red=0;
	x->parent->parent->red=1;
	LeftRotate(x->parent->parent);
			} 
		}
	}
	root->left->red=0;
	return(newNode);

#ifdef CHECK_INTERVAL_TREE_ASSUMPTIONS
	CheckAssumptions();
#elif defined(DEBUG_ASSERT)
	Assert(!nilNode->red,C_TEXT("nilNode not red in ITTreeInsert"));
	Assert(!root->red,C_TEXT("root not red in ITTreeInsert"));
	Assert((nilNode->maxHigh=MIN_INT),
		C_TEXT("nilNode->maxHigh != MIN_INT in ITTreeInsert"));
#endif
}

/***********************************************************************/
/*  FUNCTION:  GetSuccessorOf  */
/**/
/*    INPUTS:  x is the node we want the succesor of */
/**/
/*    OUTPUT:  This function returns the successor of x or NULL if no */
/*             successor exists. */
/**/
/*    Modifies Input: none */
/**/
/*    Note:  uses the algorithm in _Introduction_To_Algorithms_ */
/***********************************************************************/
	
IntervalTreeNode * IntervalTree::GetSuccessorOf(IntervalTreeNode * x) const
{ 
	IntervalTreeNode* y;

	if (nilNode != (y = x->right)) { /* assignment to y is intentional */
		while(y->left != nilNode) { /* returns the minium of the right subtree of x */
			y=y->left;
		}
		return(y);
	} else {
		y=x->parent;
		while(x == y->right) { /* sentinel used instead of checking for nilNode */
			x=y;
			y=y->parent;
		}
		if (y == root) return(nilNode);
		return(y);
	}
}

/***********************************************************************/
/*  FUNCTION:  GetPredecessorOf  */
/**/
/*    INPUTS:  x is the node to get predecessor of */
/**/
/*    OUTPUT:  This function returns the predecessor of x or NULL if no */
/*             predecessor exists. */
/**/
/*    Modifies Input: none */
/**/
/*    Note:  uses the algorithm in _Introduction_To_Algorithms_ */
/***********************************************************************/

IntervalTreeNode * IntervalTree::GetPredecessorOf(IntervalTreeNode * x) const {
	IntervalTreeNode* y;

	if (nilNode != (y = x->left)) { /* assignment to y is intentional */
		while(y->right != nilNode) { /* returns the maximum of the left subtree of x */
			y=y->right;
		}
		return(y);
	} else {
		y=x->parent;
		while(x == y->left) { 
			if (y == root) return(nilNode); 
			x=y;
			y=y->parent;
		}
		return(y);
	}
}

/***********************************************************************/
/*  FUNCTION:  Print */
/**/
/*    INPUTS:  none */
/**/
/*    OUTPUT:  none  */
/**/
/*    EFFECTS:  This function recursively prints the nodes of the tree */
/*              inorder. */
/**/
/*    Modifies Input: none */
/**/
/*    Note:    This function should only be called from ITTreePrint */
/***********************************************************************/

void IntervalTreeNode::Print(IntervalTreeNode * nilNode,
						IntervalTreeNode * root) const {
	storedInterval->Print();
	printf(", k=%i, h=%i, mH=%i",key,high,maxHigh);
	printf("  l->key=");
	if( left == nilNode) printf("NULL"); else printf("%i",left->key);
	printf("  r->key=");
	if( right == nilNode) printf("NULL"); else printf("%i",right->key);
	printf("  p->key=");
	if( parent == root) printf("NULL"); else printf("%i",parent->key);
	printf("  red=%i\n",red);
}

void IntervalTree::TreePrintHelper( IntervalTreeNode* x) const {
	
	if (x != nilNode) {
		TreePrintHelper(x->left);
		x->Print(nilNode,root);
		TreePrintHelper(x->right);
	}
}

IntervalTree::~IntervalTree() {
	IntervalTreeNode * x = root->left;
	TemplateStack<IntervalTreeNode *> stuffToFree;

	if (x != nilNode) {
		if (x->left != nilNode) {
			stuffToFree.Push(x->left);
		}
		if (x->right != nilNode) {
			stuffToFree.Push(x->right);
		}
		// delete x->storedInterval;
		delete x;
		while( stuffToFree.NotEmpty() ) {
			x = stuffToFree.Pop();
			if (x->left != nilNode) {
	stuffToFree.Push(x->left);
			}
			if (x->right != nilNode) {
	stuffToFree.Push(x->right);
			}
			// delete x->storedInterval;
			delete x;
		}
	}
	delete nilNode;
	delete root;
	free(recursionNodeStack);
}


/***********************************************************************/
/*  FUNCTION:  Print */
/**/
/*    INPUTS:  none */
/**/
/*    OUTPUT:  none */
/**/
/*    EFFECT:  This function recursively prints the nodes of the tree */
/*             inorder. */
/**/
/*    Modifies Input: none */
/**/
/***********************************************************************/

void IntervalTree::Print() const {
	TreePrintHelper(root->left);
}

/***********************************************************************/
/*  FUNCTION:  DeleteFixUp */
/**/
/*    INPUTS:  x is the child of the spliced */
/*             out node in DeleteNode. */
/**/
/*    OUTPUT:  none */
/**/
/*    EFFECT:  Performs rotations and changes colors to restore red-black */
/*             properties after a node is deleted */
/**/
/*    Modifies Input: this, x */
/**/
/*    The algorithm from this function is from _Introduction_To_Algorithms_ */
/***********************************************************************/

void IntervalTree::DeleteFixUp(IntervalTreeNode* x) {
	IntervalTreeNode * w;
	IntervalTreeNode * rootLeft = root->left;

	while( (!x->red) && (rootLeft != x)) {
		if (x == x->parent->left) {
			w=x->parent->right;
			if (w->red) {
	w->red=0;
	x->parent->red=1;
	LeftRotate(x->parent);
	w=x->parent->right;
			}
			if ( (!w->right->red) && (!w->left->red) ) { 
	w->red=1;
	x=x->parent;
			} else {
	if (!w->right->red) {
		w->left->red=0;
		w->red=1;
		RightRotate(w);
		w=x->parent->right;
	}
	w->red=x->parent->red;
	x->parent->red=0;
	w->right->red=0;
	LeftRotate(x->parent);
	x=rootLeft; /* this is to exit while loop */
			}
		} else { /* the code below is has left and right switched from above */
			w=x->parent->left;
			if (w->red) {
	w->red=0;
	x->parent->red=1;
	RightRotate(x->parent);
	w=x->parent->left;
			}
			if ( (!w->right->red) && (!w->left->red) ) { 
	w->red=1;
	x=x->parent;
			} else {
	if (!w->left->red) {
		w->right->red=0;
		w->red=1;
		LeftRotate(w);
		w=x->parent->left;
	}
	w->red=x->parent->red;
	x->parent->red=0;
	w->left->red=0;
	RightRotate(x->parent);
	x=rootLeft; /* this is to exit while loop */
			}
		}
	}
	x->red=0;

#ifdef CHECK_INTERVAL_TREE_ASSUMPTIONS
	CheckAssumptions();
#elif defined(DEBUG_ASSERT)
	Assert(!nilNode->red,C_TEXT("nilNode not black in ITDeleteFixUp"));
	Assert((nilNode->maxHigh=MIN_INT),
		C_TEXT("nilNode->maxHigh != MIN_INT in ITDeleteFixUp"));
#endif
}


/***********************************************************************/
/*  FUNCTION:  DeleteNode */
/**/
/*    INPUTS:  tree is the tree to delete node z from */
/**/
/*    OUTPUT:  returns the Interval stored at deleted node */
/**/
/*    EFFECT:  Deletes z from tree and but don't call destructor */
/*             Then calls FixUpMaxHigh to fix maxHigh fields then calls */
/*             ITDeleteFixUp to restore red-black properties */
/**/
/*    Modifies Input:  z */
/**/
/*    The algorithm from this function is from _Introduction_To_Algorithms_ */
/***********************************************************************/

Interval * IntervalTree::DeleteNode(IntervalTreeNode * z){
	IntervalTreeNode* y;
	IntervalTreeNode* x;
	Interval * returnValue = z->storedInterval;

	y= ((z->left == nilNode) || (z->right == nilNode)) ? z : GetSuccessorOf(z);
	x= (y->left == nilNode) ? y->right : y->left;
	if (root == (x->parent = y->parent)) { /* assignment of y->p to x->p is intentional */
		root->left=x;
	} else {
		if (y == y->parent->left) {
			y->parent->left=x;
		} else {
			y->parent->right=x;
		}
	}
	if (y != z) { /* y should not be nilNode in this case */

#ifdef DEBUG_ASSERT
		Assert( (y!=nilNode),C_TEXT("y is nilNode in DeleteNode \n"));
#endif
		/* y is the node to splice out and x is its child */
	
		y->maxHigh = MIN_INT;
		y->left=z->left;
		y->right=z->right;
		y->parent=z->parent;
		z->left->parent=z->right->parent=y;
		if (z == z->parent->left) {
			z->parent->left=y; 
		} else {
			z->parent->right=y;
		}
		FixUpMaxHigh(x->parent); 
		if (!(y->red)) {
			y->red = z->red;
			DeleteFixUp(x);
		} else
			y->red = z->red; 
		delete z;
#ifdef CHECK_INTERVAL_TREE_ASSUMPTIONS
		CheckAssumptions();
#elif defined(DEBUG_ASSERT)
		Assert(!nilNode->red,C_TEXT("nilNode not black in ITDelete"));
		Assert((nilNode->maxHigh=MIN_INT),C_TEXT("nilNode->maxHigh != MIN_INT in ITDelete"));
#endif
	} else {
		FixUpMaxHigh(x->parent);
		if (!(y->red)) DeleteFixUp(x);
		delete y;
#ifdef CHECK_INTERVAL_TREE_ASSUMPTIONS
		CheckAssumptions();
#elif defined(DEBUG_ASSERT)
		Assert(!nilNode->red,C_TEXT("nilNode not black in ITDelete"));
		Assert((nilNode->maxHigh=MIN_INT),C_TEXT("nilNode->maxHigh != MIN_INT in ITDelete"));
#endif
	}
	return returnValue;
}


/***********************************************************************/
/*  FUNCTION:  Overlap */
/**/
/*    INPUTS:  [a1,a2] and [b1,b2] are the low and high endpoints of two */
/*             closed intervals.  */
/**/
/*    OUTPUT:  boolean whether [a1,a2] overlaps [b1,b2] */
/**/
/*    Modifies Input: none */
/**/
/*    EFFECT:  returns 1 if the intervals overlap, and 0 otherwise */
/***********************************************************************/

int Overlap(int a1, int a2, int b1, int b2) {
	if (a1 <= b1) {
		return( (b1 <= a2) );
	} else {
		return( (a1 <= b2) );
	}
}


/***********************************************************************/
/*  FUNCTION:  Contains */
/**/
/*    INPUTS:  [a1,a2] and [b1,b2] are the low and high endpoints of two */
/*             closed intervals.  */
/**/
/*    OUTPUT:  boolean whether [a1,a2] contains [b1,b2] */
/**/
/*    Modifies Input: none */
/**/
/*    EFFECT:  returns 1 if interval a contains b, and 0 otherwise */
/***********************************************************************/

int Contains(int a1, int a2, int b1, int b2) {
	return(a1 <= b1 && b2 <= a2);
}


/***********************************************************************/
/*  FUNCTION:  Enumerate */
/**/
/*    INPUTS:  tree is the tree to look for intervals overlapping the */
/*             closed interval [low,high]  */
/**/
/*    OUTPUT:  stack containing pointers to the nodes overlapping */
/*             [low,high] */
/**/
/*    Modifies Input: none */
/**/
/*    EFFECT:  Returns a stack containing pointers to nodes containing */
/*             intervals which overlap [low,high] in O(max(N,k*log(N))) */
/*             where N is the number of intervals in the tree and k is  */
/*             the number of overlapping intervals                      */
/**/
/*    Note:    This basic idea for this function comes from the  */
/*              _Introduction_To_Algorithms_ book by Cormen et al, but */
/*             modifications were made to return all overlapping intervals */
/*             instead of just the first overlapping interval as in the */
/*             book.  The natural way to do this would require recursive */
/*             calls of a basic search function.  I translated the */
/*             recursive version into an interative version with a stack */
/*             as described below. */
/***********************************************************************/



/*  The basic idea for the function below is to take the IntervalSearch */
/*  function from the book and modify to find all overlapping intervals */
/*  instead of just one.  This means that any time we take the left */
/*  branch down the tree we must also check the right branch if and only if */
/*  we find an overlapping interval in that left branch.  Note this is a */
/*  recursive condition because if we go left at the root then go left */
/*  again at the first left child and find an overlap in the left subtree */
/*  of the left child of root we must recursively check the right subtree */
/*  of the left child of root as well as the right child of root. */

TemplateStack<void *> * IntervalTree::Enumerate(int low, 
							int high)  {
	TemplateStack<void *> *enumResultStack = 0;
	IntervalTreeNode* x=root->left;
	int stuffToDo = (x != nilNode);
	
	// Possible speed up: add min field to prune right searches //

#ifdef DEBUG_ASSERT
	Assert((recursionNodeStackTop == 1),
		C_TEXT("recursionStack not empty when entering IntervalTree::Enumerate"));
#endif
	currentParent = 0;
	enumResultStack = new TemplateStack<void *>(4);

	while(stuffToDo) {
		if (Overlap(low,high,x->key,x->high) ) {
			enumResultStack->Push(x->storedInterval);
			recursionNodeStack[currentParent].tryRightBranch=1;
		}
		if(x->left->maxHigh >= low) { // implies x != nilNode 
			if ( recursionNodeStackTop == recursionNodeStackSize ) {
	recursionNodeStackSize *= 2;
	recursionNodeStack = (it_recursion_node *) 
		realloc(recursionNodeStack,
			recursionNodeStackSize * sizeof(it_recursion_node));
	if (recursionNodeStack == NULL) 
		ExitProgramMacro(C_TEXT("realloc failed in IntervalTree::Enumerate\n"));
			}
			recursionNodeStack[recursionNodeStackTop].start_node = x;
			recursionNodeStack[recursionNodeStackTop].tryRightBranch = 0;
			recursionNodeStack[recursionNodeStackTop].parentIndex = currentParent;
			currentParent = recursionNodeStackTop++;
			x = x->left;
		} else {
			x = x->right;
		}
		stuffToDo = (x != nilNode);
		while( (!stuffToDo) && (recursionNodeStackTop > 1) ) {
	if(recursionNodeStack[--recursionNodeStackTop].tryRightBranch) {
		x=recursionNodeStack[recursionNodeStackTop].start_node->right;
		currentParent=recursionNodeStack[recursionNodeStackTop].parentIndex;
		recursionNodeStack[currentParent].tryRightBranch=1;
		stuffToDo = ( x != nilNode);
	}
		}
	}
#ifdef DEBUG_ASSERT
	Assert((recursionNodeStackTop == 1),
		C_TEXT("recursionStack not empty when exiting IntervalTree::Enumerate"));
#endif
	return(enumResultStack);   
}
	


/***********************************************************************/
/*  FUNCTION:  EnumerateContained */
/**/
/*    INPUTS:  tree is the tree to look for intervals overlapping the */
/*             closed interval [low,high]  */
/**/
/*    OUTPUT:  stack containing pointers to the nodes overlapping */
/*             [low,high] */
/**/
/*    Modifies Input: none */
/**/
/*    EFFECT:  Returns a stack containing pointers to nodes containing */
/*             intervals which are contained in [low,high] in O(max(N,k*log(N))) */
/*             where N is the number of intervals in the tree and k is  */
/*             the number of overlapping intervals                      */
/***********************************************************************/



/*  The basic idea for the function below is to take the IntervalSearch */
/*  function from the book and modify to find all contained intervals */
/*  instead of just one.  This means that any time we take the left */
/*  branch down the tree we must also check the right branch if and only if */
/*  we find an overlapping interval in that left branch.  Note this is a */
/*  recursive condition because if we go left at the root then go left */
/*  again at the first left child and find an overlap in the left subtree */
/*  of the left child of root we must recursively check the right subtree */
/*  of the left child of root as well as the right child of root. */

TemplateStack<void *> * IntervalTree::EnumerateContained(int low, int high)  {
	TemplateStack<void *> *enumResultStack = 0;
	IntervalTreeNode* x=root->left;
	int stuffToDo = (x != nilNode);
	
	// Possible speed up: add min field to prune right searches //
	
#ifdef DEBUG_ASSERT
	Assert((recursionNodeStackTop == 1),
					C_TEXT("recursionStack not empty when entering IntervalTree::EnumerateContained"));
#endif
	currentParent = 0;
	enumResultStack = new TemplateStack<void *>(4);
	
	while(stuffToDo) {
		if (Contains(low,high,x->key,x->high) ) {
			enumResultStack->Push(x->storedInterval);
			recursionNodeStack[currentParent].tryRightBranch=1;
		}
		if(x->left->key >= low) { // implies x != nilNode
			if ( recursionNodeStackTop == recursionNodeStackSize ) {
				recursionNodeStackSize *= 2;
				recursionNodeStack = (it_recursion_node *)
				realloc(recursionNodeStack,
								recursionNodeStackSize * sizeof(it_recursion_node));
				if (recursionNodeStack == NULL)
					ExitProgramMacro(C_TEXT("realloc failed in IntervalTree::EnumerateContained\n"));
			}
			recursionNodeStack[recursionNodeStackTop].start_node = x;
			recursionNodeStack[recursionNodeStackTop].tryRightBranch = 0;
			recursionNodeStack[recursionNodeStackTop].parentIndex = currentParent;
			currentParent = recursionNodeStackTop++;
			x = x->left;
		} else {
			x = x->right;
		}
		stuffToDo = (x != nilNode);
		while( (!stuffToDo) && (recursionNodeStackTop > 1) ) {
			if(recursionNodeStack[--recursionNodeStackTop].tryRightBranch) {
				x=recursionNodeStack[recursionNodeStackTop].start_node->right;
				currentParent=recursionNodeStack[recursionNodeStackTop].parentIndex;
				recursionNodeStack[currentParent].tryRightBranch=1;
				stuffToDo = ( x != nilNode);
			}
		}
	}
#ifdef DEBUG_ASSERT
	Assert((recursionNodeStackTop == 1),
					C_TEXT("recursionStack not empty when exiting IntervalTree::EnumerateContained"));
#endif
	return(enumResultStack);   
}



int IntervalTree::CheckMaxHighFieldsHelper(IntervalTreeNode * y,
						const int currentHigh,
						int match) const
{
	if (y != nilNode) {
		match = CheckMaxHighFieldsHelper(y->left,currentHigh,match) ?
			1 : match;
		VERIFY(y->high <= currentHigh);
		if (y->high == currentHigh)
			match = 1;
		match = CheckMaxHighFieldsHelper(y->right,currentHigh,match) ?
			1 : match;
	}
	return match;
}

		

/* Make sure the maxHigh fields for everything makes sense. *
	* If something is wrong, print a warning and exit */
void IntervalTree::CheckMaxHighFields(IntervalTreeNode * x) const {
	if (x != nilNode) {
		CheckMaxHighFields(x->left);
		if(!(CheckMaxHighFieldsHelper(x,x->maxHigh,0) > 0)) {
			ExitProgramMacro("error found in CheckMaxHighFields.\n");
		}
		CheckMaxHighFields(x->right);
	}
}

void IntervalTree::CheckAssumptions() const {
	VERIFY(nilNode->key == MIN_INT);
	VERIFY(nilNode->high == MIN_INT);
	VERIFY(nilNode->maxHigh == MIN_INT);
	VERIFY(root->key == MAX_INT);
	VERIFY(root->high == MAX_INT);
	VERIFY(root->maxHigh == MAX_INT);
	VERIFY(nilNode->storedInterval == NULL);
	VERIFY(root->storedInterval == NULL);
	VERIFY(nilNode->red == 0);
	VERIFY(root->red == 0);
	CheckMaxHighFields(root->left);
}


int main(){
	freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	return 0;
}