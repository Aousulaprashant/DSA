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
struct info
{
    int min;
    int max;
    int siz;
    int ans;
    bool isBST;
};
info largestbst(node *root)
{
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, 0, 0, true};
    }
    if (root->l == NULL && root->r == NULL)
    {
        return {root->data, root->data, 1, 1, true};
    }
    info left = largestbst(root->l);
    info rigth = largestbst(root->r);
    info curr;
    curr.siz = (left.siz + rigth.siz + 1);
    if (left.isBST && rigth.isBST && rigth.min  <root->data && left.max> root->data ){
        curr.max=max(left.max,max(rigth.max,root->data));
        curr.min=min(rigth.min,min(root->data,left.min));
        curr.isBST=true;
        curr.ans=curr.siz;
        return curr;
    }else{
    curr.ans=max(left.ans,rigth.ans);
    curr.isBST=false;
    return curr;
    }
}
int main(){
    node * root=new node(5);
    root->l=new node(2);
    root->r=new node(12);
    root->l->l=new node(1);
    root->l->r=new node(3);
    cout<<largestbst(root).ans;
    return 0;
    
}
