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
void cal(node *root, node **first, node **mid, node **last, node **prev)
{
    if(root==NULL){
        return;
    }
    cal(root->l, first, mid, last, prev);

    if(*prev &&root->data <(*prev)->data){
        if(!*first){
            *first=*prev;
            *mid=root;

        }
        else{
            *last=root;
        }
    }
    *prev=root;
    cal(root->r, first, mid, last, prev);

}
void swap(int *a,int *b){
    int temp;
   temp=*a;
   *a=*b;
   *b=temp;
}
node *restore(node *root)
{
    node *first;
    node *mid;
    node *last ;
    node *prev ;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    cal(root, &first, &mid, &last, &prev);
    if (first && last)
    {
        swap(&(first->data), &(last->data));
    }
    else if (first && mid)
    {
        swap(&(first->data), &(mid->data));
    }
}
void inorder(node * root){
    if(root==NULL){
        return;

    }
    inorder(root->l);
    cout<<root->data<<" ";
    inorder(root->r);
}
int main(){
    node *root=new node(6);
    root->l=new node(9);
    root->r=new node(3);
    root->l->l=new node(1);
    root->l->r=new node(4);
    root->r->r=new node(13);
    inorder(root);cout<<endl;
    restore(root);cout<<endl;
    inorder(root);
    return 0;
}