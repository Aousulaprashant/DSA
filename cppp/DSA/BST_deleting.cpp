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
node *inorprec(node *root)
{
    node *curr = root;
    while (curr && curr->l != NULL)
    {
        curr = curr->l;
    }
    return curr;
}
node *delete_node(node *root, int n)
{
    if (n < root->data)
    {
        root->l = delete_node(root->l, n);
    }
    else if (n < root->data)
    {
        root->r = delete_node(root->r, n);
    }
    else
    {
        if (root->l == NULL)
        {
            node *temp = root->r;
            free(root);
            return temp;
        }
        else if (root->r == NULL)
        {
            node *temp = root->l;
            free(root);
            return temp;
        }

        node *temp = inorprec(root->r);
        root->data = temp->data;
        root->r = delete_node(root->r, temp->data);
    }
    return root;
}
int inorder(node*root){
    if(root==NULL){
        return 0;
    }
    inorder(root->l);
    cout<<root->data<<" ";
    inorder(root->r);
}
int main()
{

    node *root = new node(4);
    root->l = new node(2);
    root->r = new node(5);
    root->l->l = new node(1);
    root->r->r = new node(6);

    root->l->r = new node(3);
    inorder(root);
    delete_node(root,5);
    cout<<"\n";
    inorder(root);
     return 0;

}