#include "bits/stdc++.h"
using namespace std;
struct node
{
public:
    int d;
    struct node *l;
    struct node *r;
    node(int x)
    {
        this->d = x;
        l = NULL;
        r = NULL;
    }
};
int totalnode(node * node1){
    if(node1==NULL){
        return 0;
    }
    return totalnode(node1->l)+ totalnode(node1->r)+1;
}
int sum(node * node1){
    if(node1==NULL){
        return 0;
    }
    return sum(node1->l)+ sum(node1->r)+node1->d;
}
int main()
{
    node *root = new node(1);
    root->l = new node(2);
    root->r = new node(3);
    root->l->l = new node(4);
    root->l->r = new node(5);
    root->r->l = new node(6);
    root->r->r = new node(7);
    cout<<totalnode(root)<<"\n";
    cout<<sum(root);
    
}