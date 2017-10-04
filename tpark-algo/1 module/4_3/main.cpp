//testing unlikely optimization
#include <iostream>

#define unlikely(expr) __builtin_expect(!!(expr),0)
#define likely(expr) __builtin_expect(!!(expr),1)
#define STANDART_CAPACITY 20
#define PUSH_BACK 3
#define POP_FRONT 2

template<class T>
class Stack {

private:

    unsigned int head = 0;
    int capacity = STANDART_CAPACITY;

    T *arr;

public:

    Stack();
    ~Stack() { delete arr; }

    T push(const T &value);
    T pop();

    unsigned int length() { return head; };
    void display();
    void clear();
};

template<class T>
void Stack<T>::clear() {
    while (length())
        pop();
}

template<class T>
Stack<T>::Stack() {
    arr = (T *) malloc(capacity * sizeof(T));
}

template<class T>
T Stack<T>::push(const T &value) {

    if (head == capacity - 1) {
        capacity *= 2;
        arr = (T *) realloc(arr, capacity * sizeof(T));
    }
    arr[head] = value;
    head++;
    return arr[head - 1];

}

template<class T>
T Stack<T>::pop() {

    if (unlikely(length() == 0)) {
        return -1;
    } else {
        if ((capacity > STANDART_CAPACITY) && (head < capacity / 2)) {
            capacity /= 2;
            arr = (T *) realloc(arr, capacity * sizeof(T));
        }
        head--;
        return arr[head];
    }
}

template<class T>
void Stack<T>::display() {

    for (int i = 0; i < head; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;

}

template<class T>
class Queue {

private:

    Stack<T> toWrite;
    Stack<T> toRead;

    void transfer();

public:

    Queue() {};

    ~Queue() {
        toRead.clear();
        toWrite.clear();
    }

    T pushBack(const T &value);

    T popFront();

};

template<class T>
T Queue<T>::pushBack(const T &value) {
    return toWrite.push(value);
}

template<class T>
T Queue<T>::popFront() {

    if (!toRead.length())
        transfer();
    return toRead.pop();

}

template<class T>
void Queue<T>::transfer() {
    while (toWrite.length())
        toRead.push(toWrite.pop());
}

template<class T>
void commandsParser(int command, int data, int &result, Queue<T> &queue) {

    switch (command) {
        case PUSH_BACK: {
            result *= (queue.pushBack(data) == data);
            break;
        }
        case POP_FRONT: {
            result *= (queue.popFront() == data);
            break;
        }
        default: {
            std::cout << "FUCK YOU" << std::endl;
        }
    }
}

int main() {

    Queue<int> queue;
    int n;
    std::cin >> n;

    int command, data, result = 1;

    for (; n > 0; n--) {
        std::cin >> command >> data;
        commandsParser(command, data, result, queue);
    }

    std::cout << (result ? "YES" : "NO") << std::endl;

    return 0;
}