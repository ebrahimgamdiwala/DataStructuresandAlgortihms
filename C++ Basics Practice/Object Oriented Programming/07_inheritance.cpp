#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    string name;
    int age;

    Person(string name, int age){
        this->name = name;
        this->age = age;
        cout << "Parent/Base Class Constructor" << endl;
    }

    Person()
    {
        cout << "Parent/Base Class Constructor" << endl;
    }
    ~Person()
    {
        cout << "Parent/Base Class Destructor" << endl;
    }
};

class Student : public Person
{
public:
    int rollno;
    // Student()
    // {
    //     cout << "Child/Derived Class Constructor" << endl;
    // }
    Student(string name, int age, int rollno) : Person(name, age) // Here we explicitly call the parent class constructor
    {
        this->rollno = rollno;
        cout << "Child/Derived Class Constructor" << endl;
    }
    ~Student()
    {
        cout << "Child/Derived Class Destructor" << endl;
    }
    void getInfo()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Roll No : " << rollno << endl;
    }
};
int main()
{
    Student s1("Ebrahim", 20, 26);
    // s1.name = "Ebrahim";
    // s1.age = 20;
    // s1.rollno = 26;

    s1.getInfo();

    return 0;
}