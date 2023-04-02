#include "bits/stdc++.h"
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int main()
{
        int count = 0;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    vector<int> indeg(n,0);
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        indeg[y]++;
    }
    queue<int> q;
    rep(i, 0, n)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
         count++;
        int x = q.front();
        q.pop();
 
        cout << x << "  ";
        for (auto s : v[x])
        {
            indeg[s]--;
            if (indeg[s] == 0)
            {
                q.push(s);
            }
        }
    }
}
