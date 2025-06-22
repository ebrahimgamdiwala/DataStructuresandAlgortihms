#include <iostream>
using namespace std;

int main(){

    //Implicit Type Conversion
    char grade = 'A';
    int value = grade;

    cout<<"Implicit Type Conversion :\n\n";
    cout<<"grade = "<<grade<<"\n";
    cout<<"value = "<<value<<"\n\n";

    //Explicit Type Conversion
    double price = 349.99;
    int newPrice = (int)price;

    cout<<"Explicit Type Conversion :\n\n";
    cout<<"price = "<<price<<"\n";
    cout<<"newPrice = "<<newPrice<<"\n";
    return 0;
}