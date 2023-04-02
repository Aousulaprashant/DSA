#include <iostream>
using namespace std;
int findpeek(int arr[],int first,int last){
    int mid=(first+last)/2;
    
    if(mid==0||(arr[mid-1]<=arr[mid])&&(arr[mid+1]<=arr[mid])){
        return mid;
    }
    else if (mid>0 && arr[mid-1]>arr[mid])
    {
        findpeek(arr,first,mid-1);

        /* code */
    }else if(mid>0 && arr[mid+1]>arr[mid]){
         findpeek(arr,first,mid+1);

    }
    
}
int main(){
int arr[]={30,40,50,10,20};
cout<<findpeek(arr,0,4);       

}