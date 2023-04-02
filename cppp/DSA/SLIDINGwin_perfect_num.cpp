#include <iostream>
#include <math.h>
using namespace std;
bool isperfect(int n)
{
    int sum = 1;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == n / i)
            {
                sum +=i;
            }else{
                sum+=i+n/i;
            }
        }
    }
    if(sum==n &&n!=1){
        return true;
    }
    return false;
}
int maxsum(int arr[],int n,int k){
    int res=0;
    if (k > n)
    {
        return -1;
    }
    for(int i=0;i<k;i++){
        res+=arr[i];
    }
    int sum=res;
    for (int j = k; j < n; j++){
        sum+=arr[j]-arr[j-k];
        res=max(sum,res);
    }
    return res;

}

int perfectnumber(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (isperfect(arr[i]))
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 0;
        }
    }
return maxsum(arr,n,k);
}
int main()
{
    int arr[]={28,2,3,6,496,99,8128,24};
    int n=8;
    int k=4;
    cout<<perfectnumber(arr,n,k);
    return 0;
}