#include <iostream>
using namespace std;

class CircularQueue{
    int *arr;
    int currSize, capacity;
    int f, r;

public:
    CircularQueue(int size){
        capacity = size;
        arr = new int[capacity];
        currSize = 0;
        f = 0;
        r = -1;
    }

    void push(int data){
        if(currSize == capacity){
            cout << "Circular Queue is Full\n";
            return;
        }

        r = (r+1) % capacity;
        arr[r] = data;
        currSize++;
    }

    void pop(){
        if(isEmpty()){
            cout << "Circular Queue is empty\n";
            return;
        }

        f = (f+1) % capacity;
        currSize--;
    }

    int front(){
        if(isEmpty()){
            cout << "Circular Queue is empty\n";
            return -1;
        }
        return arr[f];
    }

    bool isEmpty(){
        return currSize == 0;
    }

    void printQueue(){
        if(isEmpty()){
            cout << "Circular Queue is empty\n";
            return;
        }

        int i = f;
        while(true){
            cout << arr[i] << " ";
            if(i == r) break;
            i = (i+1) % capacity;
        }
        cout << endl;
    }
};
int main(){
    CircularQueue cq(5);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.push(5);
    cq.push(6);  // This should show "Circular Queue is Full"
    cq.printQueue();

    cout << "Front element is: " << cq.front() << endl;

    
    cq.pop();
    
    cq.printQueue();

    cout << "Front element is: " << cq.front() << endl;

    return 0;
}