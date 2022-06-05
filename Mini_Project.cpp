#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

class address{
    private:
        string first_name, last_name, house, address, landmark, city, contact_no;

    public:
        void menu();
        void insert();
        void display();
        void modify();
        void search();
        void deleted();
};

void address::menu(){  //Main menu
START:
    int choice;
    char x;
    system("cls");

    cout << "* USER ADDRESS BOOK *\n" << endl;
    cout << "\n1. Add a new contact" << endl;
    cout << "2. Display all contacts" << endl;
    cout << "3. Edit a contact" << endl;
    cout << "4. Search address book" << endl;
    cout << "5. Delete a contact" << endl;
    cout << "6. Exit" << endl;

    cout << "\nChoose an option: 1/2/3/4/5/6: ";
    cin >> choice;

    switch (choice){
    case 1:
        do{
            insert();
            cout << "Add another contact (Y/N): ";
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
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        exit(0);
    default:
        cout << "Invalid choice, please try again!";
    }
    getch();
    goto START;
}
void address::insert(){  //Adding contact details
    system("cls");
    fstream file;

    cout<< "\n* Add Contact *" << endl;
    cout<< "Enter fisrt name: ";
    cin>> first_name;
    cout<< "Enter last name: ";
    cin>> last_name;
    cout<< "Enter house no.: ";
    cin>>house;
    cout<< "Enter address line: ";
    cin>> address;
    cout<< "Enter landmark: ";
    cin>> landmark;
    cout<< "Enter city: ";
    cin>> city;
    cout<< "Enter contact no.: ";
    cin>> contact_no;
    file.open("addressBook.txt", ios::app | ios::out);
    file << " " << first_name << " " << last_name << " " << house << " " << address << " " << landmark << " " << city << " " << contact_no << "\n";
    file.close();
}

void address::display(){  //Displaying contact details
    system("cls");
    fstream file;
    int total = 1;
    cout << "* Address Book *" << endl;
    file.open("addressBook.txt", ios::in);
    if (!file){
        cout << "Book is empty!";
        file.close();
    }
    else{
        file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
        while (!file.eof()){
            cout << "\nContact entry no.: " << total++ << endl;
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
            cout << "Book is empty!";
    }
    file.close();
}
void address::modify(){  //Modifying contact details
    system("cls");
    fstream file, file1;
    string contact;
    int found = 0;
    cout << "* Edit Contact *" << endl;
    file.open("addressBook.txt", ios::in);
    if (!file)
        cout << "Book is empty!";
    else{
        cout << "\nEnter a contact number: ";
        cin >> contact;
        file1.open("record.txt", ios::app | ios::out);
        file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
        while (!file.eof()){
            if (contact != contact_no)
                file1 << " " << first_name << " " << last_name << " " << house << " " << address << " " << landmark << " " << city << " " << contact_no << "\n";
            else{
                cout<< "Enter new first name: ";
                cin>> first_name;
                cout<< "Enter new last name: ";
                cin>> last_name;
                cout<< "Enter house no.:";
                cin>> house;
                cout<< "Enter new address line: ";
                cin>> address;
                cout<< "Enter new landmark: ";
                cin>> landmark;
                cout<< "Enter new city: ";
                cin>> city;
                cout<< "Enter new contact: ";
                cin>> contact_no;
                file1 << " " << first_name << " " << last_name << " " << house << " " << address << " " << landmark << " " << city << " " << contact_no<< "\n";
                found++;
            }
            file >> first_name >>  last_name >> house >> address >> landmark >> city >> contact_no;
            if (found == 0)
                cout << "\nContact not found!";
        }
        file1.close();
        file.close();
        remove("addressBook.txt");
        rename("record.txt", "addressBook.txt");
    }
}
void address::search(){  //Searching contact data
    system("cls");
    fstream file;
    int found = 0;
    file.open("addressBook.txt", ios::in);
    if (!file){
        cout << "* Search Contact *" << endl;
        cout << "Book is empty!";
    }
    else{
        string contact;
        cout << "* Search Contact *" << endl;
        cout << "\nEnter a contact number: ";
        cin >> contact;
        file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
        while (!file.eof()){
            if (contact == contact_no){
                cout << "First name: " << first_name << endl;
                cout << "Last name: " << last_name << endl;
                cout<< "House no.: " << house << endl;
                cout << "Address line: " << address << endl;
                cout << "Landmark: " << landmark << endl;
                cout << "City: " << city << endl;
                cout << "Contact no.: " << contact_no << endl;
                found++;
            }
            file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
        }
        if (found == 0)
            cout << "\nContact not found!";
        file.close();
    }
}
void address::deleted()  //Deleting contact 
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "* Delete Contact *" << endl;
    file.open("addressBook.txt", ios::in);
    if (!file)
    {
        cout << "\nBook is empty!";
        file.close();
    }
    else
    {
        cout << "Enter a contact number: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
        while (!file.eof()){
            if (roll != contact_no)
                file1 << " " << first_name << " " << last_name << " " << house << " " << address << " " << landmark << " " << city << " " << contact_no << "\n";
            else{
                found++;
                cout << "\nContact deleted successfully!";
            }
            file >> first_name >> last_name >> house >> address >> landmark >> city >> contact_no;
        }
        if (found == 0)
            cout << "\nContact not found!";
        file1.close();
        file.close();
        remove("addressBook.txt");
        rename("record.txt", "addressBook.txt");
    }
}
int main(){  
    address project;
    project.menu();
    return 0;
}          
        