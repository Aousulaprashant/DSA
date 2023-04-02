/*PRIMS ALGORITHM
   used to find the MST(minimum spanning TREE) as in previous program
   its kind of greedy algorithm
*/
#include "bits/stdc++.h"
using namespace std;
int cost=0;
int n,m;
const int N=1e5+3;
const int inf=1e9;
vector<vector<int>>g[N];
vector<int>dist(N);
vector<int>parnt(N);
vector<bool>vis(N);
void prims(int start){
   for(int i=0;i<n;i++){
      dist[i]=inf;
   }
   dist[start]=0;
   set<vector<int>>s;
   s.insert({0,start});
   while(!s.empty()){
      auto x=*(s.begin());
      s.erase(x);
      vis[x[1]]=true;
      int u=x[1];
      int v=parnt[x[1]];
      int w=x[0];
      cout<<u<<" "<<v<< " "<<w<<endl;
      cost+=w;
      for(auto it:g[x[1]]){
      if(vis[it[0]]){
         continue;
      }
      if(dist[it[0]]>it[1]){
         s.erase({dist[it[0]],it[0]});
         dist[it[0]]=it[1];
         s.insert({dist[it[0]],it[0]});
         parnt[it[0]]=x[1];
      }
      }
   }

}
int main(){
   cin>>n>>m;
   for(int i=0;i<m;i++){
      int u,v,w;cin>>u>>v>>w;
      g[u].push_back({v,w});
      g[v].push_back({u,w});
   }
   prims(0);
   cout<<cost;
}