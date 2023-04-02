#include "bits/stdc++.h"
using namespace std;
#define re(i,a,b) for(int i=a;i<b;i++)
int main(){
    int k;cin>>k;
    int arr[k];
    re(i,0,k){
        cin>>arr[i];
    }
    map<int,int>mp;
    re(i,0,k){
        mp[arr[i]]++;
    }
    map<int,int> :: iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<"->"<<it->second<<endl;
    }
}
