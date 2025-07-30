#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;     // Automatically managed
    double* gpa;     // Manually managed (dynamic memory)

public:
    // Constructor
    Student(const string& n, double g) {
        name = n;
        gpa = new double(g);  // Allocate memory for GPA
        cout << "Constructor called for " << name << endl;
    }

    // Destructor
    ~Student() {
        delete gpa;  // Free the dynamically allocated memory
        cout << "Destructor called for " << name << endl;
    }

    // Display function
    void display() const {
        cout << "Name: " << name << ", GPA: " << *gpa << endl;
    }
};

int main() {
    Student s("Ebrahim", 3.75);
    s.display();

    // Destructor will be called automatically here when 's' goes out of scope

    return 0;
}
