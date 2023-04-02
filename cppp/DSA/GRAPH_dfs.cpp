#include "bits/stdc++.h"
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
const int N=1e5+2;
bool vis[N];
vector<int>v[N];
void dfs(int node){
    vis[node]=true;
    cout<<node<<" ";
    vector<int>:: iterator it;
    for(it=v[node].begin();it!=v[node].end();it++){
        if(vis[*it]);
        else{
            dfs(*it);
        }
    }

}
int main(){
    int n,m;
    cin>>n>>m;
    rep(i,0,n){
        vis[i]=false;
    }
    int x,y;
    
    rep(i,0,m){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
}