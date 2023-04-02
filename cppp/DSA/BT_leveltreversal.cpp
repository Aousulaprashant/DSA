#include "bits/stdc++.h"
using namespace std;
class node
{
public:
    int d;
    class node *l;
    class node *r;
    node(int x)
    {
        this->d = x;
        l = NULL;
        r = NULL;
    }
};
node *leveltreversal(node *r)
{
    queue<node *> q;
    q.push(r);
    q.push(NULL);
    while (!q.empty())
    {
        node *t = q.front();
        q.pop();
        if (t != NULL)
        {
            cout<<t->d<<" | ";
            if (t->l)
            {
                
                q.push(t->l);
            }
            if(t->r){
                q.push(t->r);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}
int main()
{
    node *root = new node(1);
    root->l = new node(2);
    root->r = new node(3);
    root->l->l = new node(4);
    root->l->r = new node(5);
    root->r->l = new node(4);
    root->r->r = new node(5);
    leveltreversal(root);
}