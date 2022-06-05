/*To implement Polymorphism for member functions of UGCourse class, PGCourse class and DiplomaCourse class.*/
//Author:HRITHIK KOUL
#include <iostream>
using namespace std;

class diploma
{
public:
    virtual void status()
    {
        cout << "completed diploma" << endl;
    }
};
class ug : public diploma
{
public:
    virtual void status()
    {
        cout << "completed ug course" << endl;
    }
};
class pg : public ug
{
public:
    virtual void status()
    {
        cout << "completed pg course" << endl;
    }
};

int main()
{
    diploma *ptr;
    diploma d;
    ug u;
    pg p;
    ptr = &d;
    ptr->status();
    ptr = &u;
    ptr->status();
    ptr = &p;
    ptr->status();
}
