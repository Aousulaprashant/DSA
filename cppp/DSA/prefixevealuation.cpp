#include<iostream>
using namespace std;
#include<stack>
#include<math.h>
int prefix(string s){
    stack<int>stack1;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>='0' &&s[i]<='9'){
            stack1.push(s[i]-'0');

        }else{
            int op1=stack1.top();
            stack1.pop();
             int op2=stack1.top();
            stack1.pop();
            switch(s[i]){
                case '-':stack1.push(op1-op2);
                break;
                 case '+':stack1.push(op1+op2);
                break;
                 case '*':stack1.push(op1*op2);
                break;
                 case '/':stack1.push(op1/op2);
                break;

            }
        }
    }
 return stack1.top();
}
int main(){
    cout<<prefix("-+7*45+20")<<endl;
    return 0;
}