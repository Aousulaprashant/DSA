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
void vectororder(node *root, int hd, map<int, vector<int>> &mp)
{
    if (root == NULL)
    {
        return;
    }
    mp[hd].push_back(root->data);
    vectororder(root->l, hd - 1, mp);
    vectororder(root->r, hd + 1, mp);
   
}
signed main()
{
    /*
        10
       /   \
      7     4
    /  \    / \
    3   11  14 6
    
    */

    node *root = new node(10);
    root->l = new node(7);
    root->r = new node(4);
    root->l->l = new node(3);
    root->r->r = new node(6);
    root->r->l = new node(14);
    root->l->r = new node(11);
    map<int, vector<int>> mp;
    int HD = 0;
    vectororder(root, HD, mp);
    map<int,vector<int>> :: iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        for(int i=0;i<(it->second).size();i++){
            cout<<(it->second)[i]<<" ";
        }
        cout<<"\n";
    }

    cout << "\n";
    return 0;
}