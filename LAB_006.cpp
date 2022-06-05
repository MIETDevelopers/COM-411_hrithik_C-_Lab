/*To delete the details of a course using a member function of course class.
To get the details of a course by using course_id member function of course class.*/
// Author:HRITHIK KOUL
#include <iostream>
using namespace std;
class course
{
    int cId, months;
    string cName, iname;

public:
    course()
    {
        cId = 0;
    }
    int id()
    {
        return cId;
    }
    void get()
    {
        cout << "Enter Course Id: ";
        cin >> cId;
        cout << "Enter Course Name: ";
        cin >> cName;
        cout << "Enter Course Duration(In Months): ";
        cin >> months;
        cout << "Enter Instructor Name: ";
        cin >> iname;
    }
    void display()
    {
        cout << "\nCourse Id: " << cId << endl;
        cout << "Course Name: " << cName << endl;
        cout << "Course Duration(In Months): " << months << endl;
        cout << "Course Instructor: " << iname << endl;
    }
    int CourseID()
    {
        return cId;
    }
    void del()
    {
        cout << "Course Details Deleted!";
    }
};
int main()
{
    int x, k = 8;
    course c[3];
    for (int i = 0; i < 2; i++)
    {
        cout << "\nEnter Details of Course " << i + 1 << endl;
        c[i].get();
    }
    cout << "\nEnter the Course ID to display Details of Course you want: ";
    cin >> x;
    for (int i = 0; i < 2; i++)
    {
        if (c[i].CourseID() == x)
        {
            c[i].display();
            k = 0;
        }
        else
        {
            if (k != 0 && i == 2 - 1)
                cout << "rollno not found";
        }
    }
    cout << "\nEnter the Course ID to delete Details of Course you want: ";
    cin >> x;
    for (int i = 0; i < 2; i++)
    {
        if (c[i].CourseID() == x)
        {
            c[i] = c[i + 1];
            c[i + 1] = course();
            c[i].del();
            k = 1;
        }
        else
        {
            if (k != 1 && i == 2 - 1)
            {
                cout << "rollno not found";
                k = 0;
            }
        }
    }
    if (k == 1)
    {
        for (int i = 0; i < 2; i++)
        {
            if (c[i].id() != 0)
            {
                c[i].display();
                k = 2;
            }
        }
        if (k != 2)
        {
            cout << "no record";
        }
    }
    return 0;
}