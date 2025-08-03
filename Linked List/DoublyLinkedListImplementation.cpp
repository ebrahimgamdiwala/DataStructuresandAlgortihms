#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        next = prev = nullptr;
    }
};

class DoublyLL
{
    Node *head;
    Node *tail;

public:
    DoublyLL()
    {
        head = tail = nullptr;
    }
};
int main()
{

    return 0;
}