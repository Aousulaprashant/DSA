#include "bits/stdc++.h"
using namespace std;
const int N=1e5+2;
vector<int>parant(N);
vector<int>sz(N);
void makese(int i){
    parant[i]=i;
    sz[i]=1;
}
int findset(int v){
    if(v==parant[v]){
        return v;
    }
    return parant[v]=findset(parant[v]);
}
void union4(int u,int v){
    u=findset(u);
    v=findset(v);
    if(u!=v){
        if(sz[u]<sz[v]){
            swap(u,v);
        }
        parant[v]=u;
        sz[u]+=sz[v];
    }
}

int main(){
    for(int i=0;i<N;i++){
        makese(i);
    }
    int n,m;cin>>n>>m;
    vector<vector<int>>endg;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        endg.push_back({x,y});
    }
    bool cycle=false;
    for(auto i:endg){
        int u =i[0];
        int v =i[1];
        int x=findset(u);
        int y=findset(v);
        if(x==y){
            cycle =true;

        }else{
            union4(u,v);
        }
    }
    if(cycle){
        cout<<"cycle is present!!";
    }else{
        cout<<"nop!!! cycle is npt present!!";
    }
}