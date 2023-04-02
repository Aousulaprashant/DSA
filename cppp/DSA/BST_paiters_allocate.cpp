#include "bits/stdc++.h"
using namespace std;
int findpainter(int ar[],int no_bords,int limit){
    int sum=0;
    int painters=1;
    for(int i=0;i<no_bords;i++){
        sum+=ar[i];
        if(sum>limit){
            sum=ar[i];
            painters++;
        }

    }
    return painters;


}
int paiters(int arr[],int n,int m){
    int total_length=0,k=0;
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
        total_length+=arr[i];
    }
    int low=k,high=total_length;
    while(low<high){
        int mid=(low+high)/2;
        int painter=findpainter(arr,n,mid);
        if(painter<=m){
            high=mid;
        }else{
            low =mid+1;
        }
    }
    return low;
}
int main(){
    int arr[]={10,20,30,40};
    int n=4,m=2;
    cout<<paiters(arr,n,m);
    return 0;
}