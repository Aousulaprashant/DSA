#include <iostream>
#include "bits/stdc++.h"
using namespace std;
struct Node
{

    int data;
struct Node *left;
    struct Node *right;

    Node(int x)
    {
        this->data = x;
        left = NULL;
        right = NULL;
    }
};
int search(int ino[], int s, int e, int curr)
{
    for (int i = s; i < e; i++)
    {
        if (ino[i]==curr)
        {
            return i;
           
        }
    }
}
Node *bulttree(int preor[], int inor[], int start, int end)
{
     if(start>end){
         return NULL;
     }
    static int indx = 0;
    int curr = preor[indx];
    indx++;
    Node *node1 = new Node(curr);
    // if(start==end){
    //     return node1;
    // }
    int pos = search(inor, start, end, curr);
    node1->left = bulttree(preor, inor, start, pos - 1);
    node1->right = bulttree(preor, inor, pos + 1, end);
    return node1;
}
void inorderpr(Node *root)
{
    if(root==NULL){
        return;
    }
    inorderpr(root->left);
    cout << root->data<<" ";
    inorderpr(root->right);
}
int main()
{
    int pro[] = {1,2,4,3,5};
   
    int ino[] = {4,2,1,5,3};
    Node *curr = bulttree(pro, ino, 0, 4);

    inorderpr(curr);
    return 0;
}