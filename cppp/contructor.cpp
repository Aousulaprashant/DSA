#include <iostream>

#include<bits/stdc++.h>
using namespace std;
class student
{
private:
    string name;

public:
    int marks;
    int result;
    student(string s, int m, int r)
    {
        name = s;
        marks = m;
        result = r;
        cout << "parametarized conctructor\n ";
        // parametarized conctructor
    }
    student()
    {
        cout << "defult contructor\n";
    }
    student(student &a)
    {
        name = a.name;
        marks = a.marks;
        result = a.result;
        cout << "copy constructor!!\n";
    }
    bool operator==(student &a)
    {
        if (name == a.name && marks == a.marks && result == a.result)
        {
            return true;
        }
    }
    ~student()
    {
        cout << "\ndistructor took place\n";
    }
    /*void printinfo(){
        cout<<endl<<name<<endl;
        cout<<endl<<marks;
    }*/
};
int main()
{
    student a("prashanth", 100, 5);
    student b;
    student c = a;
    if (c == a)
    {
        cout << "same ";
    }
}


