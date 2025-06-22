#include <iostream>
using namespace std;

int main(){
    int sum = 0;
    int n;

    cout<<"Enter a number n : \n";
    cin>>n;

    for (int i = 0; i <= n; i++)
    {
        sum+=i;
    }

    cout<<"The sum of first "<<n<<" numbers is : "<<sum;

    sum = 0;
    
    for (int i = 1; i <= n; i+=2)
    {
        sum+=i;
    }

    cout<<"\nThe sum of first "<<n<<" odd numbers is : "<<sum;

    return 0;
}