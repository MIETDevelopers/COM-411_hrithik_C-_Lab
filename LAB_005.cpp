/*To add the details of a course using a parameterized constructor of a course class.
To update the details of a course using a roll no using a member function of course class.*/
// Author:HRITHIK KOUL
#include <iostream>
#include <string>
using namespace std;
class course
{
   int course_id;
   string course_name;
   string Course_Duration;

public:
   course(int courseid, string coursen, string coursed);
   course() {}
   void print_CourseInfo();
   void update(int i, int n);
};
course::course(int courseid, string coursen, string coursed)
{
   course_id = courseid;
   course_name = coursen;
   Course_Duration = coursed;
}

void course::print_CourseInfo()
{
   cout << "rollno of course taker:" << course_id << endl;
   cout << "Course name:" << course_name << endl;
   cout << "Course Duration:" << Course_Duration << endl;
}
void course::update(int i, int n)
{
   int a;
   if (i == 0)
   {
      cout << "enter the rollno for which you want to update" << endl;
      cin >> a;
   }
   if (a == this->course_id)
   {
      cout << "Update the details" << endl;
      cout << "enter the course taker rollno" << endl;
      cin >> course_id;
      cout << "enter the course name" << endl;
      cin >> course_name;
      cout << "enter the course duration" << endl;
      cin >> Course_Duration;
      cout << "printing updated details" << endl;
      this->print_CourseInfo();
   }
   else
   {
      if (i == n)
         cout << "course detail not found" << endl;
   }
}
int main()
{
   course c1[10];
   int x;
   string y, z;
   int n;
   cout << "how many course details you want to enter";
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      cout << "enter the course taker " << i + 1 << " rollno" << endl;
      cin >> x;
      cout << "enter the course " << i + 1 << " name" << endl;
      cin >> y;
      cout << "enter the course " << i + 1 << " duration" << endl;
      cin >> z;
      c1[i] = course(x, y, z);
   }
   for (int i = 0; i < n; i++)
   {
      c1[i].print_CourseInfo();
   }
   for (int i = 0; i < 2; i++)
   {
      c1[i].update(i, n);
   }
}