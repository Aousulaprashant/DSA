#include "bits/stdc++.h"
using namespace std;
struct node
{
    int data;
    node *l;
    node *r;
    node(int x)
    {
        data = x;
        l = NULL;
        r = NULL;
    }
};
bool check_bst(node *root, node *min, node *max)
{
    if (root == NULL)
    {
        return true;
    }
    if (min!=NULL && root->data <= min->data)
    {
        return false;
    }
    if(max!=NULL and root->data >= max->data){
         return false;
    }
    bool left = check_bst(root->l, min, root);
    bool right = check_bst(root->r, root, max);
    return left and right;
}
int main()
{
    node *root = new node(4);
    root->l = new node(2);
    root->r = new node(5);
    root->l->l = new node(89);
    root->r->r = new node(6);
    root->l->r = new node(3);

    if (check_bst(root, NULL, NULL))
    {
        cout << "valide!!\n";
    }
    else
    {
        cout << "invalide!!\n";
    }
}