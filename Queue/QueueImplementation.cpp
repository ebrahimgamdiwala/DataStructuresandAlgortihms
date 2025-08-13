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

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(int val)
    {
        Node *newNode = new Node(val);

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {

            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue()
    {
        if (front == rear)
        {
            delete front;
            front = rear = nullptr;
        }
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        else
        {

            Node *temp = front;
            front = front->next;
            temp->next = nullptr;
            delete temp;
        }
    }
    int frontElement()
    {
        if (isEmpty())
        {
            cout << "Queue is empty";
            return -1;
        }
        return front->data;
    }
    void printQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = front;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};
int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.printQueue();
    q.dequeue();
    q.dequeue();
    q.printQueue();
    cout << "The element at the front of the queue is : " << q.frontElement();

    return 0;
}