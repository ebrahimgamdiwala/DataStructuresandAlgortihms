#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}
int main()
{
    int num;
    cout << "Enter a number : " << "\n";
    cin >> num;

    cout << "The factorial of the entered number is : " << factorial(num) << endl;
    return 0;
}