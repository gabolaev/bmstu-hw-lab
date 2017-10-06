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
    void displayReverse();
    T getHead();
    void clear();
};



template <class T>
T Stack<T>::getHead() {
    return arr[head-1];
}

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
        std::cout << arr[i] << std::flush;

    std::cout << std::endl;
}

template<class T>
void Stack<T>::displayReverse() {

    for (int i = head-1; i >= 0; i--)
        std::cout << arr[i] << std::flush;
}

bool itOpener(char ch, char &pair){
    switch (ch){
        case '{': pair = '}'; return true;
        case '}': pair = '{'; return false;
        case '[': pair = ']'; return true;
        case ']': pair = '['; return false;
        case '(': pair = ')'; return true;
        case ')': pair = '('; return false;
        default: return '0';
    }
}

void analyseSeq(std::string &sequence, Stack<char> &end, Stack<char> &begin){

    char pairElement;

    for(auto ch = sequence.begin(); ch != sequence.end(); ch++){
        if(itOpener(*ch, pairElement)){
            end.push(pairElement);
        }else{
            if (!end.length()){
                begin.push(pairElement);
            }else{
                if (end.getHead() == *ch){
                    end.pop();
                }else{
                    sequence = "IMPOSSIBLE";
                    return;
                }
            }
        }
    }
}

int main(){

    Stack<char> stack, begin;

    std::string inputSequence;
    std::getline(std::cin, inputSequence);
    analyseSeq(inputSequence, stack, begin);

    if(inputSequence != "IMPOSSIBLE"){
        begin.displayReverse();
        std::cout << inputSequence;
        stack.displayReverse();
    }else{
        std::cout << inputSequence;
    }
    return 0;
}


























