#include <iostream>
using namespace std;

/*
==============================================================
| Base Class ↓ / Derived Class → | Private | Protected | Public |
|-------------------------------|---------|-----------|--------|
| Private                       |   ❌    |     ❌     |   ❌   |
| Protected                     | Private | Protected |Protected|
| Public                        | Private | Protected | Public |
==============================================================
Legend:
❌ = Not Inherited
Other = Becomes that access specifier in Derived class
This table shows how base class members behave in the derived class
based on inheritance mode in C++.
*/

// Base classes with different access specifiers
class PrivateBase {
private:
    int a = 10;
public:
    void show() {
        cout << "PrivateBase: a = " << a << endl;
    }
};

class ProtectedBase {
protected:
    int b = 20;
public:
    void show() {
        cout << "ProtectedBase: b = " << b << endl;
    }
};

class PublicBase {
public:
    int c = 30;
    void show() {
        cout << "PublicBase: c = " << c << endl;
    }
};

// -------------------------------------------------------------------
// 1. Base = Private -> Not inherited in any mode
// -------------------------------------------------------------------
class DerivedFromPrivate_Public : public PrivateBase {};
class DerivedFromPrivate_Protected : protected PrivateBase {};
class DerivedFromPrivate_Private : private PrivateBase {};

// -------------------------------------------------------------------
// 2. Base = Protected -> Inherited as per mode
// -------------------------------------------------------------------
class DerivedFromProtected_Public : public ProtectedBase {
public:
    void access() { cout << "DerivedFromProtected_Public: b = " << b << endl; }
};

class DerivedFromProtected_Protected : protected ProtectedBase {
public:
    void access() { cout << "DerivedFromProtected_Protected: b = " << b << endl; }
};

class DerivedFromProtected_Private : private ProtectedBase {
public:
    void access() { cout << "DerivedFromProtected_Private: b = " << b << endl; }
};

// -------------------------------------------------------------------
// 3. Base = Public -> Inherited as per mode
// -------------------------------------------------------------------
class DerivedFromPublic_Public : public PublicBase {
public:
    void access() { cout << "DerivedFromPublic_Public: c = " << c << endl; }
};

class DerivedFromPublic_Protected : protected PublicBase {
public:
    void access() { cout << "DerivedFromPublic_Protected: c = " << c << endl; }
};

class DerivedFromPublic_Private : private PublicBase {
public:
    void access() { cout << "DerivedFromPublic_Private: c = " << c << endl; }
};

// -------------------------------------------------------------------
// Main
// -------------------------------------------------------------------
int main() {
    cout << "=== Inheritance Access Table Demonstration ===\n";

    cout << "\nBase Class: Private (Not inherited)\n";
    // DerivedFromPrivate_Public dpp; // Not inherited, nothing to show

    cout << "\nBase Class: Protected" << endl;
    DerivedFromProtected_Public d1;
    d1.access(); // ✅

    DerivedFromProtected_Protected d2;
    d2.access(); // ✅

    DerivedFromProtected_Private d3;
    d3.access(); // ✅

    cout << "\nBase Class: Public" << endl;
    DerivedFromPublic_Public d4;
    d4.access();         // ✅ public access
    cout << d4.c << endl; // ✅ public

    DerivedFromPublic_Protected d5;
    d5.access();         // ✅ protected inside class
    // cout << d5.c << endl; // ❌ protected outside

    DerivedFromPublic_Private d6;
    d6.access();         // ✅ private inside class
    // cout << d6.c << endl; // ❌ private outside

    return 0;
}
