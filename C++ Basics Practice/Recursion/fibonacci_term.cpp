#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    int num;
    cout << "Enter a number (n) : " << "\n";
    cin >> num;

    cout << "The nth fibonacci term is : " << fibonacci(num) << endl;
    return 0;
}