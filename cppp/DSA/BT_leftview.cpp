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
void leftview(node * newn){
    if(newn==NULL){
        return;
    }
    queue<node*>q;
    q.push(newn);
    while(!q.empty()){
        int n=q.size();
        for(int i=1;i<=n;i++){
            node* curr=q.front();
            q.pop();
            if(i==1){
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
    node *root = new node(5);
    root->l = new node(3);
    root->r = new node(6);
    root->l->l = new node(2);
    root->l->r = new node(4);
 
    leftview(root);
    return 0;


}