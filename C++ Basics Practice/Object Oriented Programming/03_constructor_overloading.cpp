#include <iostream>
using namespace std;

// Define a class Rectangle
class Rectangle {
private:
    int length;
    int width;

public:
    // Default constructor
    Rectangle() {
        length = 0;
        width = 0;
        cout << "Default constructor called." << endl;
    }

    // Constructor with one parameter (square)
    Rectangle(int side) {
        length = width = side;
        cout << "One-parameter constructor called." << endl;
    }

    // Constructor with two parameters (rectangle)
    Rectangle(int l, int w) {
        length = l;
        width = w;
        cout << "Two-parameter constructor called." << endl;
    }

    // Method to calculate area
    int area() {
        return length * width;
    }

    // Display rectangle details
    void display() {
        cout << "Length: " << length << ", Width: " << width 
             << ", Area: " << area() << endl;
    }
};

int main() {
    Rectangle r1;             // Calls default constructor
    Rectangle r2(5);          // Calls one-parameter constructor (square)
    Rectangle r3(4, 6);       // Calls two-parameter constructor

    cout << "\nRectangle 1:" << endl;
    r1.display();

    cout << "\nRectangle 2:" << endl;
    r2.display();

    cout << "\nRectangle 3:" << endl;
    r3.display();

    return 0;
}
