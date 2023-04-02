#include "bits/stdc++.h"
using namespace std;
priority_queue<int, vector<int>> hmax;

priority_queue<int, vector<int>, greater<int>> hmin;

void insert(int x)
{
    if (hmax.size() == hmin.size())
    {
        if (hmin.size() == 0)
        {
            hmax.push(x);
            return;
        }
        if ( x<hmax.top() )
        {
            hmax.push(x);
        }
        else
        {
            hmin.push(x);
        }
    }
    else
    {
        if (hmax.size() > hmin.size())
        {
            if (x >= hmax.top())
            {
                hmin.push(x);
            }
            else
            {
                int temp = hmax.top();
                hmax.pop();
                hmax.push(x);
                hmin.push(temp);
            }
        }
        else
        {
            if(x<=hmin.top()){
                hmax.push(x);
            }
            else{
                int temp = hmin.top();
                hmin.pop();
                hmax.push(temp);
                hmin.push(x);
                

            }
            
        }
    }
}
double findmean()
{
    if (hmax.size() == hmin.size())
    {
        return (hmax.top() + hmin.top()) / 2.0;
    }
    else if (hmax.size() > hmin.size())
    {
        return hmax.top();
    }
    else
    {
        return hmin.size();
    }
}
int main()
{
    insert(10);
    cout << findmean();
    cout << endl;
    insert(15);
    cout << findmean();
    cout << endl;
    insert(21);
    cout << findmean();
    cout << endl;
    insert(30);
    cout << findmean();
    cout << endl;
    insert(18);
    cout << findmean();
    cout << endl;
    insert(19);
    cout << findmean();
    return 0;
}