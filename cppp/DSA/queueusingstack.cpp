#include <iostream>
using namespace std;
#include <stack>
class queue1
{
public:
    stack<int> st1;
    stack<int> st2;
    int push(int x)
    {
        st1.push(x);
    }
    int pop()
    {
        if(st1.empty() and st2.empty()){
            cout<<"queue is empty"<<endl;
            return -1;
            
        }
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());   
                st1.pop();
            }
           
        }
         int stq=st2.top();
            st2.pop();
            return stq;
    }
};

int main()
{
    queue1 q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<< q.pop() << endl;
     cout<< q.pop() << endl;
      cout<< q.pop() << endl;
    
}