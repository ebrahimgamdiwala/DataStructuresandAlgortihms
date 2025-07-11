#include <iostream>
using namespace std;

int maxRowSum2dArray(int matrix[4][3],int rows, int cols){
    int maxRowSum = INT_MIN;
    for (int i = 0; i < rows; i++)
    {
        int currSum = 0;
        for (int j = 0; j < cols; j++)
        {
            currSum+=matrix[i][j];
        }
        maxRowSum = max(maxRowSum, currSum);
        
    }
    return maxRowSum;
}
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
    
    int ans = maxRowSum2dArray(matrix,rows,cols);
    cout<<"Max row sum of the entered matrix is : "<<ans; 

    return 0;
}