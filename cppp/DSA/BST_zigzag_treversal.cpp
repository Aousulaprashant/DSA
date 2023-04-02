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
void zigzagtreversal(node *root)
{
    if(root==NULL){
        return;
    }
    stack<node *> curr;
    stack<node *> next;
    bool lefttoright = true;
    curr.push(root);
    while (!curr.empty())
    {
        node *temp = curr.top();
        curr.pop();
        if (temp)
        {
            cout << temp->data << " ";
            if (lefttoright)
            {
                if (temp->l)
                {
                    next.push(temp->l);
                }
                if (temp->r)
                {
                    next.push(temp->r);
                }
            }
            else
            {
                if (temp->r)
                {
                    next.push(temp->r);
                }
                if (temp->l)
                {
                    next.push(temp->l);
                }
            }
        }
        if (curr.empty())
        {
            lefttoright = !lefttoright;
            swap(curr, next);
        }
    }
}
int main()
{
    node *root = new node(12);
    root->l = new node(9);
    root->r = new node(15);
    root->l->l = new node(5);
    root->r->r = new node(10);
    zigzagtreversal(root);
    return 0;
}
