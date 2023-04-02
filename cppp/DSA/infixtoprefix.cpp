#include<iostream>
using namespace std;
//(a-b/c)*(a/k-l)
#include<stack>
int pre(char c)
{
    if (c == '^')
    {
        return 3;
    }
    
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else{
        return -1;
    }
    return 0;
}
string reverse(string s){
    
    stack<char>st;
    string res;
    for(int i=0;i<=s.length();i++){
        st.push(s[i]);
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    st.pop();
     for(int i=0;i<=res.length();i++){
        if(res[i]=='('){
            res[i]=')';
        }
        else if(res[i]==')'){
            res[i]='(';
        }
     }
    return res;
}
string inf2pre(string s){
    stack<char>st;
    string res;
    for (int i = 0; i <s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            res += s[i];
        }
        else if (s[i]== '(')
        {
            st.push(s[i]);
        }
        else if (s[i]== ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && pre(st.top()) > pre(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
      
    }
     while(!st.empty())
      {
          res += st.top();
          st.pop();
      }
    res=reverse(res);

    return res;
}

int main(){

    string str="(a-b/c)*(a/k-l)";
    string restr=reverse(str);
    
    cout<<inf2pre(restr);

}