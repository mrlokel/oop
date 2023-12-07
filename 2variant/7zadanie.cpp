#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

class List {
protected:
    int size;
public:
    List() : size(0) {} // Конструктор по умолчанию

    virtual void add(int value) = 0;

    virtual int remove() = 0;

    int getSize() const {
        return size;
    }
};

class Stack : public List {
private:
    static const int MAX_SIZE = 100;
    int elements[MAX_SIZE];
    int top; // Вершина стека
public:
    Stack() : top(-1) {} // Конструктор по умолчанию

    void add(int value) override {
        if (top >= MAX_SIZE - 1) {
            throw overflow_error("Stack overflow");
        }
        elements[++top] = value;
        size++;
    }

    int remove() override {
        if (top < 0) {
            throw underflow_error("Stack underflow");
        }
        size--;
        return elements[top--];
    }
};

class Queue : public List {
private:
    static const int MAX_SIZE = 100;
    int elements[MAX_SIZE];
    int front, rear;
public:
    Queue() : front(0), rear(0) {} // Конструктор по умолчанию

    void add(int value) override {
        if ((rear + 1) % MAX_SIZE == front) {
            throw overflow_error("Queue overflow");
        }
        elements[rear] = value;
        rear = (rear + 1) % MAX_SIZE;
        size++;
    }

    int remove() override {
        if (front == rear) {
            throw underflow_error("Queue underflow");
        }
        int value = elements[front];
        front = (front + 1) % MAX_SIZE;
        size--;
        return value;
    }
};

int main() {
    Stack stack;
    Queue queue;

    srand(time(nullptr));
    for (int i = 0; i < 5; ++i) {
        int value = rand() % 100;
        try {
            stack.add(value);
            queue.add(value);
        } catch (const exception &e) {
            cerr << "Exception occurred: " << e.what() << endl;
        }
    }

    cout << "Stack size: " << stack.getSize() << endl;
    while (stack.getSize() > 0) {
        cout << "Stack element: " << stack.remove() << endl;
    }

    cout << "Queue size: " << queue.getSize() << endl;
    while (queue.getSize() > 0) {
        cout << "Queue element: " << queue.remove() << endl;
    }

    return 0;
}
