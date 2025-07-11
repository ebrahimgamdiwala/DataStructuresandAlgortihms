#include <iostream>
using namespace std;

int diagonalSum2dArray(int matrix[3][3],int rows, int cols){
    int diagonalSum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i==j)
            {
                diagonalSum+=matrix[i][j];
            }
            else if(j == rows-i-1)
            {
                diagonalSum+=matrix[i][j];
            }
            
        }
        
    }
    return diagonalSum;
}

int main(){
    int matrix[3][3];
    int rows = 3;
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
    
    int ans = diagonalSum2dArray(matrix,rows,cols);
    cout<<"Sum of the diagonals of the entered matrix is : "<<ans; 

    return 0;
}