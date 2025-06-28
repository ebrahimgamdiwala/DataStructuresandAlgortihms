#include <iostream>
#include <vector>

using namespace std;

/*
  Problem: Find the element that appears only once in an array where every other element appears exactly twice.

  Example Input: {4, 1, 2, 1, 2}
  Expected Output: 4

  Explanation:
  ------------------------------
  We use the XOR (^) operation to solve this problem efficiently.

  Properties of XOR:
  1. a ^ a = 0      → XOR of a number with itself is 0.
  2. a ^ 0 = a      → XOR of a number with 0 is the number itself.
  3. XOR is associative and commutative:
     So, a ^ b ^ a = a ^ a ^ b = 0 ^ b = b

  Applying this to our problem:
  - If every element appears twice except one, XORing all elements will cancel out the ones that appear twice.
  - Only the unique (non-repeating) element will remain.

  Time Complexity: O(n)
  Space Complexity: O(1)
*/

int main() {
    // Sample hardcoded input
    vector<int> nums = {4, 1, 2, 1, 2};

    int ans = 0;

    // XOR all elements in the array
    for (int i : nums) {
        ans ^= i;  // cancel out duplicates
    }

    // The remaining value is the unique number
    cout << "The single number is: " << ans << endl;

    return 0;
}
