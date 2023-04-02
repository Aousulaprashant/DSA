#include<bits/stdc++.h>
using namespace std;
class stack1{
    queue<int>que1;
    queue<int>que2;
    public:
    int push(int x){
        que1.push(x);

    }
    int pop(){
        if(que1.empty()){
            cout<<"stack is empty"<<endl;
        }
        while(que1.size()!=1){
            que2.push(que1.front());
            que1.pop();
        }
        que1.pop();
        que1=que2;
    }
    int top(){
        if(que1.empty()){
            cout<<"stack is empty"<<endl;
        }
         while(que1.size()!=1){
            que2.push(que1.front());
            que1.pop();
        }
        int ans=que1.front();
        que2.push(que1.front());
        que1=que2;
        return ans;
    }
};
int main(){
    stack1 st;
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(7);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top();

}