#include "bits/stdc++.h"
using namespace std;
struct node
{
    int data;
    struct node *l;
    struct node *r;
    node(int x)
    {
        data = x;
        l = NULL;
        r = NULL;
    }
};
node *LCA(node *n, int n1, int n2)
{
    if (n == NULL)
    {
        return NULL;
    }
    if (n->data == n1 || n->data == n2)
    {
        return n;
    }
    node *left = LCA(n->l, n1, n2);
    node *right = LCA(n->r, n1, n2);
    if (left != NULL && right != NULL)
    {
        return n;
    }

    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    if (left != NULL)
    {
        return LCA(left->l, n1, n2);
    }
    return LCA(right->r, n1, n2);
}
int finddis(node *lca, int k, int dis)
{
    if (lca == NULL)
    {
        return -1;
    }
    if (lca->data == k)
    {
        return dis;
    }
    int left = finddis(lca->l, k, dis + 1);
    if (left != -1)
    {
        return left;
    }
    return finddis(lca->r, k, dis + 1);
}
int distace2nodes(node *n, int n1, int n2)
{
    node *lca = LCA(n, n1, n2);
    int d1 = finddis(lca, n1, 0);
    int d2 = finddis(lca, n2, 0);

    return d1 + d2;
}
int main()
{
    node *root = new node(1);
    root->l = new node(2);
    root->r = new node(3);
    root->l->l = new node(4);
    root->l->r = new node(5);

    cout << distace2nodes(root, 4, 1);
    return 0;
}