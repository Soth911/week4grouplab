#include <iostream>
#include <string>
using namespace std;

#define MAX 10
#define COMPACT_THRESHOLD 0.5

class Queue {
private:
    string data[MAX];
    int front;
    int rear;

public:
    Queue() {
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return rear == MAX;
    }

    void compact() {
        int size = rear - front;
        for (int i = 0; i < size; ++i) {
            data[i] = data[front + i];
        }
        front = 0;
        rear = size;
        cout << "Compaction triggered! Remaining " << size << " students moved.\n";
    }

    void enqueue(const string& name) {
        if (isFull()) {
            if (front > 0 && front >= MAX * COMPACT_THRESHOLD) {
                compact();
            } else {
                cout << "Queue is full! Cannot add " << name << endl;
                return;
            }
        }
        data[rear++] = name;
        cout << name << " joined the line.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! No one to serve.\n";
            return;
        }
        cout << data[front++] << " is being served.\n";
    }

    void printQueue() {
        cout << "\nCurrent queue: ";
        if (isEmpty()) {
            cout << "[empty]\n";
            return;
        }
        for (int i = front; i < rear; ++i) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }
};

