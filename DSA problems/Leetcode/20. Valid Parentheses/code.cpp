#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a pair of brackets is matching
bool isMatch(char o, char c)
{
    return ((o == '(' && c == ')') || (o == '[' && c == ']') || (o == '{' && c == '}'));
}

// Function to check if the input string has valid brackets
bool isValid(string s)
{
    stack<char> st;

    // Traverse each character in the string
    for (char c : s)
    {
        // If it's an opening bracket, push to the stack
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        // If it's a closing bracket, check for match
        else if (c == ')' || c == ']' || c == '}')
        {
            // If stack is empty, there's no opening bracket to match
            if (st.empty())
            {
                return false;
            }
            else
            {
                // Get the last opening bracket
                char openingParenthesis = st.top();
                st.pop();
                // If it doesn't match, the string is invalid
                if (!isMatch(openingParenthesis, c))
                {
                    return false;
                }
            }
        }
    }

    // If stack is empty, all brackets matched correctly
    return st.empty();
}

int main()
{
    string input = "{[()]}";

    // Output result
    if (isValid(input))
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }

    return 0;
}
