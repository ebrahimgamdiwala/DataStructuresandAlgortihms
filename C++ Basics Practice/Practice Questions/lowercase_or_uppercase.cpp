#include <iostream>
using namespace std;

int main(){
    char ch;

    cout<<"Enter a character : \n";
    cin>>ch;
    if(ch>='A'&&ch<='Z'){
        cout<<ch<<" is an uppercase character\n";
    }
    else if(ch>='a'&&ch<='z'){
        cout<<ch<<" is an lowercase character\n";
    }
    
    return 0;
}