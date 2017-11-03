#include <bits/stdc++.h>

#define fi(a,b,c) for(int a=b; a<=c; a++)
#define fd(a,b,c) for(int a=b; a>=c; a--)

using namespace std;

int n;

struct  Tnode {
    int v, size_;
    bool needSwap;
    Tnode *left , *right , *parent;
}    *nilt , *root [2] ;

Tnode *M, *M1, *M2, *M3, *M4, *M5, *M6, *M7, *M8, *M9;

void Init () {
    nilt = new Tnode ;
    nilt->size_ = 0;
    root[0] = nilt;
}

Tnode *newnode(int v) {
    Tnode *p = new Tnode;
    p->needSwap = 0;
    p->size_ = 1;
    p->v = v;
    p->left = p->right = p->parent = nilt;
    return p;
}

void setlink (Tnode *x, Tnode *y, bool inleft) {
    y->parent = x;
    if (inleft ) x->left = y; else x->right = y;
}

void lazy_update(Tnode *x) {
    if (x== nilt || !x->needSwap) return;
    Tnode *pleft =  x->left; Tnode *pright = x->right;
    setlink(x,pleft,0);
    setlink(x,pright,1);
    x->needSwap = 0;
    x->left->needSwap ^= 1;
    x->right->needSwap ^= 1;
}

void uptree(Tnode *x) {
    Tnode *y =  x->parent;
    if (y == nilt) return;
    lazy_update(y);
    lazy_update(x);
    Tnode *z = y->parent;
    if (x == y->left) {
        setlink(y,x->right,1);
        setlink(x,y,0);
    }
    else {
        setlink(y,x->left,0);
        setlink(x,y,1);
    }
    setlink(z,x,z->left == y);
    y->size_ = 1 + y->left->size_ + y->right->size_;
    x->size_ = 1 + x->left->size_ + x->right->size_;
    lazy_update(z);
}

void splay(Tnode *x) {
    lazy_update(x);
    while(1) {
        Tnode *y= x->parent;
        if (y==nilt) return;
        Tnode *z= y->parent;
        if (x!= nilt && (z->left ==y) == (y->left == x)) uptree(y);
        uptree(x);
    }
}

Tnode *getnode(Tnode *root, int index ) {
    Tnode *p = root;
    while (1) {
        lazy_update(p);
        if (p->left->size_ +1 == index ) return p;
        else
            if (p->left->size_+1 <index) {
                index -= p->left->size_ +1;
                p= p->right;
            }
            else p=p->left;
    }
}

void split(Tnode *r, int index, Tnode *&ln, Tnode *&rn) {
    if (index == 0) {
        ln = nilt;
        rn = r;
        return;
    }
    if (index == r->size_) {
        ln = r;
        rn = nilt;
        return;
    }
    Tnode *p = getnode(r, index);
    splay(p);
    rn = p->right;
    rn->parent = nilt;

    p->right = nilt;
    p->size_ = p->left->size_ +1;
    ln = p;
}

Tnode *join(Tnode *ln, Tnode *rn) {
    if (ln==nilt ) return rn;
    if (rn==nilt ) return ln;
    lazy_update(ln);
    while (ln->right != nilt) {
        ln = ln->right;
        lazy_update(ln);
    }
    splay(ln);
    setlink(ln,rn,0);
    ln->size_ = ln->left->size_ + ln->right->size_ +1;
    return ln;
}

void builttree() {
    fi(i, 1, n) {
        Tnode *x = newnode(i);
        x= join(root[0], x);
        root[0] = x;
    }
    root[0]->parent = nilt;
}

void print(Tnode *T) {
    if (T == nilt) return;
    print (T->left);
    cout << T->v <<' ';
    print (T->right);
}

int main() {
    ios::sync_with_stdio(false);
  //  freopen("test.in", "r", stdin);
 //   freopen("test.out", "w", stdout);
    cin >>n;
    Init();
    builttree();
    int query;
    cin>>query;
    M= root[0];

    while (query--) {
        int i, m, j;
        cin >>i >>m >>j;
        split (M, i-1, M1, M2);
        split (M2, m, M3, M4);;
        M5 = join(M1, M4);
        split (M5, j-1 , M6, M7);
        M8 = join (M6, M3);
        M = join(M8, M7);
    }
    print (M);
    return 0;
}