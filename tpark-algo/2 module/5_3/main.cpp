#include <iostream>
#include <vector>

class Compare {
public:
    bool operator()(const int &a, const int &b){
        return a > b;
    }
};

template<class T, class CMP>
void mergeParts(T *array, int begin, int middle, int end, CMP cmp, int64_t &counter) {

    int leftPartSize = middle - begin + 1;
    int rightPartSize = end - middle;

    auto leftPart = new T[leftPartSize],rightPart = new T[rightPartSize];

    for (auto i = 0; i < leftPartSize; ++i)
        leftPart[i] = array[begin + i];

    for (auto i = 0; i < rightPartSize; ++i)
        rightPart[i] = array[middle + i + 1];

    int resultArrayIter = end;
    --leftPartSize;
    --rightPartSize;

    for (;leftPartSize >= 0 && rightPartSize >= 0; resultArrayIter--) {
        if (cmp(leftPart[leftPartSize], rightPart[rightPartSize])) {
            array[resultArrayIter] = leftPart[leftPartSize--];
            counter += rightPartSize + 1;
        } else {
            array[resultArrayIter] = rightPart[rightPartSize--];
        }

    }

    while(leftPartSize >= 0)
        array[resultArrayIter--] = leftPart[leftPartSize--];

    while(rightPartSize >= 0)
        array[resultArrayIter--] = rightPart[rightPartSize--];

    delete[] leftPart;
    delete[] rightPart;
};


template<class T, class CMP>
void mergeSort(T *array, int left, int right, CMP cmp, int64_t &counter) {

    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle, cmp, counter);
        mergeSort(array, middle + 1, right, cmp, counter);
        mergeParts(array, left, middle, right, cmp, counter);
    }

};

int main() {

    std::vector<int> array;
    int value;
    int64_t counter = 0;
    while(std::cin >> value) {
        array.push_back(value);
    }

    mergeSort(array.data(), 0, static_cast<int>(array.size() - 1), Compare(), counter);
    printf("%lld", counter);
    return 0;
}