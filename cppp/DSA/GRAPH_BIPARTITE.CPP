#include "bits/stdc++.h"
using namespace std;
vector<vector<int>> ad;
vector<int> col;
bool bipart;
vector<bool> vis;
void colour(int i, int curr)
{
    if (col[i] != -1 && col[i] != curr)
    {
        bipart = false;
        return;
    }
    col[i] = curr;
    if (vis[i])
    {
        return;
    }
    else
    {
        vis[i] = true;
        for (auto x : ad[i])
        {
            colour(x, curr xor 1);
        }
    }
}
int main()
{
    int n, m;
    bipart = true;
    cin >> n >> m;
    ad = vector<vector<int>>(n);
    vis = vector<bool>(n, false);
    col = vector<int>(n, -1);
    for (int i = 0; i < m; i++)
    {
        int x;
        int y;
        cin >> x >> y;
        ad[x].push_back(y);
        ad[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            colour(i, 0);
        }
    }
    if(bipart==true)
    {
        cout << "its biparite";
    }
    else
    {
        cout << "nop!!";
    }
}