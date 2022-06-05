/*To edit course records using files.
To delete course records using files.*/
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
    void deleted();
    void modify();
};

void course::menu()
{ // Main menu
START:
    int choice;
    char x;
    cout << "\n1. Add a new course" << endl;
    cout << "2. Display all course" << endl;
    cout << "3. Modify course" << endl;
    cout << "4. delete course" << endl;
    cout << "5. Exit" << endl;
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
        modify();
        break;
    case 4:
        deleted();
        break;
    case 5:
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

void course::modify()
{
    fstream file, file1;
    int course;
    int found = 0;
    file.open("course.txt", ios::in);
    if (!file)
        cout << "record is empty!";
    else
    {
        cout << "\nEnter a course number: ";
        cin >> course;
        file1.open("record.txt", ios::app | ios::out);
        file >> Course_name >> course_id;
        while (!file.eof())
        {
            if (course != course_id)
                file1 >> Course_name >> course_id;

            else
            {
                cout << "Enter new course id: ";
                cin >> course_id;
                cout << "Enter new course name: ";
                cin >> Course_name;

                file1 << " " << Course_name << " " << course_id << "\n";
                found++;
            }
            file >> Course_name >> course_id;

            if (found == 0)
                cout << "\nrecord not found!";
        }
        file1.close();
        file.close();
        remove("course.txt");
        rename("record.txt", "course.txt");
    }
}

void course::deleted()
{
    fstream file, file1;
    int found = 0;
    int course;
    file.open("course.txt", ios::in);
    if (!file)
    {
        cout << "\nrecord is empty!";
        file.close();
    }
    else
    {
        cout << "Enter a course number: ";
        cin >> course;
        file1.open("record.txt", ios::app | ios::out);
        file >> Course_name >> course_id;

        while (!file.eof())
        {
            if (course != course_id)
                file1 << " " << Course_name << " " << course_id << "\n";
            else
            {
                found++;
                cout << "\nrecord deleted successfully!";
            }
            file >> Course_name >> course_id;
        }
        if (found == 0)
            cout << "\nrecord not found!";
        file1.close();
        file.close();
        remove("course.txt");
        rename("record.txt", "course.txt");
    }
}
int main()
{
    course c;
    c.menu();
    return 0;
}
