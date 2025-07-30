#include <iostream>
using namespace std;

// Multilevel Inheritance :
// Grandparent (Base)
//    ↓
// Parent (Derived from Base)
//    ↓
// Child (Derived from Parent)


// Base class
class Grandparent {
public:
    void familyOrigin() {
        cout << "Grandparent: We are from the royal family.\n";
    }
};

// Derived from Grandparent
class Parent : public Grandparent {
public:
    void profession() {
        cout << "Parent: I am a doctor.\n";
    }
};

// Derived from Parent
class Child : public Parent {
public:
    void hobby() {
        cout << "Child: I love painting.\n";
    }
};

int main() {
    Child c;

    // Accessing functions from all three levels
    c.familyOrigin();  // Grandparent class
    c.profession();    // Parent class
    c.hobby();         // Child class

    return 0;
}
