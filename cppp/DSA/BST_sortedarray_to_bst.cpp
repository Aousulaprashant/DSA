#include "bits/stdc++.h"
using namespace std;
struct node
{
    int data;
    node *l;
    node *r;
    node(int x)
    {
        data = x;
        l = NULL;
        r = NULL;
    }
};
node *sortedarr(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    node*newn=new node(arr[mid]);

   
        newn->l=sortedarr(arr,start,mid-1);

    
    newn->r=sortedarr(arr,mid+1,end);
    return newn;
}
int preorder(node *root){
    if(root==NULL){
        return 0;
    }
    cout<<root->data<<" ";
    preorder(root->l);
    preorder(root->r);
}
int main(){
    int sortarr[]={1,2,3,4,5};
    node * root=sortedarr(sortarr,0,4);
    preorder(root);
    return 0;

}