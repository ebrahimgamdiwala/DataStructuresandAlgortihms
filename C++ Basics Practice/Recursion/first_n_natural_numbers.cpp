#include <iostream>
using namespace std;

void printNaturalNumbers(int n){
    if (n==0)
    {
        return;
    }
    cout<<n<<" ";
    printNaturalNumbers(n-1);
    
}
int main(){
    printNaturalNumbers(10);
    return 0;
}