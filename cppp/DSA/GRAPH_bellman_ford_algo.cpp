#include "bits/stdc++.h"
using namespace std;
const int inf=1e7;
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>>edge;
    vector<int>dis(n,inf);
    for(int i=0;i<m;i++){
        int x,y,w;cin>>x>>y>>w;
        edge.push_back({x,y,w});
    }
    int sc;cin>>sc;
    dis[sc]=0;
    bool change =false;
  for(int it=0;it<n-1;it++){
    for(auto e:edge){
        int u=e[0];
        int v=e[1];
        int w=e[2];
        if(dis[v]>dis[u]+w){
            change=false;
        }
        dis[v]=min(dis[v],dis[u]+w);
    }
  }
  for(auto i:dis){
    cout<<i<<" ";
  }cout<<"\n";
  if(change){
    cout<<"detected cycle!!\n";
  }else{
    cout<<"nop no cycle !!";
  }

}