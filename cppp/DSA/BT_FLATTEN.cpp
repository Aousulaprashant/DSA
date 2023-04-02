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
void faltten(node *currnode){
    if(currnode==NULL || (currnode->l==NULL && currnode->r==NULL)){
        return;

    }
    if(currnode->l!=NULL){
        faltten(currnode->l);
        node *temp=currnode->r;
        currnode->r=currnode->l;
        currnode->l=NULL;
        node *t=currnode->r;
        while (t->r!=NULL)
        {
            /* code */
            t=t->r;
        }
        t->r=temp;
        
    }
    faltten(currnode->l);
}
int inorder(node * root){
    if(root==NULL){
        return 0;
    }
    inorder(root->l);
    cout<<root->data<<" ";
    inorder(root->r);
  
}
int main(){

node *root = new node(1);
    root->l = new node(2);
    root->r = new node(3);
    root->r->r = new node(4);
    root->r->r->r = new node(5);
    faltten(root);
    inorder(root);
    return 0;
}