#include "bits/stdc++.h"
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
const int N=1e5+2;
bool iscycle(int s,vector<vector<int>>& a,vector<bool>&vis,int parant){
    vis[s]=true;
    for(auto i:a[s]){
        if(i!=parant){
            if(vis[i]){
                return true;
            }else if(!vis[i] and iscycle(i,a,vis,s)){
                return true;
            }
        }
    }
    return false;

}
int main(){
    int n,m;cin>>n>>m;
    /*rep(i,0,n){
        vis[i]=false;
    }*/
    vector<vector<int>>a(n);
    vector<bool> vis(n,false);

    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    bool cycle=false;
    rep(i,0,n){
        if(!vis[i] && iscycle(i,a,vis,-1)){
            cycle=true;
        }
       
    }
     if(cycle)
     {
         cout<<"cycle spotted!!!\n";
     }
      else{
            cout<<"cycle not spotted!!\n";
        }
return 0;
}