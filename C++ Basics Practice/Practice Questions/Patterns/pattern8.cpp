#include <iostream>
using namespace std;

int main(){
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <=i ; j++)
        {
            cout << " ";
        }
        
        for (int j = 1; j <= n-i; j++)
        {
            cout << i;
        }
        cout<<endl;
    }
    return 0;
}