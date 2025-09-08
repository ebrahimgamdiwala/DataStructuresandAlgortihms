// Required for input/output operations, the vector data structure,
// and the string data structure.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief Finds the indices of all words in a vector that contain a specific character.
 *
 * @param words A vector of strings to search through.
 * @param x The character to search for within each string.
 * @return vector<int> A vector of integers containing the 0-based indices of the words that contain the character `x`.
 *
 * ## Overall Approach
 * The function uses a straightforward nested loop approach to solve the problem.
 *
 * 1.  **Initialization:** An empty integer vector `ans` is created to store the indices of the matching words.
 * 2.  **Outer Loop (Iterating through words):** The function iterates through the input `words` vector using an index `i`. This loop runs from the first word to the last.
 * 3.  **Inner Loop (Iterating through characters):** For each word, a nested loop iterates through its characters using an index `j`.
 * 4.  **Character Check:** Inside the inner loop, it checks if the character at the current position (`words[i][j]`) is equal to the target character `x`.
 * 5.  **Match Found:** If a match is found:
 * - The index of the current word, `i`, is added to the `ans` vector.
 * - The `break` statement is executed. This is a key optimization that immediately stops the inner loop for the current word, as we only need to know if the character exists at least once. We can then proceed to the next word.
 * 6.  **Return Value:** After the outer loop has checked all the words, the `ans` vector, which now contains all the required indices, is returned.
 *
 * ## Time Complexity: O(N * L)
 * Let N be the number of words in the `words` vector.
 * Let L be the average length of the words.
 * The outer loop runs N times. The inner loop, in the worst case, runs L times for each word.
 * Therefore, the total time complexity is O(N * L).
 *
 * ## Space Complexity: O(K) or O(N)
 * The space required is primarily for the `ans` vector. Let K be the number of words that contain the character `x`. The space complexity is O(K).
 * In the worst-case scenario, all N words contain the character, so the space complexity becomes O(N).
 * If we do not consider the space used for the return value (output), the auxiliary space complexity is O(1).
 */
vector<int> findWordsContaining(vector<string>& words, char x) {
    // 'ans' will store the indices of the words that contain the character 'x'.
    vector<int> ans;

    // The outer loop iterates through each word in the input vector 'words'.
    // 'i' represents the index of the current word.
    for (int i = 0; i < words.size(); i++) {
        // The inner loop iterates through each character of the current word 'words[i]'.
        // 'j' represents the index of the current character.
        for (int j = 0; j < words[i].size(); j++) {
            // Check if the current character matches the target character 'x'.
            if (words[i][j] == x) {
                // If a match is found, add the index of the word 'i' to our answer vector.
                ans.push_back(i);
                // We found the character, so we can stop searching in this word.
                // The 'break' exits the inner loop and continues with the next word in the outer loop.
                break;
            }
        }
    }
    // Return the vector of indices.
    return ans;
}

// Helper function to print a vector of integers for easy verification.
void printVector(const vector<int>& vec) {
    if (vec.empty()) {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    // --- Test Case 1 ---
    vector<string> words1 = {"leetcode", "win", "loops", "success"};
    char x1 = 'e';
    cout << "Words: [\"leetcode\", \"win\", \"loops\", \"success\"], Char: '" << x1 << "'" << endl;
    vector<int> result1 = findWordsContaining(words1, x1);
    cout << "Resulting indices: ";
    printVector(result1); // Expected: [0, 3]
    cout << "--------------------" << endl;

    // --- Test Case 2 ---
    vector<string> words2 = {"abc", "bcd", "aaaa", "cbc"};
    char x2 = 'a';
    cout << "Words: [\"abc\", \"bcd\", \"aaaa\", \"cbc\"], Char: '" << x2 << "'" << endl;
    vector<int> result2 = findWordsContaining(words2, x2);
    cout << "Resulting indices: ";
    printVector(result2); // Expected: [0, 2]
    cout << "--------------------" << endl;

    // --- Test Case 3 ---
    vector<string> words3 = {"hello", "world"};
    char x3 = 'z';
    cout << "Words: [\"hello\", \"world\"], Char: '" << x3 << "'" << endl;
    vector<int> result3 = findWordsContaining(words3, x3);
    cout << "Resulting indices: ";
    printVector(result3); // Expected: []
    cout << "--------------------" << endl;

    return 0;
}
