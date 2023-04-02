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
int path(node *root, int &ans)
{
    if(root==NULL){
        return 0;
    }
    int left = path(root->l, ans);
    int right = path(root->r, ans);
    int maxi = max(max(root->data, root->data + left),max( root->data + right, root->data + left + right));
    ans=max(ans,maxi);
    int singlepath=max(root->data,max(root->data+left,root->data+right));
    return singlepath;
}
int maxpathsum(node *root)
{
    int ans = INT_MIN;
    path(root, ans);
    return ans;
}
int main()
{
    node *root = new node(1);
    root->l = new node(2);
    root->r = new node(3);
    root->l->l = new node(4);
    root->r->r = new node(5);
    cout<<maxpathsum(root);
}