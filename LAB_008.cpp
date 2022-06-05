/*To store student record in file.
To search student record in file.*/
// Author:HRITHIK KOUL
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

class student
{
private:
    string first_name, last_name, house, address, landmark, city, contact_no;

public:
    void menu();
    void insert();
    void display();
    void search();
};

void student::menu()
{ // Main menu
START:
    int choice;
    char x;
    cout << "\n1. Add a new student" << endl;
    cout << "2. Display all student" << endl;

    cout << "3. Search student" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "Add another student (Y/N): ";
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
void student::insert()
{
    fstream file;

    cout << "Enter first name: ";
    cin >> first_name;
    cout << "Enter last name: ";
    cin >> last_name;
    cout << "Enter house no.: ";
    cin >> house;
    cout << "Enter address line: ";
    cin >> address;
    cout << "Enter landmark: ";
    cin >> landmark;
    cout << "Enter city: ";
    cin >> city;
    cout << "Enter contact no.: ";
    cin >> contact_no;
    file.open("student.txt", ios::app | ios::out);
    file << " " << first_name << " " << last_name << " " << house << " " << address << " " << landmark << " " << city << " " << contact_no << "\n";
    file.close();
}

void student::display()
{
    fstream file;
    int total = 0;
    file.open("student.txt", ios::in);
    if (!file)
    {
        cout << "record is empty!";
        file.close();
    }
    else
    {
        file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
        while (!file.eof())
        {
            cout << "\nstudent entry no.: " << ++total << endl;
            cout << "\nFirst name: " << first_name << endl;
            cout << "Last_name: " << last_name << endl;
            cout << "House no.: " << house << endl;
            cout << "Address line: " << address << endl;
            cout << "Landmark: " << landmark << endl;
            cout << "City: " << city << endl;
            cout << "Contact no.: " << contact_no << endl;
            file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
        }
        if (total == 0)
            cout << "record is empty!";
    }
    file.close();
}

void student::search()
{
    fstream file;
    int found = 0;
    file.open("student.txt", ios::in);
    if (!file)
    {
        cout << "record is empty!";
    }
    else
    {
        string contact;
        cout << "\nEnter a contact number: ";
        cin >> contact;
        file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
        while (!file.eof())
        {
            if (contact == contact_no)
            {
                cout << "First name: " << first_name << endl;
                cout << "Last name: " << last_name << endl;
                cout << "House no.: " << house << endl;
                cout << "Address line: " << address << endl;
                cout << "Landmark: " << landmark << endl;
                cout << "City: " << city << endl;
                cout << "Contact no.: " << contact_no << endl;
                found++;
            }
            file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
        }
        if (found == 0)
            cout << "\nstudent not found!";
        file.close();
    }
}

int main()
{
    student s;
    s.menu();
    return 0;
}
