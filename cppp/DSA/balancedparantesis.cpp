#include<iostream>
using namespace std;
#include<stack>
bool balancepar(string s){
    stack<char>st;
    bool ans=true;
    for(int i=0;i<=s.length();i++){
        if(s[i]=='{' or s[i]=='[' or s[i]=='(' ){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.top()=='('){
                st.pop();
            }
            else{
                ans=false;
            }
        }
        else if(s[i]==']'){
            if(st.top()=='['){
                st.pop();
            }
            else{
                ans=false;
            }
        }
        else if(s[i]=='}'){
            if(st.top()=='{'){
                st.pop();
            }
            else{
                ans=false;
            }
        }
    }
    return ans;
}
int main(){
    string st="{[()}]";
   cout<< balancepar(st);
}
