#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    vector<int>ans;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "enter the value :\t";
    int v;
    cin >> v;
   sort(arr.begin(),arr.end());
   for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int count=0;
   
    for (int i = n-1; i >=0; i--)
    {
       while(v>=arr[i]){

           v=v-arr[i];
           ans.push_back(arr[i]);
           count++;

       }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i]<< " ";
    }
    cout<<endl<<count;


}