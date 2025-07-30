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
        next = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    // Time Complexity: O(1)
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
        return;
    }

    // Time Complexity: O(1)
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }

        // Without tail pointer :
        // Node *temp = head;
        // while (temp->next != NULL)
        // {
        //     temp = temp->next;
        // }
        // temp->next = newNode;
        // tail = newNode;

        // With tail pointer :
        tail->next = newNode;
        tail = newNode;
        return;
    }

    // Time Complexity: O(pos)
    void insert_at_pos(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid position";
            return;
        }
        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == NULL)
        {
            tail = newNode;
        }

        return;
    }

    // Time Complexity: O(1)
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty" << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;

        return;
    }

    // Time Complexity: O(n)
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty" << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete tail;
        temp->next = NULL;
        tail = temp;
        return;
    }

    // Time Complexity: O(n)
    int searchLL(int key)
    {
        Node *temp = head;
        int pos = 0;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return pos;
            }
            pos++;
            temp = temp->next;
        }
        return -1;
    }

    // Time Complexity: O(n)
    void printLL()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.pop_back();
    ll.insert_at_pos(10, 1);
    ll.printLL();
    cout << "Key found at index : " << ll.searchLL(3) << endl;
    return 0;
}
