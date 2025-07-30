#include <iostream>
#include <string>

using namespace std;

// Define a class named Car
class Car
{
private:
    string brand;
    string model;
    int year;

public:
    // Default constructor (no parameters)
    Car() {
        // This sets default values if no arguments are passed
        brand = "Unknown";
        model = "Unknown";
        year = 0;
        cout << "Default constructor called." << endl;
    }

    // Parameterized constructor
    Car(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
        cout << "Parameterized constructor called." << endl;
    }

    // Display function to show car details
    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int main()
{
    // Create an object using the default constructor
    Car car1;  // Calls Car()

    // Create an object using the parameterized constructor
    Car car2("Toyota", "Corolla", 2021);  // Calls Car(string, string, int)

    cout << "\nCar 1 Info:" << endl;
    car1.displayInfo();

    cout << "\nCar 2 Info:" << endl;
    car2.displayInfo();

    return 0;
}
