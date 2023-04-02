#include "bits/stdc++.h"
using namespace std;
#define pir pair<int,int>
#define re(i,a,b) for(int i=a;i<b;i++)
vector<int> topfreq(vector<int>& arr,int n){
    unordered_map<int,int>mp;
    re(i,0,n){
        mp[arr[i]]++;
    }
    priority_queue<pir,vector<pir>,greater<pir>>pq;
    for(auto x: mp){
        pq.push(make_pair(x.second,x.first));
        if(pq.size()>n){
            pq.pop();
        }
    }
    vector<int>ans;
    while(!pq.empty()){
       pair<int,int> temp=pq.top();
       pq.pop();
       ans.push_back(temp.second);
    }
    re(i,0,ans.size()){
        cout<<ans[i]<<" ";
    }
}
int main(){
    vector<int>arr={1,1,1,2,2,3};

    int k=2;

   topfreq(arr,k);
}