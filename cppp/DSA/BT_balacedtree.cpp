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
int higt(node *n){
    if(n==NULL){
        return 0;
    }
    int hl=higt(n->l);
    int h2=higt(n->r);

    return max(hl,h2)+1;
}
bool balanced(node * newn){
    if(newn==NULL){
        return true;
    }
    if(balanced(newn->l)==false){
        return false;
    }
    if(balanced(newn->r)==false){
        return false;
    }
    int lh=higt(newn->l);
    int rl=higt(newn->r);
    if(abs(lh-rl)<=1){
        return true;

    }
    else{
        return false;
    }
}

int main(){
    node * root=new node(1);
    root->l = new node(2);
    root->r = new node(3);
    root->l->l = new node(4);
    root->l->r = new node(5);
    root->r->l = new node(6);
    root->r->r = new node(7); 
     root->r->r->r= new node(72);
     root->r->r->r->r= new node(72);
    if(balanced(root)){
        cout<<"balaced tree";
    }else{
        cout<<"unbalendced tree";
    }
    return 0;
}