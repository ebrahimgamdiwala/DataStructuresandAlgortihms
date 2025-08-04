#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class CircularLL
{
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    CircularLL()
    {
        head = tail = nullptr;
    }

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
            tail->next = newNode;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            head = newNode;
        }
    }

    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
            tail->next = newNode;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtHead()
    {
        if (head == nullptr)
        {
            cout << "Linked List is empty";
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            tail->next = head;
            temp->next = nullptr;
            delete temp;
        }
    }

    void deleteAtTail()
    {
        if (head == nullptr)
        {
            cout << "Linked List is empty";
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = tail;
            Node *prev = head;
            while (prev->next != tail)
            {
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = nullptr;
            delete temp;
        }
    }

    void printCLL()
    {
        Node *temp = head;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << temp->data << endl;
    }
};

int main()
{
    CircularLL cll;
    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtHead(3);
    cll.insertAtHead(4);
    cll.insertAtTail(5);
    cll.printCLL();
    cll.deleteAtHead();
    cll.printCLL();
    cll.deleteAtTail();
    cll.printCLL();
    return 0;
}