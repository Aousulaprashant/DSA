#include "bits/stdc++.h"
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{

    int n;
    cin >> n;
    vector<int> input(n);
    rep(i, 0, n)
    {
        cin >> input[i];
    }
    priority_queue<int, vector<int>, greater<int>> minheap;
    rep(i, 0, n)
    {
        minheap.push(input[i]);
    }
    int ans = 0;
    while (minheap.size() > 1)
    {
        int a = minheap.top();
        minheap.pop();
        int b = minheap.top();
        minheap.pop();
        ans = ans + (a + b);
        minheap.push(a + b);
    }
    cout << ans;
}