#include <iostream>
#include <vector>

using namespace std;

class Stack
{
    vector<int> v;
    int top = -1;

public:
    void push(int val)
    {
        v.push_back(val);
        top++;
    }
    int pop()
    {
        if (top != -1)
        {
            int poppedVal = v[top];
            v.pop_back();
            top--;
            return poppedVal;
        }

        cout << "Stack Underflow" << endl;
        return -1;
    }
    int stackTop()
    {
        if (top != -1)
        {
            return v[top];
        }

        return -1;
    }
    void printStack()
    {
        cout << "Elements of the stack : " << endl;
        for (int i = top; i >=0; i--)
        {
            cout << v[i] << endl;
        }
    }
    bool isEmpty(){
        return v.size() == 0;
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
    cout << "Is the stack empty : " << (s.isEmpty()? "Yes" : "No");

    return 0;
}