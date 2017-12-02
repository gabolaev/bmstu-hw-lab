#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>

#define STANDART_CAPACITY 5


class Compare{
public:
    bool operator()(const uint32_t &a, const uint32_t &b){
        return a < b;
    }
};

template<class T>
class Stack {

private:

    uint32_t head = 0;
    uint32_t capacity = STANDART_CAPACITY;

    T *arr;

public:

    Stack();

    ~Stack() { delete arr; }

    const T &push(const T &value);

    T pop();

    uint32_t length() {
        return head;
    };

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
const T &Stack<T>::push(const T &value) {

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

    assert(length() != 0);

    if ((capacity > STANDART_CAPACITY) && (head < capacity / 2)) {
        capacity /= 2;
        arr = (T *) realloc(arr, capacity * sizeof(T));
    }
    head--;
    return arr[head];
}

template<class T>
void Stack<T>::display() {

    for (uint32_t i = 0; i < head; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;

}


template<class TYPE, class COMPARATOR>
uint32_t getMedian(TYPE &arr, uint32_t &left, uint32_t &right, COMPARATOR cmp) {

    uint32_t mid = left + (right - left) / 2;

    if (cmp(arr[left], arr[mid])) {

        if (cmp(arr[right], arr[left])) return left;
        else if (cmp(arr[right], arr[mid])) return right;
        return mid;

    } else {

        if (cmp(arr[right], arr[mid])) return mid;
        else if (cmp(arr[right], arr[left])) return right;
        return left;

    }
};

template<class T, class COMPARATOR>
void insertionSort(T *arr, uint32_t &from, uint32_t &to, COMPARATOR cmp) {

    for (uint32_t i = from; i <= to; ++i) {
        uint32_t tempPosition = i;
        T nowValue = arr[i];
        while ((tempPosition > 0) && (cmp(nowValue, arr[tempPosition - 1]))) {
            arr[tempPosition] = arr[tempPosition - 1];
            --tempPosition;
        }
        arr[tempPosition] = nowValue;
    }
}


template<class TYPE, class COMPARATOR>
uint32_t partition(TYPE *arr, uint32_t &from, uint32_t &to, COMPARATOR cmp) {
    uint32_t median = getMedian(arr, from, to, cmp), wall = to;

    std::swap(arr[median], arr[from]);

    for (uint32_t nowPos = to; nowPos > from; --nowPos)
        if (cmp(arr[from], arr[nowPos]))
            std::swap(arr[nowPos], arr[wall--]);

    std::swap(arr[from], arr[wall]);
    return wall;
};

template<class TYPE, class COMPARATOR>
void quickestSort(TYPE *arr, uint32_t from, uint32_t to, COMPARATOR cmp) {

    Stack<std::pair<uint32_t, uint32_t>> toSort;
    toSort.push({from, to});

    while (toSort.length()) {

        auto nowSortPart = toSort.pop();

        if (nowSortPart.second - nowSortPart.first < 4) {
            insertionSort(arr, nowSortPart.first, nowSortPart.second, cmp);
        } else {
            auto wall = partition(arr, nowSortPart.first, nowSortPart.second, cmp);
            if (wall > nowSortPart.first)
                toSort.push({nowSortPart.first, wall - 1});

            if (wall < nowSortPart.second)
                toSort.push({wall + 1, nowSortPart.second});
        }
    }
};

int main() {

    std::vector<uint32_t> array;

    uint32_t inputValue;
    while(std::cin >> inputValue){
        array.push_back(inputValue);
    }

    quickestSort(array.data(), 0, array.size()-1, Compare());

    for(uint32_t i = 9; i < array.size(); i += 10)
        std::cout << array[i] << " ";

}