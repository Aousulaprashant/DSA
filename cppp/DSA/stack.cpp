#include<iostream>
using namespace std;
#define n 5
class stack{
    int *arr;
    int top;
    public:
    stack(){
        arr=new int[n];
        top=-1;
    }
    void push(int x){
        top++;
        arr[top]=x;
       
    }
    void pop(){
        top--;
    }
    void display(){
          cout<<arr[top]<<endl;
    }

};
int main(){
    stack elem;
    elem.push(2);
    elem.push(5);
    elem.push(6);
    elem.push(4);
    elem.push(9);
    elem.push(1);
    elem.display();
    elem.pop();
    elem.display();
   
}