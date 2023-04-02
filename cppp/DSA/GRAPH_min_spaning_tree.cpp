/*minmum spanning tree(MST)

definetion of spaining tree:-
      given an undirected and connected graph G(V,E) ;a spaning tree
of graph G is a tree that spans G(that is,it includes every vertex of G)
and is subgraph of G(every edge in the tree belongs to G).

  COST of the spanning tree:-
      SUM of the weights of the edges present in the graph.

    MST:
    ST which has min cost.

    WE FIND MST by Kruskal's algoritham.
*/
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 2;
vector<int> parant(N);
vector<int> sz(N);
void makese(int i)
{
    parant[i] = i;
    sz[i] = 1;
}
int findset(int v)
{
    if (v == parant[v])
    {
        return v;
    }
    return parant[v] = findset(parant[v]);
}
void union4(int u, int v)
{
    u = findset(u);
    v = findset(v);
    if (u != v)
    {
        if (sz[u] < sz[v])
        {
            swap(u, v);
        }
        parant[v] = u;
        sz[u] += sz[v];
    }
}
int main()
{
    for (int i = 0; i < N; i++)
    {
        makese(i);
    }
    int n, m;
    cin >> n>>m;
    vector<vector<int>> endg;
    for (int i = 0; i < m; i++)
    {
        int w, x, y;
        cin >> x >> y>>w;
        endg.push_back({w, x, y});
    }
    sort(endg.begin(), endg.end());
    int cost = 0;
    for (auto i : endg)
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = findset(u);
        int y = findset(v);
        if (x == y)
        {
            continue;
        }
        else
        {
            cout << u << " " << v<<endl;
            cost += w;
            union4(u, v);
        }
    }
    cout<<"\n"<<"MST:\t"<<cost;
}
