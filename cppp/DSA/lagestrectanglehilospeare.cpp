#include<iostream>
#include "bits/stdc++.h"
using namespace std;
int lagest_rectangle_area(vector<int>a){
    stack<int>st;
    int ans=0;
    int n=a.size();
    a.push_back(0);
    for(int i=0;i<n;i++){

        while(!st.empty()&& a[st.top()]>a[i]){
            int h=a[st.top()];
            st.pop();
            if(st.empty()){
                ans=max(ans,h*i);
            }
            else{
                int len=i-st.top()-1;
                ans=max(ans,h*len);
            }
        }
        st.push(i);
    }
    return ans;
}
int main(){
    vector<int>a={2,1,5,6,2,3};
    cout<<lagest_rectangle_area(a);
}
