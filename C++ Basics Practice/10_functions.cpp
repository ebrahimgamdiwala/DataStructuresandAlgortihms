#include <iostream>
using namespace std;

// Function Definition

void printHello()
{
    cout << "Hello\n";
}
double sum(double a, double b)
{
    return a + b;
}
int minOfTwo(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
int sumOfNos(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}
int factorialOfNo(int num)
{
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{

    printHello();
    cout << "Sum of 10.99 and 5.65 is : " << sum(10.99, 5.65) << "\n";
    cout << "Minimum of 5 and 3 is : " << minOfTwo(5, 3) << "\n";
    cout << "Sum of first 10 numbers is : " << sumOfNos(10) << "\n";
    cout << "Factorial of 5 is : " << factorialOfNo(5) << "\n";

    return 0;
}