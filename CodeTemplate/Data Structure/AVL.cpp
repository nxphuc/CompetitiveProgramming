#include <stdio.h>
#include <algorithm>
using namespace std;

const int oo = 2e9;

class NodeAVL {
    int val, mx, h, sz;
    NodeAVL *lef, *rig;
    NodeAVL(const int& val) :
        val(val), mx(val), sz(1),
        h(1), lef(NULL), rig(NULL) {}

    static int getHeight(NodeAVL *&r) {
        return r == NULL ? 0 : r->h;
    }

    static int getSize(NodeAVL *&r) {
        return r == NULL ? 0 : r->sz;
    }

    static int getMx(NodeAVL *&r) {
        return r == NULL ? -oo : r->mx;
    }

    static void update(NodeAVL *&r) {
        if (r == NULL) return;
        r->h = max(getHeight(r->lef), getHeight(r->rig)) + 1;
        r->sz = getSize(r->lef) + getSize(r->rig) + 1;
        r->mx = max(r->val, max(getMx(r->lef), getMx(r->rig)));
    }

    static void LL(NodeAVL *&r) {
        NodeAVL *node = r->lef;
        r->lef = node->rig;
        node->rig = r;

        r = node;
        update(r->rig);
        update(r);
    }

    static void RR(NodeAVL *&r) {
        NodeAVL *node = r->rig;
        r->rig = node->lef;
        node->lef = r;

        r = node;
        update(r->lef);
        update(r);
    }

    static void LR(NodeAVL *&r) {
        RR(r->lef);
        LL(r);
    }

    static void RL(NodeAVL *&r) {
        LL(r->rig);
        RR(r);
    }

    static void balance(NodeAVL *&r) {
        if (r == NULL)
            return;

        int bal = getHeight(r->lef) - getHeight(r->rig);
        if (bal == 2) {
            NodeAVL *node = r->lef;
            if (getHeight(node->lef) -
                getHeight(node->rig) == -1)
                LR(r);
            else
                LL(r);
        }

        if (bal == -2) {
            NodeAVL *node = r->rig;
            if (getHeight(node->lef) -
                getHeight(node->rig) == 1)
                RL(r);
            else
                RR(r);
        }
    }

    static void change(NodeAVL *&r, NodeAVL *& q) {
        if (r->rig)
            change(r->rig, q);
        else {
            q->val = r->val;
            q = r;
            r = r->lef;
        }

        update(r);
        balance(r);
    }
public:
    static void remove(NodeAVL *&r, const int& pos) {
        if (r == NULL) return;

        int szTmp = getSize(r->lef) + 1;
        if (pos < szTmp)
            remove(r->lef, pos);
        else
            if (pos > szTmp)
                remove(r->rig, pos - szTmp);
            else {
                NodeAVL *q = r;
                if (q->lef == NULL)
                    r = r->rig;
                else
                    if (q->rig == NULL)
                        r = r->lef;
                    else
                        change(r->lef, q);
                delete q;
            }

            update(r);
            balance(r);
    }

    static int getValue(NodeAVL *&r, const int& pos) {
        int szTmp = getSize(r->lef) + 1;
        if (pos < szTmp)
            return getValue(r->lef, pos);
        else
            if (pos > szTmp)
                return getValue(r->rig, pos - szTmp);
            else
                return r->val;
    }

    static void insert(NodeAVL *&r,
        const int& pos, const int& val) {

        if (r == NULL)
            r = new NodeAVL(val);
        else {
            int szTmp = getSize(r->lef) + 1;
            if (pos <= szTmp)
                insert(r->lef, pos, val);
            else
                insert(r->rig, pos - szTmp, val);

            update(r);
            balance(r);
        }
    }

    static void update(NodeAVL *&r,
        const int& pos, const int& val) {

        if (r == NULL) return;

        int szTmp = getSize(r->lef);
        if (pos <= szTmp)
            update(r->lef, pos, val);
        else
            if (pos > szTmp + 1)
                update(r->rig, pos - szTmp - 1, val);
            else
                r->val = val;

        update(r);
    }

    static int getMx(NodeAVL *&r,
        const int& u, const int& v,
        const int& lef = 1, int rig = -1) {

        if (rig == -1)
            rig = getSize(r);
        if (r == NULL || u > v)
            return -oo;
        if (u == lef && v == rig)
            return r->mx;

        int szTmp = getSize(r->lef) + 1;
        if (v < szTmp)
            return getMx(r->lef, u, v, lef, szTmp);
        if (u > szTmp)
            return getMx(r->rig, u - szTmp, v - szTmp, 1, rig - szTmp);
        int res = max(
            getMx(r->lef, u, szTmp, lef, szTmp),
            getMx(r->rig, 1, v - szTmp, 1, rig - szTmp)
        );
        return max(res, r->val);
    }

    static void erase(NodeAVL *&root) {
        if (root == NULL)
            return;
        erase(root->lef);
        erase(root->rig);
        delete root;
    }
};

NodeAVL *root = NULL;
