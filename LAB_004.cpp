/*To search student details by roll no. using a member function of student class.
To get the results of students by roll no. using a member function of student class.*/
// Author:HRITHIK KOUL
#include <iostream>
using namespace std;
class Student
{
private:
    int roll_number;
    string name;
    int score;
    string result;

public:
    void getDetails()
    {
        cout << "Enter roll number: " << endl;
        cin >> roll_number;
        cout << "Enter name: " << endl;
        cin >> name;
        cout << "Enter score: " << endl;
        cin >> score;
        cout << "Enter remarks: " << endl;
        cin >> result;
    }
    void displayDetails()
    {
        cout << "Roll number: " << roll_number << endl;
        cout << "Name: " << name << endl;
        cout << "Score: " << score << endl;
        cout << "Result: " << result << endl;
    }
    void search(int i, int n)
    {
        int j;
        if (i == 0)
        {
            cout << "enter roll no to search student details" << endl;
            cin >> j;
        }
        if (j == this->roll_number)
        {
            this->displayDetails();
        }
        else
        {
            if (i == n)
                cout << "student details not found" << endl;
        }
    }
    void results()
    {
        cout << result << endl;
    }
    void get_result(int i, int n)
    {
        int x;
        if (i == 0)
        {
            cout << "enter rollno to search result" << endl;
            cin >> x;
        }
        if (x == (this)->roll_number)
        {
            this->results();
        }
        else
        {
            if (i == n)
                cout << "student details not found" << endl;
        }
    }
};

int main()
{
    Student s[10];
    int n;
    cout << "how many details you want to enter" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        s[i].getDetails();
    }

    for (int i = 0; i < n; i++)
    {
        s[i].displayDetails();
    }
    for (int i = 0; i < n; i++)
    {
        s[i].search(i, n);
    }
    for (int i = 0; i < n; i++)
    {
        s[i].get_result(i, n);
    }
    return 0;
}
