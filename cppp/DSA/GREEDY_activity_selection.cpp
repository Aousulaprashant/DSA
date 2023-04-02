#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>input;
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        input.push_back({start,end});
    }
    //1.sort the activities accoring to there ending time;
    sort(input.begin(),input.end(),[&](vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    });
    int ans=1;
    int end=input[0][1];
    for(int i=0;i<n;i++){
        if(end<=input[i][0]){
            ans++;
            end=input[i][0];
        }
    }
    cout<<ans;
}