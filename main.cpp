#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int num;
    string name;
    char sex[10];
public:
    void get_value()
    {
        cin>>num>>name>>sex;
    }
    void display()
    {
        cout<<"num is "<<num<<endl;
        cout<<"name is "<<name<<endl;
        cout<<"sex is "<<sex<<endl;
    }
};
class Student1:public Student
{
private:
    int age;
    string addr;
public:
    void get_value_1()
    {
        cin>>age>>addr;
    }
    void display_1()
    {
        cout<<num<<endl;
        Student::display();
        cout<<"age is "<<age<<endl;
        cout<<"addr is "<<addr<<endl;
    }
};
int main()
{
    Student1 stu;
    stu.get_value();
    stu.get_value_1();
    stu.display();
    stu.display_1();
    return 0;
}
