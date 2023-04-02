#include "bits/stdc++.h"
using namespace std;
const int N=1e5+2;
const int inf=1e7;
int main(){
    int n,m;
    
    cin>>n>>m;
    vector<int>dis(n+1,inf);
    vector<vector<pair<int,int>>>gr(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        gr[u].push_back({v,w});
        gr[v].push_back({u,w});
    }
    int sorc;cin>>sorc;
    dis[sorc]=0;
    set<pair<int,int>> set;
    set.insert({0,sorc});
    while(!set.empty()){
        auto x=*(set.begin());
        set.erase(x);
        for(auto i: gr[x.second]){
            if(dis[i.first]>dis[x.second]+i.second){
                set.erase({dis[i.first],i.first});
                dis[i.first]=dis[x.second]+i.second;
                set.insert({dis[i.first],i.first});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
}