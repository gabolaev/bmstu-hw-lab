#include <iostream>
#include <cassert>

#define STANDART_CAPACITY 20
#define CAPACITY_GROWTH 2

struct athlet {
    int weight;
    int force;

    athlet(int inputWeight, int inputForce) : weight(inputWeight), force(inputForce) {};

    athlet() : weight(0), force(0) {};

    bool operator<(const athlet &b) const {
        return (this->weight < b.weight) || ((this->weight == b.weight) && (this->force < b.force));
    };
};


template<class T>
class athletSpecialVector {

private:
    unsigned int size;
    unsigned int capacity;
    T *arr;

public:
    explicit athletSpecialVector(unsigned int customCapacity);

    explicit athletSpecialVector() : athletSpecialVector(STANDART_CAPACITY) {};

    ~athletSpecialVector() { free(arr); };

    int partition(int from, int to);

    void qsort(int left, int right);

    void updateBuffer();

    void push_back(const T &value);

    void pop_back();

    unsigned int calculate();

    void display();

    int length() { return size; }


    T &operator[](unsigned int index) {
        assert(index <= size);
        return arr[index];
    }




};

template<class T>
int athletSpecialVector<T>::partition(int from, int to) {

    int wall = from;

    for (int i = from; i < to; i++) {
        if (arr[i] < arr[to]) {
            std::swap(arr[i], arr[wall]);
            wall++;
        }
    }
    std::swap(arr[to], arr[wall]);
    return wall;

}

template<class T>
void athletSpecialVector<T>::qsort(int left, int right) {

    if (left < right) {
        int wall = partition(left, right);
        qsort(left, wall - 1);
        qsort(wall + 1, right);
    }
}

template<class T>
athletSpecialVector<T>::athletSpecialVector(unsigned int customCapacity) : capacity(customCapacity), size(0) {
    arr = (T *) malloc(capacity * sizeof(T));
}

template<class T>
void athletSpecialVector<T>::display() {
    for (int i = 0; i < size; ++i) {
        std::cout << std::endl << arr[i].weight << " " << arr[i].force << " ";
    }
    std::cout << std::endl;
}

template<class T>
void athletSpecialVector<T>::updateBuffer() {
    auto temp = arr;
    arr = (T *) malloc(capacity * sizeof(T));
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }

    delete[] temp;
}

template<class T>
void athletSpecialVector<T>::push_back(const T &value) {

    if (size + 1 == capacity) {
        capacity *= CAPACITY_GROWTH;
        updateBuffer();
    }
    arr[size] = value;
    size++;
}

template<class T>
void athletSpecialVector<T>::pop_back() {
    assert(size > 0);
    size--;
    if ((capacity > STANDART_CAPACITY) && (size < (capacity / CAPACITY_GROWTH))) {
        capacity >>= 1;
        updateBuffer();
    }
}

template<class T>
unsigned int athletSpecialVector<T>::calculate() {

    unsigned int result = 0, nowWeight = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i].force >= nowWeight) {
            nowWeight += arr[i].weight;
            ++result;
        }
    }

    return result;
}


int main() {

    athletSpecialVector<athlet> circus;
    circus.push_back({});

    while (std::cin >> circus[circus.length() - 1].weight >> circus[circus.length() - 1].force) {
        circus.push_back({});
    }
    circus.pop_back();

    circus.qsort(0, static_cast<unsigned int>(circus.length() - 1));
    std::cout << circus.calculate();

    return 0;
}