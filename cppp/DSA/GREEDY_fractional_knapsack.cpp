#include "bits/stdc++.h"
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define f first
#define s second
bool compire(pii p1, pii p2)
{
    double v1 = (double)p1.f / p1.s;
    double v2 = (double)p2.f / p2.s;
    return v1 > v2;
}
int main()
{
    int n;
    cin >> n;
    vector<pii>input(n);

    rep(i, 0, n)
    {
        cin >> input[i].f >> input[i].s;
    }
    sort(input.begin(), input.end(), compire);
    int ans=0;
    int w;
    cin>>w;
    rep(i,0,n){
        if(input[i].s<=w){
            ans+=input[i].f;
            w-=input[i].s;
            continue;
        }
        double vw=(double) input[i].f/input[i].s;
        ans+=vw*w;
        w=0;
           break;
        

    }
    cout<<ans;
       
}