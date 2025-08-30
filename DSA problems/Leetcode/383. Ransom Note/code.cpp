// Required for input/output, strings, and the unordered_map data structure.
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * @brief Determines if a ransom note can be constructed from the characters in a magazine.
 *
 * @param ransomNote A string representing the desired ransom note.
 * @param magazine A string representing the available characters.
 * @return bool True if the ransom note can be constructed, false otherwise.
 *
 * ## Overall Approach
 * The problem asks if we have enough of each specific character in the `magazine` to build the
 * `ransomNote`. The most efficient way to solve this is to count the frequency of each character
 * available in the `magazine`.
 *
 * 1.  **Frequency Counting:** We first iterate through the `magazine` string and store the count
 * of each character in a hash map (`unordered_map`). This gives us an inventory of all
 * available letters.
 * 2.  **Verification:** Next, we iterate through the `ransomNote`. For each character required by
 * the note, we check our inventory (the hash map).
 * - If the character is available (its count is greater than 0), we "use" one by
 * decrementing its count in the map.
 * - If the character is not available (its count is 0 or it's not in the map), we immediately
 * know the note cannot be constructed, so we return `false`.
 * 3.  **Conclusion:** If we successfully complete the loop through the `ransomNote` without running
 * out of any required characters, it means the note can be constructed, and we return `true`.
 *
 * ## Time Complexity: O(M + N)
 * Where M is the length of the `magazine` and N is the length of the `ransomNote`.
 * We perform one pass through the magazine to build the map (O(M)) and one pass through
 * the ransom note to check the characters (O(N)).
 *
 * ## Space Complexity: O(k)
 * Where k is the number of unique characters in the `magazine`. The space is used to store
 * the frequency map. In the worst case, k can be up to the size of the character set (e.g., 26 for
 * lowercase English letters, 52 for mixed case, etc.), which is considered constant space, O(1).
 */
bool canConstruct(string ransomNote, string magazine) {
    // Create a hash map to store the frequency of characters in the magazine.
    unordered_map<char, int> m;

    // Populate the map by counting each character in the magazine.
    for (char c : magazine) {
        m[c]++;
    }

    // Iterate through the ransom note to see if we have enough characters.
    for (char c : ransomNote) {
        // Check the current count of character 'c' *before* decrementing.
        // If the count is 0 or the character doesn't exist in the map,
        // we don't have enough letters.
        if (m[c] <= 0) {
            return false;
        }
        // If we have the character, "use" it by decrementing its count.
        m[c]--;
    }

    // If we successfully iterated through the entire ransom note, it means
    // we had enough of every required character.
    return true;
}

int main() {
    // --- Test Case 1: Should return false ---
    string ransomNote1 = "a";
    string magazine1 = "b";
    cout << "Can \"" << ransomNote1 << "\" be constructed from \"" << magazine1 << "\"? ";
    cout << (canConstruct(ransomNote1, magazine1) ? "Yes" : "No") << endl; // Expected: No

    // --- Test Case 2: Should return false ---
    string ransomNote2 = "aa";
    string magazine2 = "ab";
    cout << "Can \"" << ransomNote2 << "\" be constructed from \"" << magazine2 << "\"? ";
    cout << (canConstruct(ransomNote2, magazine2) ? "Yes" : "No") << endl; // Expected: No

    // --- Test Case 3: Should return true ---
    string ransomNote3 = "aa";
    string magazine3 = "aab";
    cout << "Can \"" << ransomNote3 << "\" be constructed from \"" << magazine3 << "\"? ";
    cout << (canConstruct(ransomNote3, magazine3) ? "Yes" : "No") << endl; // Expected: Yes

    return 0;
}
