/*To update the details of a student using a member function of student class
To delete the details of a student using member function of student class*/
// Author:HRITHIK KOUL
#include <iostream>
using namespace std;
class student
{
    int rollno;
    string name, section, semester;

public:
    student();
    student(int x, string y, string z, string q);
    void display(int);
    void update();
    int roll();
    void deleted();
};
student::student(int x, string y, string z, string q)
{
    rollno = x;
    name = y;
    section = z;
    semester = q;
}
student::student()
{
    rollno = 0;
    name = "";
    section = "";
    semester = "";
}
void student::display(int j)
{
    cout << "student " << j + 1 << " rollno is " << rollno << endl;
    cout << "student " << j + 1 << " name is " << name << endl;
    cout << "student " << j + 1 << " section is " << section << endl;
    cout << "student " << j + 1 << " semester is " << semester << endl;
}
int student::roll()
{
    return rollno;
}
void student::update()
{
    cout << "enter the rollno of student " << endl;
    cin >> this->rollno;
    cout << "enter the name of student " << endl;
    cin >> this->name;
    cout << "enter the section of student " << endl;
    cin >> this->section;
    cout << "enter the semester of student " << endl;
    cin >> this->semester;
}
void student::deleted()
{
    cout << "details deleted" << endl;
}
int main()
{
    student s1[25];
    int n, r, x;
    int track = 0;
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
    cout << "\nEnter the student rollno to update the details: ";
    cin >> x;
    for (int i = 0; i < n; ++i)
    {
        if (x == s1[i].roll())
        {
            s1[i].update();
            track = 1;
        }
        else
        {
            if (i == n - 1)
                cout << "rollno not found";
        }
    }
    if (track == 1)
    {
        cout << "printing updated details" << endl;
        for (int i = 0; i < n; i++)
        {
            s1[i].display(i);
        }
    }
    track = 0;
    cout << "\nEnter the student rollno to delete the details: ";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (x == s1[i].roll())
        {
            s1[i] = s1[i + 1];
            s1[i + 1] = student();
            s1[i].deleted();
            track = 1;
        }
        else
        {
            if (i == n - 1)
                cout << "rollno not found";
        }
    }

    if (track == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (s1[i].roll() != 0)
            {
                cout << "printing after deleting details" << endl;
                s1[i].display(i);
                track++;
            }
            else
            {
                if (i == n - 1 && track==1)
                    cout << "no record left";
            }
        }
    }
}