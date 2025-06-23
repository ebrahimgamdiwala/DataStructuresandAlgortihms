#include <iostream>
using namespace std;

int binaryToDecimal(int binNum)
{
    int ans = 0, pow = 1, dig;
    while (binNum>0)
    {
        dig = binNum % 10;
        ans += pow*dig;
        pow *= 2;
        binNum /= 10;
    }
    
    return ans;
}

int main()
{
    int binNum = 10111;
    
        cout << binaryToDecimal(binNum) << endl;

    return 0;
}