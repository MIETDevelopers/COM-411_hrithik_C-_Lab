/*To create Course records using files.
To search records by course_id using files.*/
// Author:HRITHIK KOUL
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

class course
{
private:
    string Course_name;
    int course_id;

public:
    void menu();
    void insert();
    void display();
    void search();
};

void course::menu()
{
START:
    int choice;
    char x;
    cout << "\n1. Add a new course" << endl;
    cout << "2. Display all course" << endl;

    cout << "3. Search course" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "Add another course (Y/N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        search();
        break;

    case 4:
        exit(0);
    default:
        cout << "Invalid choice, please try again!";
    }
    getch();
    goto START;
}
void course::insert()
{
    fstream file;

    cout << "Enter course name: ";
    cin >> Course_name;
    cout << "Enter course id name: ";
    cin >> course_id;
    file.open("course.txt", ios::app | ios::out);
    file << " " << Course_name << " " << course_id << "\n";
    file.close();
}

void course::display()
{
    fstream file;
    int total = 0;
    file.open("course.txt", ios::in);
    if (!file)
    {
        cout << "course is empty!";
        file.close();
    }
    else
    {
        file >> Course_name >> course_id;
        while (!file.eof())
        {
            cout << "\ncourse entry no.: " << ++total << endl;
            cout << "\ncourse name: " << Course_name << endl;
            cout << "\ncourse id: " << course_id << endl;

            file >> Course_name >> course_id;
        }
        if (total == 0)
            cout << "course is empty!";
    }
    file.close();
}

void course::search()
{
    fstream file;
    int found = 0;
    file.open("course.txt", ios::in);
    if (!file)
    {
        cout << "course is empty!";
    }
    else
    {
        int id;
        cout << "\nEnter a course id: ";
        cin >> id;
        file >> Course_name >> course_id;

        while (!file.eof())
        {
            if (id == course_id)
            {
                cout << "\ncourse name: " << Course_name << endl;
                cout << "\ncourse id: " << course_id << endl;
                found++;
            }
            file >> Course_name >> course_id;
        }
        if (found == 0)
            cout << "\nCourse not found!";
        file.close();
    }
}

int main()
{
    course c;
    c.menu();
    return 0;
}
