// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the queue data structure.
#include <queue>
// Required for using the string data structure.
#include <string>
// Required for using the unordered_map (hash map) data structure.
#include <unordered_map>

using namespace std;

/**
 * @brief Finds the index of the first non-repeating character in a string.
 *
 * @param s The input string.
 * @return int The index of the first unique character, or -1 if none exists.
 *
 * ## Overall Approach
 * This function uses a hash map for frequency counting and a queue to preserve the order
 * of characters as they appear.
 *
 * 1.  **First Pass:** The code iterates through the string once. It uses a hash map (`m`)
 * to count the frequency of each character. Simultaneously, it uses a queue (`q`) to
 * store the *index* of each character the *first time* it is encountered. This queue
 * maintains a list of potential candidates for the first unique character in their
 * original order.
 *
 * 2.  **Filtering:** After the first pass, the queue contains indices of all characters
 * that appeared at least once. The second `while` loop then "cleans" the front of the
 * queue. It removes indices of characters whose final frequency count in the map is
 * greater than 1.
 *
 * 3.  **Result:** The loop stops as soon as it finds an index at the front of the queue
 * that points to a character with a frequency of 1. This index is the answer. If the
 * queue becomes empty, it means no unique character was found.
 *
 * ## Time Complexity: O(N)
 * The algorithm iterates through the string of length N once to populate the map and queue.
 * The subsequent while loop also processes each element in the queue at most once. Therefore,
 * the time complexity is linear with respect to the length of the string.
 *
 * ## Space Complexity: O(K)
 * The space is determined by the hash map and the queue. In the worst case, both will store
 * an entry for each unique character in the string. If K is the number of unique characters,
 * the space complexity is O(K). For a fixed character set (like ASCII or 26 lowercase
 * English letters), this can be considered O(1).
 */
int firstUniqChar(string s) {
    // `m` stores the frequency count of each character.
    unordered_map<char, int> m;
    // `q` stores the indices of characters that are potential candidates for being the first unique character.
    queue<int> q;

    // STEP 1: Iterate through the string to populate the map and queue.
    for (int i = 0; i < s.size(); i++) {
        // If we are seeing this character for the first time...
        if (m.find(s[i]) == m.end()) {
            // ...add its index to the queue of potential candidates.
            q.push(i);
        }
        // Increment the frequency count for the character.
        m[s[i]]++;
    }

    // STEP 2: Filter the queue to find the first true unique character.
    // While the queue is not empty AND the character at the index at the front of the queue
    // has a frequency greater than 1...
    while (!q.empty() && m[s[q.front()]] > 1) {
        // ...it's a duplicate, so pop its index from the queue.
        q.pop();
    }

    // STEP 3: Return the result.
    // If the queue is empty, it means all characters were duplicates.
    // Otherwise, the index at the front of the queue is our answer.
    return q.empty() ? -1 : q.front();
}

int main() {
    string s1 = "leetcode";
    cout << "String: \"" << s1 << "\"" << endl;
    cout << "First unique character index: " << firstUniqChar(s1) << endl; // Expected: 0
    cout << "---" << endl;

    string s2 = "loveleetcode";
    cout << "String: \"" << s2 << "\"" << endl;
    cout << "First unique character index: " << firstUniqChar(s2) << endl; // Expected: 2
    cout << "---" << endl;

    string s3 = "aabb";
    cout << "String: \"" << s3 << "\"" << endl;
    cout << "First unique character index: " << firstUniqChar(s3) << endl; // Expected: -1
    cout << "---" << endl;

    return 0;
}
