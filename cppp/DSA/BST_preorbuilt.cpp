#include "bits/stdc++.h"
using namespace std;
struct node{
    int data;
    node*l;
    node*r;
    node(int x){
        data=x;
        l=NULL; 
        r=NULL;
    }
};
node*contuctree(int pre[],int *index,int key,int min,int max,int n){
    if(*index>=n){
        return NULL;
    }
    node*root=NULL;
    if(key>min && key<max){
        root=new node(key);
        *index=*index+1;
        if(*index<n){
            root->l=contuctree(pre,index,pre[*index],min,key,n);
        }
        if(*index<n){
            root->r=contuctree(pre,index,pre[*index],key,max,n);
        }
        
    }
    return root;
    
}
int preorder(node* root){
        if(root==NULL){
        return 0;
    }
      cout<<root->data<<" ";
    preorder(root->l);
  
    preorder(root->r);
}
int main(){
    int pre[]={10,2,1,13,11};
    int index=0;
    int min=INT_MIN;
    int max=INT_MAX;
    int n=5;
   node *root= contuctree(pre,&index,pre[0],min,max,n);
   preorder(root);

}