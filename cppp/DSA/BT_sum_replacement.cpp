#include "bits/stdc++.h"
using namespace std;
struct node
{
    int data;
    struct node *l;
    struct node *r;
    node(int x)
    {
        this->data = x;
        l = NULL;
        r = NULL;
    }
};
int sumreplacement(node *newn){
    if(newn==NULL){
        return 0;
    }

    sumreplacement(newn->l);
    sumreplacement(newn->r);
    if(newn->l!=NULL){
        newn->data+=newn->l->data;
    }
    if(newn->r!=NULL){
        newn->data+=newn->r->data;
    }

}
void preorder(node * n){
    if(n==NULL){
        return;
    }
    cout<<n->data<<" ";
    preorder(n->l);
    preorder(n->r);
}
int main()
{
    node * root=new node(1);
     root->l = new node(2);
    root->r = new node(3);
    root->l->l = new node(4);
    root->l->r = new node(5);
    root->r->l = new node(6);
    root->r->r = new node(7); 
    sumreplacement(root);
    preorder(root);

}