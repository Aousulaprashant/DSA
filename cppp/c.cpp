#include <iostream>
using namespace std;
class student
{
    string finalresult;
public:
    string name;
    int marks;
    string grade;
    void printf()
    {
        cout << "next studend detailes:" << endl;
        cout << "name:\n"
             << name << endl;
        cout << "marks:\n"
             << marks << endl;
        cout << "grade:\n"
             << grade << endl;
    }
};
int main()
{
    int n;
    cout << "enter the no.of students:\n";
    cin >> n;

    student arr[n];
    for (int i = 0; i < n; i++)
    {
    
        cout << "enter the name:\n";
        cin >> arr[i].name;
        cout << "enter the marks:\n";
        cin >> arr[i].marks;
        cout << "enter the grade:\n";
        cin >> arr[i].grade;
        cout << "enter P/F:\n";
    }
    cout << "first student detail:" << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i].printf();
    }
}