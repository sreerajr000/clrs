#include <bits/stdc++.h>

using namespace std;

class Queue {
    private:
    vector<int> q;
    int tail, head;

    public:
    Queue(int size) {
        q.resize(size);
        tail = 0;
        head = 0;
    }

    void enqueue(int x) {
        q[tail] = x;
        if(tail == q.size() - 1) {
            tail = 0;
        }
        else {
            ++tail;
        }
    }

    int dequeue() {
        int x = q[head];
        if(head == q.size() - 1) {
            head = 0;
        }
        else {
            ++head;
        }
        return x;
    }
};

int main() {
    Queue q(5);
    q.enqueue(6);
    q.enqueue(4);
    q.enqueue(8);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(2);
    cout << q.dequeue() << endl;
    return 0;
}