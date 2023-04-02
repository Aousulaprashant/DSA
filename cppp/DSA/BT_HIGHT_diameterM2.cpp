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
int caldiameter(node*n,int * higt){
    if(n==NULL){
        *higt=0;
        return 0;
    }
    int lh=0;
    int rh=0;
    int d1=caldiameter(n->l,&lh);
    int d2=caldiameter(n->r,&rh);
    int currdiameter=lh+rh+1;
    *higt =max(lh,rh)+1;
    return max(currdiameter,max(d1,d2));




}

int main(){
    node *root = new node(1);
    root->l = new node(2);
    root->r = new node(3);
    root->l->l = new node(4);
    root->l->r = new node(5);
    root->r->l = new node(6);
    root->r->r = new node(7); 
    int higt=0; 
    cout<<caldiameter(root,&higt);
}
