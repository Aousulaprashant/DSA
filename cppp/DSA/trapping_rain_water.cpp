#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int raintrap(vector<int> a)
{
    stack<int> st;
    int water = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            int crr = st.top();
            st.pop();
            if (st.empty())
            {
                break;
            }

            int diff = i - st.top()- 1;
            water += diff * (min(a[st.top()], a[i]) - a[crr]);
        }
        st.push(i);
    }
    return water;
}
int main()
{
    vector<int> a = {3, 1, 2, 4, 0, 1, 3, 2};
    cout << raintrap(a);
}