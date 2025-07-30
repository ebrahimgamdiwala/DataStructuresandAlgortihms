#include <iostream>
#include <string>
using namespace std;

// Class to demonstrate Copy Constructor
class Student {
private:
    string name;
    int age;

public:
    // Parameterized constructor
    // Used to initialize object with specific values
    Student(string n, int a) {
        name = n;
        age = a;
        cout << "Parameterized constructor called." << endl;
    }

    // Copy constructor
    // Called when a new object is created from an existing object
    // Syntax: ClassName(const ClassName &obj)
    // It creates a **shallow copy** of the object's members
    Student(const Student &s) {
        name = s.name;
        age = s.age;
        cout << "Copy constructor called." << endl;
    }

    // Method to display student info
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Creating original object using parameterized constructor
    Student s1("Ali", 20);

    // Creating a copy of s1 using copy constructor
    // This is where the copy constructor is automatically invoked
    Student s2 = s1;

    cout << "\nOriginal Student (s1):" << endl;
    s1.display();

    cout << "\nCopied Student (s2):" << endl;
    s2.display();

    return 0;
}
