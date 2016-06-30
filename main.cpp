#include <iostream>
#include <string>
using namespace std;

class student
{
private:
    int num;
    string name;
    char sex;
public:
    void get_value()
    {
        cout<<"学号: ";
        cin>>num;
        cout<<"姓名: ";
        cin>>name;
        cout<<"性别: "<<endl;
        cin>>sex;
    }
    void display()
    {
        cout<<"学号："<<num<<"\n"<<"姓名: "<<name<<"\n"<<"性别: "<<sex<<endl;
    }
};
class student1:private student
{
private:
    int age;
    string addr;
public:
    void get_value_1()
    {
        get_value();
        cout<<"年龄: ";
        cin>>age;
        cout<<"地址: ";
        cin>>addr;
    }
    void display_1()
    {
        display();
        cout<<"年龄："<<age<<"\n地址："<<addr<<endl;
    }
};
int main()
{
    student1 stu;
    stu.get_value_1();
    stu.display_1();
    return 0;

}
