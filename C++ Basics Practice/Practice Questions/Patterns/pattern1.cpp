#include <iostream>
using namespace std;

int main(){
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<(char)(64+j)<<" "; //Different variations could be printing * or numbers
        }
        cout<<endl;
    }
    
    return 0;
}