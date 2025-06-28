#include <iostream>
using namespace std;

// Function for Function Pointer demo
void greet() {
    cout << "Hello from greet()!\n";
}

// Function for Pass by Pointer
void changeValue(int* ptr) {
    *ptr = 20;
}

int main() {
    cout << "==== 1. Basic Pointer ====\n";
    int a = 10;
    int* ptr = &a;
    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Pointer ptr points to: " << ptr << endl;
    cout << "Value pointed by ptr: " << *ptr << endl;

    cout << "\n==== 2. Pointer to Different Types ====\n";
    float f = 3.14;
    char c = 'A';
    float* pf = &f;
    char* pc = &c;
    cout << "Float: " << *pf << ", Char: " << *pc << endl;

    cout << "\n==== 3. Pointer Arithmetic ====\n";
    int arr[] = {10, 20, 30};
    int* parr = arr;
    cout << "First element: " << *parr << endl;
    parr++;
    cout << "Second element: " << *parr << endl;

    cout << "\n==== 4. NULL Pointer ====\n";
    int* nullPtr = nullptr;
    cout << "Null pointer address: " << nullPtr << endl;

    cout << "\n==== 5. Dangling Pointer (Example - DO NOT USE IN REAL CODE) ====\n";
    // int* dp = create(); // Unsafe, shows concept only

    cout << "\n==== 6. Dynamic Memory Allocation ====\n";
    int* dyn = new int;
    *dyn = 42;
    cout << "Dynamically allocated value: " << *dyn << endl;
    delete dyn;
    dyn = nullptr;

    int* dynArr = new int[3]{1, 2, 3};
    cout << "Dynamic array element 1: " << dynArr[0] << endl;
    delete[] dynArr;

    cout << "\n==== 7. Pass by Pointer to Function ====\n";
    int x = 10;
    changeValue(&x);
    cout << "Modified x: " << x << endl;

    cout << "\n==== 8. Pointer to Pointer ====\n";
    int* p = &a;
    int** pp = &p;
    cout << "Value via pointer to pointer: " << **pp << endl;

    cout << "\n==== 9. Array and Pointer Relationship ====\n";
    int nums[3] = {5, 10, 15};
    int* pn = nums;
    cout << "nums[1] via pointer: " << *(pn + 1) << endl;

    cout << "\n==== 10. Void Pointer ====\n";
    void* vptr;
    vptr = &a;
    cout << "Void pointer pointing to int a: " << *(static_cast<int*>(vptr)) << endl;

    cout << "\n==== 11. Function Pointer ====\n";
    void (*fp)() = greet;
    fp();

    cout << "\n==== 12. Const with Pointers ====\n";
    int b = 100;
    const int* cp1 = &a;     // Cannot modify *cp1
    int* const cp2 = &a;     // Cannot change cp2 itself
    const int* const cp3 = &a; // Neither *cp3 nor cp3 can change
    cout << "*cp1: " << *cp1 << ", *cp2: " << *cp2 << ", *cp3: " << *cp3 << endl;

    return 0;
}
