#include <iostream>
using namespace std;

int addDigits(int num)
{
    int sum = 0;
    while (num)
    {
        sum += (num % 10);
        num /= 10;
    }
    if (sum < 10)
    {
        return sum;
    }
    else
    {
        return addDigits(sum);
    }
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "The result is: " << addDigits(num) << endl;
    return 0;
}