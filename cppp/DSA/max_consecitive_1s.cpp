#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    int k;
    cin >> k;

    int count = 0, ans = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)

            count++;
        while (count > k)
        {
            if (a[j] == 0)
            {
                count--;
            }
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans;
}