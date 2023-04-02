#include "bits/stdc++.h"
#include <iostream>
#include <math.h>
using namespace std;
vector<int> span1(vector<int> prices)
{

    stack<pair<int, int>> s;
    vector<int> ans;
    for (auto i : prices)
    {
        int days = 1;
        while (!s.empty() and s.top().first <=i)
        {
            days+=s.top().second;
            s.pop();

        }
        s.push({i,days});
        ans.push_back(days);
    }
    return ans;
}
int main()
{
    vector<int> a = {100, 80, 60, 70, 60, 70, 85};
    vector<int> ans = span1(a);
    for(auto i:ans){
        cout<<i<<" ";
    }
    
}