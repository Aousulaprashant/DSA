#include "bits/stdc++.h"
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define f first
#define s second
const int N = 1e5 + 2;
bool vis[N];
vector<int> adj[N];
int main()
{
    rep(i, 0, N)
    {
        vis[i] = false;
    }
    int n, m;
    cin >> n >> m;

    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    cout<<"the bfs is:"<<endl;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << endl;
        vector<int>::iterator it;
        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (!vis[*it])
            {
                vis[*it] = true;
                q.push(*it);
            }
        }
    }
}