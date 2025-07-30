#include <iostream>
#include <string>

using namespace std;

// Define a class named Teacher
class Teacher
{
private:
    // Private member variable - can only be accessed by functions inside this class
    double salary;

public:
    // Public member variables - can be accessed directly from outside the class
    string name;     // Teacher's name
    string dept;     // Department name
    string subject;  // Subject the teacher teaches

    // Member function (method) to change the department
    void changeDept(string newDept)
    {
        // Set the dept member variable to the new department
        dept = newDept;
    }

    // Setter function to set the value of the private salary variable
    void setSalary(double s){
        salary = s;
    }

    // Getter function to return the value of the private salary variable
    double getSalary(){
        return salary;
    }
};


int main()
{
    // Create an object of the Teacher class named t1
    Teacher t1;

    // Set values for the public attributes of the t1 object
    t1.name = "Ebrahim";            // Assign the name "Ebrahim" to t1
    t1.subject = "C++";             // Assign the subject "C++" to t1
    t1.dept = "Computer Science";   // Assign the department "Computer Science" to t1

    // Set the salary using the setter function (since salary is private)
    t1.setSalary(250000);           // Set salary to 250000 using setSalary()

    // Output the teacher's information using cout
    cout << "Name: " << t1.name << endl;          // Output the name
    cout << "Subject: " << t1.subject << endl;    // Output the subject
    cout << "Department: " << t1.dept << endl;    // Output the department

    // Get and print the salary using the getter function
    cout << "Salary: " << t1.getSalary() << endl; // Output the salary using getSalary()

    // Return 0 to indicate successful execution
    return 0;
}
