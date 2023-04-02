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
vector<node *> construct(int start, int end)
{
    vector<node *> tree;
    if (start > end)
    {
        tree.push_back(NULL);
        return tree;
    }
    for (int i = start; i <= end; i++)
    {
        vector<node *> leftsubtrees = construct(start, i - 1);
        vector<node *> rightsubtrees = construct(i + 1, end);
        for (int j = 0; j < leftsubtrees.size(); j++)
        {
            node *left = leftsubtrees[j];
            for (int k = 0; k< rightsubtrees.size(); k++)
            {
                node *rigth = rightsubtrees[k];
                node *root = new node(i);
                root->l = left;
                root->r = rigth;
                tree.push_back(root);
            }
        }
    }
    return tree;
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->l);
    preorder(root->r);
}
int main()
{
    vector<node*> totaltree = construct(1, 3);
    for (int i = 0; i < totaltree.size(); i++)
    {
        cout << (i + 1) << ": ";
        preorder(totaltree[i]);
        cout<<endl;
    }
    return 0;
}