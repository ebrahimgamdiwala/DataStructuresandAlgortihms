#include <iostream>
using namespace std;

int main(){
    int matrix[4][3];
    int rows = 4;
    int cols = 3;

    //Input

    cout << "Enter the elements of the matrix : \n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter matrix ["<<i<<"]"<<"["<<j<<"]\n";
            cin >> matrix[i][j];
            cout<<endl;
        }
    }

    //Output
    
    cout << "\nThe entered matrix is : \n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<< matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}