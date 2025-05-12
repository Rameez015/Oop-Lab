#include <iostream>
#include <exception>
using namespace std;

class QueueOverflowException : public exception {};
class QueueUnderflowException : public exception {};

template <typename T>
class Queue {
    T* arr;
    int size, front, rear, count;
public:
    Queue(int s) : size(s), front(0), rear(-1), count(0) {
        arr = new T[size];
    }
    void enqueue(T val) {
        if (count == size) {
            throw QueueOverflowException();
        }
        rear = (rear + 1) % size;
        arr[rear] = val;
        count++;
    }
    T dequeue() {
        if (count == 0) {
            throw QueueUnderflowException();
        }
        T val = arr[front];
        front = (front + 1) % size;
        count--;
        return val;
    }
};

int main() {
    Queue<int> q(1);
    try {
        cout << "Attempting to enqueue to a full queue..." << endl;
        q.enqueue(10);
        q.enqueue(20);
    } catch (QueueOverflowException& e) {
        cout << "Caught QueueOverflowException - what(): std::exception" << endl;
    }

    try {
        cout << "Attempting to dequeue from an empty queue..." << endl;
        q.dequeue();
        q.dequeue();
    } catch (QueueUnderflowException& e) {
        cout << "Caught QueueUnderflowException - what(): std::exception" << endl;
    }

    return 0;
}