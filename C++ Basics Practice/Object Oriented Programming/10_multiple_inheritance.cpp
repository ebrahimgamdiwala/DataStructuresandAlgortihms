#include <iostream>
using namespace std;

// Multiple Inheritance :
//  Parent1      Parent2
//     \          /
//      \        /
//       \      /
//         Child


// First base class
class Father {
public:
    void traitsFromFather() {
        cout << "Father: I am strong and disciplined.\n";
    }
};

// Second base class
class Mother {
public:
    void traitsFromMother() {
        cout << "Mother: I am kind and creative.\n";
    }
};

// Derived class inheriting from both Father and Mother
class Child : public Father, public Mother {
public:
    void ownTraits() {
        cout << "Child: I am a blend of both my parents.\n";
    }
};

int main() {
    Child c;

    // Accessing members from both base classes
    c.traitsFromFather();   // Father class
    c.traitsFromMother();   // Mother class
    c.ownTraits();          // Child class

    return 0;
}
