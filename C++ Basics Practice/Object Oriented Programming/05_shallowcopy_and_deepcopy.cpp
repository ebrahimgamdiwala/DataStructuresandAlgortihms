#include <iostream>
#include <string>  // for std::string

using namespace std;

class Student {
private:
    string name;    // Using std::string (no manual memory management needed)
    double* gpa;    // GPA stored as dynamically allocated double

public:
    // Constructor
    Student(const string& n, double g) {
        name = n;
        gpa = new double(g);  // Allocate memory and store GPA value
        cout << "Constructor called." << endl;
    }

    // Deep copy constructor
    Student(const Student& s) {
        name = s.name;           // std::string copies automatically (deep copy internally)
        gpa = new double(*s.gpa); // Allocate new memory and copy GPA value
        cout << "Deep copy constructor called." << endl;
    }

    // Shallow copy constructor (unsafe) — comment out if testing deep copy
    // Student(const Student& s) {
    //     name = s.name;
    //     gpa = s.gpa;  // Pointer copied directly — SHALLOW COPY
    //     cout << "Shallow copy constructor called." << endl;
    // }

    // Update student's data
    void update(const string& newName, double newGpa) {
        name = newName;
        *gpa = newGpa;
    }

    // Display student info
    void display() const {
        cout << "Name: " << name << ", GPA: " << *gpa << endl;
    }
};

int main() {
    // Create student s1
    Student s1("John", 3.6);

    // Create a copy s2 using copy constructor
    Student s2 = s1;

    cout << "\nBefore updating s1:" << endl;
    s1.display();
    s2.display();

    // Update s1
    s1.update("Elliot", 3.9);

    cout << "\nAfter updating s1:" << endl;
    s1.display();
    s2.display();  // If deep copy used, s2 remains unchanged

    return 0;
}
