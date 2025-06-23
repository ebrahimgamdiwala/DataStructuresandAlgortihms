#include <iostream>
#include <limits> // For numeric limits
using namespace std;

int main() {
    // Signed int (default for int)
    signed int a = -10;
    cout << "signed int a = " << a << "\n";
    cout << "  Range: " << numeric_limits<signed int>::min() << " to " 
         << numeric_limits<signed int>::max() << "\n\n";

    // Unsigned int (can only store non-negative values)
    unsigned int b = 10;
    cout << "unsigned int b = " << b << "\n";
    cout << "  Range: 0 to " << numeric_limits<unsigned int>::max() << "\n\n";

    // Short int (uses less memory, typically 16 bits)
    short int c = 32000;
    cout << "short int c = " << c << "\n";
    cout << "  Range: " << numeric_limits<short int>::min() << " to "
         << numeric_limits<short int>::max() << "\n\n";

    // Long int (uses more memory, typically 32 or 64 bits depending on system)
    long int d = 1000000;
    cout << "long int d = " << d << "\n";
    cout << "  Range: " << numeric_limits<long int>::min() << " to "
         << numeric_limits<long int>::max() << "\n\n";

    // Long long int (typically 64 bits, for very large values)
    long long int e = 9000000000000000000;
    cout << "long long int e = " << e << "\n";
    cout << "  Range: " << numeric_limits<long long int>::min() << " to "
         << numeric_limits<long long int>::max() << "\n\n";

    // Unsigned short int
    unsigned short int f = 65000;
    cout << "unsigned short int f = " << f << "\n";
    cout << "  Range: 0 to " << numeric_limits<unsigned short int>::max() << "\n";

    return 0;
}
