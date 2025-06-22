#include <iostream>
using namespace std;

int main(){

    //While loop
    int n = 50;
    int count = 1;
    while (count<=n)
    {
        cout<<count<<" ";
        count++;
    }
    cout<<endl;
    // while (count<=n) //Infinite while loop
    // {
    //     cout<<count<<" ";
    // }

    //For loop
    for (int i = 1; i < n; i+=2)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    //Do while loop
    int i = 1;

    do {
        cout << "Current number: " << i << endl;
        i++;
    } while (i <= 5);

    i = 10;

    do {
        cout << "This will print once even though i > 5!" << endl;
    } while (i <= 5);

    return 0;
}