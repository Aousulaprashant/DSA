#include "bits/stdc++.h"
using namespace std;
#define rep(i, a, b)        \
    for (i = a; i < b; i++) \
        ;
class data
{
public:
    int val, arrypos, valpos;
    data(int v, int ap, int vp)
    {
        val = v;
        arrypos = ap;
        valpos = vp;
    }
};
struct mycomparator
{
    bool operator()(data &d1, data &d2)
    {
        return d1.val > d2.val;
    }
};
vector<int> solution(vector<vector<int>> arr, int k)
{
    vector<int> ans;
    priority_queue<data, vector<data>, mycomparator> minheap; // priority queue
    for (int i = 0; i < k; i++)
    {
        data d1(arr[i][0], i, 0);
        minheap.push(d1);
    }
    while (!minheap.empty())
    {
        data curr = minheap.top();
        minheap.pop();
        ans.push_back(curr.val);
        int ar_pos = curr.arrypos, val_pos = curr.valpos;

        if (val_pos + 1 < arr[ar_pos].size())
        {
            data d2(arr[ar_pos][val_pos + 1], ar_pos, val_pos + 1);
            minheap.push(d2);
        }
    }
    cout<<"the sorted arry is:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
signed main()
{
     cout<<"enter the no. of arry:\n";
    int k;
    cin >> k;

    vector<vector<int>> arr1(k);
    for (int i = 0; i <k; i++)
    {
        int size;
        cout<<"enter the size of arry:\n";
        cin >> size;
        arr1[i] = vector<int>(size);
         cout<<"enter the elements of arry:\n";
        for (int j = 0; j <size; j++)
        {
            cin >> arr1[i][j];
        }
    }


    solution(arr1, k);
}