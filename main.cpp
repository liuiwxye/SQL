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
        cout<<"ѧ��: ";
        cin>>num;
        cout<<"����: ";
        cin>>name;
        cout<<"�Ա�: "<<endl;
        cin>>sex;
    }
    void display()
    {
        cout<<"ѧ�ţ�"<<num<<"\n"<<"����: "<<name<<"\n"<<"�Ա�: "<<sex<<endl;
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
        cout<<"����: ";
        cin>>age;
        cout<<"��ַ: ";
        cin>>addr;
    }
    void display_1()
    {
        display();
        cout<<"���䣺"<<age<<"\n��ַ��"<<addr<<endl;
    }
};
int main()
{
    student1 stu;
    stu.get_value_1();
    stu.display_1();
    return 0;

}
