#include "bits/stdc++.h"
using namespace std;
struct node{
    int data;
    struct node*l;
    struct node *r;
    node(int x){
        this->data=x;
        l=NULL;
        r=NULL;
    }


};
int calculength(node*n){
    if(n==NULL){
        return 0;
    }
    return max(calculength(n->l),calculength(n->r))+1;
}
int caculatediameter(node * newn){
    if(newn==NULL){
        return 0;
    }
    int lhight=calculength(newn->l);
    int rhight=calculength(newn->r);
    int curr=lhight+rhight+1;

    int d1=caculatediameter(newn->l);
    int d2=caculatediameter(newn->r);
    return max(curr,max(d1,d2));
}


int main(){
    node *root = new node(1);
    root->l = new node(2);
    root->r = new node(3);
    root->l->l = new node(4);
    root->l->r = new node(5);
    root->r->l = new node(6);
    root->r->r = new node(7);  
    cout<<caculatediameter(root);
}
