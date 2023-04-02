#include "bits/stdc++.h"
using namespace std;
struct node{
   

    int data;
    struct node*left;
    struct node*right;
    node(int x){
        this->data=x;
        left=NULL;
        right=NULL;
    }

};
int search(int in[],int s,int e,int curr){
    for(int i=s;i<=e;i++){
        if(in[i]==curr){
            return i;
        }       
    }
    return -1;
}
node* bulttree(int post[],int ino[],int start,int end){
    static int indx=4;
    if(start>end){
        return NULL;
    }
    
    int curr=post[indx];
    indx--;
    node* newnode=new node(curr);
    if(start==end){
         return newnode;
    }
    if(start==end){
        return newnode;
    }
    int pos=search(ino,start,end,curr);

    newnode->right=bulttree(post,ino,pos+1,end);
        newnode->left=bulttree(post,ino,start,pos-1);
    return newnode;
}
void inorder(node* n){
    if(n==NULL){
        return;
    }
    inorder(n->left);
    cout<<n->data<<" ";
    inorder(n->right);
}
int main()
{
    int post[] = {4, 2, 5, 3, 1};
    int ino[] = {4, 2, 1, 5, 3};
    node *root=bulttree(post,ino,0,4);
    inorder(root);
return 0;
}