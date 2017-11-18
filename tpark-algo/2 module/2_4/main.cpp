//попытка сделать красивее
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>


struct digit {
    int value;
    int arrayIndex;

    digit(int arrIndex) : arrayIndex(arrIndex), value(0){};
};

class DigitsCompare {
public:
    bool operator()(const digit *a, const digit *b){
        return a->value < b->value;
    }
};


template<class T, class Comparator>
class Heap {
public:

    Heap(Comparator cmp_in) : cmp(cmp_in){};

    explicit Heap(T *inputArray, Comparator cmp);

    void display();

    T extract(int index);

    const T& getMax() const {
        return array[0];
    }

    void insert(const T &elem);
    ~Heap();

private:

    void buildHeap(int index);

    Comparator cmp;

    std::vector<T> array;

    void siftUp(int index);

    void siftDown(int index);

};

template<class T, class Comparator>
Heap<T, Comparator>::Heap(T *inputArray, Comparator cmp) {

    this->cmp = &cmp;
    array = inputArray;
    buildHeap(static_cast<int>((array.size() / 2) - 1));
}

template<class T, class Comparator>
void Heap<T, Comparator>::siftDown(int index) {

    int leftChildIndex = index * 2 + 1;
    int rightChildIndex = index * 2 + 2;
    int max = index;

    if (leftChildIndex < array.size() && cmp(array[index], array[leftChildIndex]))
        max = leftChildIndex;

    if (rightChildIndex < array.size() && cmp(array[max], array[rightChildIndex]))
        max = rightChildIndex;

    if (max != index) {
        std::swap(array[max], array[index]);
        siftDown(max);
    }
}


template<class T, class Comparator>
void Heap<T, Comparator>::siftUp(int index) {

    while (index) {

        int parentIndex = (index - 1) / 2;
        if (cmp(array[index], array[parentIndex])) return;
        std::swap(array[index], array[parentIndex]);
        index = parentIndex;

    }
}

template<class T, class Comparator>
void Heap<T, Comparator>::insert(const T &elem) {

    array.push_back(elem);
    siftUp(array.size() - 1);

}

template<class T, class Comparator>
void Heap<T, Comparator>::buildHeap(int index) {
    for (; index >= 0; --index)
        siftDown(index);
}

template<class T, class Comparator>
Heap<T, Comparator>::~Heap() {
    array.clear();
}

template<class T, class Comparator>
void Heap<T, Comparator>::display() {

    std::cout << std::endl;
    std::for_each(array.begin(), array.end(), [](T &_elem) {
        std::cout << _elem << " ";
    });

}

template<class T, class Comparator>
T Heap<T, Comparator>::extract(int index) {
    assert(index < array.size() && index >= 0);

    T returnValue = array[index];

    std::swap(array[index], array[array.size() - 1]);
    array.pop_back();

    if (index < array.size() - 1) {
        siftDown(index);
    }
    return returnValue;
}

int main() {


    int n, k;
    std::cin >> n;
    std::vector<digit *> arr(n);

    Heap<digit *, DigitsCompare> *heap = new Heap<digit *, DigitsCompare>(DigitsCompare());

    for (int i = 0; i < n; ++i) {
        arr[i] = new digit(i);
        std::cin >> arr[i]->value;
    }

    std::cin >> k;

    for (int i = 0; i < k; ++i) {
        heap->insert(arr[i]);
    }

    for (int i = k; i < n; ++i) {

        while(heap->getMax()->arrayIndex < i-k){
            heap->extract(0);
        }

        std::cout << heap->getMax()->value << " " << std::flush;
        heap->insert(arr[i]);
    }

    while(heap->getMax()->arrayIndex < n-k){
        heap->extract(0);
    }
    std::cout << heap->getMax()->value << " " << std::flush;


    for (auto &elem : arr) {
        delete elem;
    }

    delete heap;

    return 0;

}
