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
//METHOD II
bool getpath(node *root, int n, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }
    path.push_back(root->data);

    if (root->data == n)
    {
        return true;
    }
    if (getpath(root->l, n, path) || getpath(root->r, n, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}
int lowest_common_ansistor(node *root, int n1, int n2)
{
    vector<int> path1, path2;
    if (!getpath(root, n1, path1) || !getpath(root, n2, path2))
    {
        return -1;
    }
    int pc;
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if (path1[pc] != path2[pc])
        {
            break;
        }
    }
    return path1[pc - 1];
}
//METHOD II
node *lca2(node*root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1||root->data==n2){
        return root;
    }
    node *llca=lca2(root->l,n1,n2);
    node *rlca=lca2(root->r,n1,n2);
    if(llca&&rlca){
        return root;
    }
    if(llca!=NULL){
        return llca;
    }
    return rlca;

}
int main()
{
    node *root = new node(1);
    root->l = new node(2);
    root->r = new node(3);
    root->l->l = new node(4);
    root->l->r = new node(5);
   cout<< lowest_common_ansistor(root, 4, 5)<<"\n";
   //method 2
   node* res=lca2(root,4,5);
   cout<<res->data;
}