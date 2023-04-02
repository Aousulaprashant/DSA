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
void distance_at_k(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
    }
    distance_at_k(root->l, k - 1);
    distance_at_k(root->r, k - 1);
}
int kth_position(node *root, node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if(root==target){
       distance_at_k(root,k);
        return 0; 
    }
    int dl=kth_position(root->l,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }else{
           distance_at_k(root->l,dl-k-2);
        }
        return dl+1;
    }
    int dr=kth_position(root->r,target,k);
   
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }else{
           distance_at_k(root->r,dl-k-2);
        }
        return dr+1;
    }
    return -1;

}
int main()
{
    node *root = new node(1);
    root->l = new node(2);
    root->r = new node(3);
  
    root->l->l=new node(4);
    kth_position(root,root->l,1);
    return 0; 
   


}