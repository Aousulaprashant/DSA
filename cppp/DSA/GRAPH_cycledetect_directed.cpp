#include "bits/stdc++.h"
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
bool iscycle(int s, vector<bool> &vis, vector<int> &st, vector<vector<int>> &adj)
{
    st[s] = true;
    if (!vis[s])
    {
        vis[s] = true;
        for (auto i : adj[s])
        {
            if (!vis[i] and iscycle(i, vis, st, adj))
            {
                return true;
            }
            if (st[i])
            {
                return true;
            }
        }
    }
    st[s]=false;
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<int> stack(n, 0);
    vector<bool> vis(n, false);
    bool cyc = false;
    rep(i, 0, n)
    {
        if (!vis[i] and iscycle(i, vis, stack, adj))
        {
            cyc = true;
        }
    }
    if (cyc)
    {
        cout << "cycle spotted!!!\n";
    }
    else
    {
        cout << "cycle not spotted!!\n";
    }
}