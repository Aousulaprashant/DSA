#include "bits/stdc++.h"
using namespace std;
bool ispossible(int arr[],int n,int m, int min){
    int studendrequired=1,sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>min){
            return false;
        }
        if(sum+arr[i]>min){
            studendrequired++;
            sum=arr[i];
            if(studendrequired>m){
                return false;
            }
        }
        else{
            sum+=arr[i];
        }
    }
    return true;
}
int allowocate(int ar[],int n,int m){
    int sum=0;
    if(n<m){
        return -1;
    }

    for(int i=0;i<n;i++){
        sum=sum+ar[i];
    }
    int start=0,end=sum;
    int ans=INT_MAX;
    while(start<=end){
        int mid=(start+end)/2;
        if(ispossible(ar,n,m,mid)){
            ans=min(ans,mid);
            end=mid-1;
        }
        else{
            start=mid+1;
        }

    }
    return ans;

}
int main(){
    int arr[]={12,34,67,90};
    int n=4;
    int m=2;
    cout<<allowocate(arr,n,m);
    return 0;
}