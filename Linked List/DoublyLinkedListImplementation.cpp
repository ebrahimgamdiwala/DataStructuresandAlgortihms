#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
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
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void printDLL()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "Linked List is empty";
        }

        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        temp->next = nullptr;
        delete temp;
    }
    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "Linked List is empty";
        }
        Node *temp = tail;
        tail = tail->prev;
        if (tail != nullptr)
        {
            tail->next = nullptr;
        }
        tail->prev = nullptr;
        delete temp;
    }
};
int main()
{
    DoublyLL dll;
    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    dll.push_front(4);
    dll.push_front(5);
    dll.push_back(10);
    dll.pop_front();
    dll.pop_back();
    dll.printDLL();
    return 0;
}