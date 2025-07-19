#include <iostream>
using namespace std;

int sum_of_n_numbers(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sum_of_n_numbers(n - 1);
}
int main()
{
    int num;
    cout << "Enter a number : " << "\n";
    cin >> num;

    cout << "The sum of the numbers upto the entered number is : " << sum_of_n_numbers(num) << endl;
    return 0;
}