#include "bits/stdc++.h"
using namespace std;
int n, m;
vector<vector<int>> ad;
vector<bool> vis;
int components(int i)
{
    if (vis[i])
    {
        return 0;
    }
    vis[i] = true;
    int ans = 1;
    for (auto s : ad[i])
    {
        if (!vis[s])
        {
            ans += components(s);
            vis[s] = true;
        }
    }
    return ans;
}
int main()
{

    cin >> n >> m;
    ad = vector<vector<int>>(n);
    vis = vector<bool>(n);
    for (int i = 0; i < m; i++)
    {
        int x;
        int y;
        cin >> x >> y;
        ad[x].push_back(y);
        ad[y].push_back(x);
    }
    vector<int> comp;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            comp.push_back(components(i));
        }
    }
    long long ans=0;
    for (auto x : comp)
    {
        //cout << x << " ";
        ans+=x*(n-x);

    }
    cout<<(ans/2);
}