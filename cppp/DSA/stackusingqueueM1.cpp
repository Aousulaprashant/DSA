#include <iostream>
using namespace std;
#include <queue>
class stack
{
    queue<int> q1;
    queue<int> q2;

public:
    int push(int x)
    {
        if (q1.empty() and q2.empty())
        {
            q1.push(x);
        }
        else
        {
            q2.push(x);
            while (!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1 = q2;
            while (!q2.empty())
            {
                q2.pop();
            }
        }
    }
    int pop(){

        q1.pop();

    }
    int front(){
        return q1.front();
    }
};
int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    cout<<s.front();
    cout<<"\n";
    s.pop();
     cout<<s.front();


}