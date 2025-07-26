#include <iostream>

int reverse(int x) {
    if (x >= INT_MAX || x <= INT_MIN) {
        return 0;
    }
    int rev = 0;
    bool isNegative = false;
    if (x < 0) {
        x = -x;
        isNegative = true;
    }
    while (x != 0) {
        int dig = x % 10;
        if ((rev > INT_MAX / 10) || (rev < INT_MIN / 10)) {
            return 0;
        }
        rev = rev * 10 + dig;
        x /= 10;
    }
    if (isNegative) {
        rev = -rev;
    }
    return rev;
}

int main() {
    int input = -12345;
    int result = reverse(input);
    std::cout << "Reversed: " << result << std::endl;
    return 0;
}
