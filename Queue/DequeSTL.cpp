#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(4);

    cout << "Front of the queue is : " << dq.front() << endl;
    cout << "Back of the queue is : " << dq.back() << endl;

    dq.pop_back();

    cout << "Front of the queue is : " << dq.front() << endl;
    cout << "Back of the queue is : " << dq.back() << endl;

    return 0;
}