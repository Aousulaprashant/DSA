#include "bits/stdc++.h"
using namespace std;
bool subarryof_0(int arr[],int &sum){
      unordered_set<int>s;
    for(int i=0;i<4;i++){
        sum+=arr[i];
        if(sum==0){
            return true;
        }
        if(s.find(sum)!=s.end()){
            return true;
        }
        s.insert(sum);
    }
    return false;
}
int main(){
    int arr[]={1,1,-1,1};

    int sum=0;
    
    cout<<subarryof_0(arr,sum);
} // namespace 

