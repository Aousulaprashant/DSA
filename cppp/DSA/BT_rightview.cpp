#include "bits/stdc++.h"
#include<iostream>
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
void rightview(node * newn){
    if(newn==NULL){
        return;
    }
    queue<node*>q;
    q.push(newn);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            node *curr=q.front();
            q.pop();
            if(i==n-1){
                cout<<curr->data<<" ";

            }
            if(curr->l!=NULL){
                q.push(curr->l);

            }
            if(curr->r!=NULL){
                q.push(curr->r);

            }

        }

    }
}
int main(){
    node *root = new node(1);
    root->l = new node(2);
    root->r = new node(3);
    root->l->l = new node(4);
    root->l->r = new node(5);
    root->r->l = new node(6);
    rightview(root);

}
