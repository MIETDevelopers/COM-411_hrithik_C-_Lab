/*To implement inheritance of a UGCourse, PGCourse and DiplomaCourse class.*/
// Author:HRITHIK KOUL
#include <iostream>
using namespace std;

class diploma
{
public:
    void diploma_1()
    {
        cout << "completed diploma" << endl;
    }
};
class ug : public diploma
{
public:
    void ug_1()
    {
        cout << "completed ug course" << endl;
    }
};
class pg : public ug
{
public:
    void pg_1()
    {
        cout << "completed pg course" << endl;
    }
};

int main()
{
    pg p;
    p.diploma_1();
    p.ug_1();
    p.pg_1();
}
