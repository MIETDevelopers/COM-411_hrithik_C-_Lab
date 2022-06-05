/*To add the details of a student using a parameterized constructor of student class.*/
// Author:HRITHIK KOUL
#include <iostream>
using namespace std;
class student
{
    int rollno;
    string name, section, semester;

public:
    student(){};
    student(int x, string y, string z, string q);
    void display(int);
};
student::student(int x, string y, string z, string q)
{
    rollno = x;
    name = y;
    section = z;
    semester = q;
}
void student::display(int j)
{
    cout << "student " << j + 1 << " rollno is " << rollno << endl;
    cout << "student " << j + 1 << " name is " << name << endl;
    cout << "student " << j + 1 << " section is " << section << endl;
    cout << "student " << j + 1 << " semester is " << semester << endl;
}
int main()
{
    student s1[25];
    int n, r;
    string q, s, j;
    cout << "how many student detail you want to enter";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "enter the rollno of student " << i + 1 << endl;
        cin >> r;
        cout << "enter the name of student " << i + 1 << endl;
        cin >> q;
        cout << "enter the section of student " << i + 1 << endl;
        cin >> s;
        cout << "enter the semester of student " << i + 1 << endl;
        cin >> j;
        s1[i] = student(r, q, s, j);
    }
    for (int i = 0; i < n; i++)
    {
        s1[i].display(i);
    }
}