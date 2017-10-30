#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9;

class Treap {
    int key, sz, val;
    bool rev;
    Treap(const int& key, const int& val) :
        key(key), sz(1), val(val), rev(false) {
        child[0] = child[1] = NULL;
    }
    Treap *child[2];

    static int getSz(Treap *&root) {
        return root == NULL ? 0 : root->sz;
    }

    static int getKey(Treap *&root) {
        return root == NULL ? oo : root->key;
    }

    static void update(Treap *&root) {
        if (root == NULL)
            return;
        root->sz = getSz(root->child[0]) +
            getSz(root->child[1]) + 1;
    }

    static void down(Treap *&root) {
        if (root->rev) {
            swap(root->child[0], root->child[1]);
            if (root->child[0] != NULL)
                root->child[0]->rev ^= 1;
            if (root->child[1] != NULL)
                root->child[1]->rev ^= 1;
            root->rev = false;
        }
    }

    static void rotate(Treap *&root, const int& dir) {
        if (root == NULL)
            return;
        Treap *cache = root->child[dir];
        down(cache);
        root->child[dir] = cache->child[dir ^ 1];
        cache->child[dir ^ 1] = root;
        update(root);
        update(cache);
        root = cache;
    }

    static void erase_this(Treap *&root) {
        if (root == NULL)
            return;
        down(root);
        if (root->child[0] == NULL &&
            root->child[1] == NULL) {

            delete root;
            root = NULL;
            return;
        }

        int dir = (getKey(root->child[0]) <
            getKey(root->child[1]) ? 0 : 1);

        rotate(root, dir);
        erase_this(root->child[dir ^ 1]);
        update(root);
    }

    static void split(Treap *root,
        Treap *&A, Treap *&B, const int& pos) {

        if (root == NULL)
            return;
        insert(root, pos + 1, 0, -1);
        A = root->child[0];
        B = root->child[1];
        delete root;
    }

    static void merge(Treap *&root,
        Treap *A, Treap *B) {

        root = A;
        insert(root, getSz(A) + 1, 0, -1);
        root->child[1] = B;
        update(root);
        erase(root, getSz(A) + 1);
    }

public:
    static void insert(Treap *&root, const int& pos,
        const int& val, const int& key) {

        if (root == NULL) {
            root = new Treap(key, val);
            return;
        }
        down(root);
        int szLef = getSz(root->child[0]);
        int dir = (pos > szLef + 1 ? 1 : 0);
        insert(root->child[dir],
            pos - (dir == 0 ? 0 : szLef + 1),
            val, key);

        if (root->key > root->child[dir]->key)
            rotate(root, dir);
        update(root);
    }

    static int findVal(Treap *&root, const int& pos) {
        if (root == NULL)
            return -1;
        down(root);
        int szLef = getSz(root->child[0]);
        if (pos == szLef + 1)
            return root->val;
        if (pos > szLef + 1)
            return
            findVal(root->child[1], pos - szLef - 1);

        return findVal(root->child[0], pos);
    }

    static void erase(Treap *&root, const int& pos) {
        if (root == NULL)
            return;
        down(root);
        int szLef = getSz(root->child[0]);
        if (pos == szLef + 1)
            erase_this(root);
        else
            if (pos > szLef + 1)
                erase(root->child[1],
                    pos - szLef - 1);
            else
                erase(root->child[0], pos);
        update(root);
    }

    static void reverse(Treap *&root,
        const int& lef, const int& rig) {

        Treap *A = NULL, *B = NULL, *C = NULL;
        split(root, A, B, lef - 1);
        split(B, B, C, rig - lef + 1);
        B->rev = true;
        merge(root, A, B);
        merge(root, root, C);
    }

    static void clear(Treap *&root) {
        if (root == NULL)
            return;
        clear(root->child[0]);
        clear(root->child[1]);
        delete root;
        root = NULL;
    }
};

Treap *root = NULL;