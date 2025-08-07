#include <iostream>
#include <list>

using namespace std;

class Stack
{
    list<int> lst;

public:
    void push(int val)
    {
        lst.push_back(val);
    }
    int pop()
    {
        if (!lst.empty())
        {
            int val = lst.back();
            lst.pop_back();
            return val;
        }
        cout << "Stack Underflow" << endl;
        return -1;
    }
    int stackTop()
    {
        if (!lst.empty())
        {
            return lst.back();
        }
        return -1;
    }
    void printStack()
    {
        cout << "Elements of the stack : " << endl;
        for (auto it = lst.rbegin(); it != lst.rend(); ++it)
        {
            cout << *it << endl;
        }
    }
    bool isEmpty()
    {
        return lst.empty();
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.printStack();
    s.pop();
    s.pop();
    s.printStack();
    cout << "The top of the stack is : " << s.stackTop() << endl;
    cout << "Is the stack empty : " << (s.isEmpty() ? "Yes" : "No");

    return 0;
}
