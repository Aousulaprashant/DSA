#include<iostream>
#include<algorithm>
using namespace std;
bool isfesible(int arr[],int m,int n,int k){
    int pos=arr[0],elem=1;
    for(int i=1;i<n;i++){
        if(arr[i]-pos>=m){
            pos=arr[i];
            elem++;
            if(elem==k){
                return true;
            }
        }
    }
    return false;
}
int maxdis(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int res=0;
    int left= 1;
    int right = arr[n - 1];
    
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isfesible(arr,mid,n,k))
        {
            res=max(res,mid);
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    return res;
}
int main(){
    int arr[]={1,2,8,4,9};
    int n=5,k=3;
    cout<<"largest minimum distance:  "<<maxdis(arr,n,k);
    return 0;
}