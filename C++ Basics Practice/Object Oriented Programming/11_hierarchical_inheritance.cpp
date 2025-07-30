#include <iostream>
using namespace std;

// Hierarchical Inheritance :
//          Parent
//          /    \
//         /      \
//    Child1     Child2


// Base class
class Parent {
public:
    void familyValues() {
        cout << "Parent: We value honesty and hard work.\n";
    }
};

// First derived class
class Child1 : public Parent {
public:
    void profession1() {
        cout << "Child1: I am a teacher.\n";
    }
};

// Second derived class
class Child2 : public Parent {
public:
    void profession2() {
        cout << "Child2: I am an engineer.\n";
    }
};

int main() {
    Child1 c1;
    Child2 c2;

    cout << "--- Child1 Object ---\n";
    c1.familyValues();  // Inherited from Parent
    c1.profession1();   // Child1 specific

    cout << "\n--- Child2 Object ---\n";
    c2.familyValues();  // Inherited from Parent
    c2.profession2();   // Child2 specific

    return 0;
}
