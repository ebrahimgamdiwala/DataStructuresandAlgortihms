#include <iostream>
using namespace std;

pair<int,int> linearSearch2dArray(int matrix[4][3],int rows, int cols,int target){
    pair <int,int> ans = {0, 0};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(matrix[i][j] == target){
                ans.first = i;
                ans.second = j;
            }
        }
        
    }
    return ans;
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
    int target;
    cout << "Enter the element you want to search : \n";
    cin>>target;
    pair<int,int> ans = linearSearch2dArray(matrix,rows,cols,target);
    cout<<"Element found at index : ["<<ans.first<<"]"<<"["<<ans.second<<"]"; 

    return 0;
}