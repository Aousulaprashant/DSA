#include "bits/stdc++.h"
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define dis_stop first
#define lit_stop second
int main(){
    int n;
    cin>>n;

    vector<pii>a(n);
    rep(i,0,n){
        cin>>a[i].dis_stop>>a[i].lit_stop;
    }
    int dis,pet;cin>>dis>>pet;
    rep(i,0,n){
        a[i].dis_stop=dis-a[i].dis_stop;

    }
    sort(a.begin(),a.end());
    int curr=pet;
    bool flag=0;
    int ans=0;
    priority_queue<int,vector<int>>pq;
    rep(i,0,n){
        while(curr>=dis){
           
            break;
        }
        while(curr<a[i].dis_stop)
        {
            if(pq.empty())
            {
                 flag=1;
                 break;
            }
            curr+=pq.top();
            pq.pop();
            ans++;   
        }

        if(flag){
            break;
        }
        pq.push(a[i].lit_stop);

    }
    while(!pq.empty()&& curr<dis){
        curr+=pq.top();
            pq.pop();
            ans++;  
    }
    if(curr<dis){
        cout<<"-1";
    }
    cout<<ans;
    return 0;
}