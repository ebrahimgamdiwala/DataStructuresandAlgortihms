#include <iostream>
using namespace std;

int main(){
    int age = 19;
    float price = 699.99f;
    double pi = 3.1415;
    char grade = 'A';
    bool flag = true;

    cout<<"Variables :\n\n";
    cout<<"age (Integer) = "<<age<<"\n";
    cout<<"price (Float) = "<<price<<"\n";
    cout<<"pi (Double) = "<<pi<<"\n";
    cout<<"grade (Character) = "<<grade<<"\n";
    cout<<"flag (Boolean) = "<<flag<<"\n\n\n"; // true -> 1 false -> 0

    cout<<"Size of Variables :\n\n";
    cout<<"age (Integer) = "<<sizeof(age)<<"\n";
    cout<<"price (Float) = "<<sizeof(price)<<"\n";
    cout<<"pi (Double) = "<<sizeof(pi)<<"\n";
    cout<<"grade (Character) = "<<sizeof(grade)<<"\n";
    cout<<"flag (Boolean) = "<<sizeof(flag)<<"\n";

    return 0;
}