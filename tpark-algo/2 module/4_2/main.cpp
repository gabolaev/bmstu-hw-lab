#include <iostream>
#include <vector>

class Compare {
public:
    bool operator()(const int &a, const int &b) {
        return a < b;
    }
};

template<class TYPE, class COMPARATOR>
uint32_t getMedian(TYPE &arr, uint32_t left, uint32_t right, COMPARATOR cmp) {

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

template<class TYPE, class COMPARATOR>
uint32_t partition(TYPE &arr, uint32_t from, uint32_t to, COMPARATOR cmp) {
    uint32_t median = getMedian(arr, from, to, cmp), wall = to;

    std::swap(arr[median], arr[from]);

    for (int nowPos = to; nowPos > from; --nowPos)
        if (cmp(arr[from], arr[nowPos]))
            std::swap(arr[nowPos], arr[wall--]);

    std::swap(arr[from], arr[wall]);
    return wall;
};

template<class TYPE, class COMPARATOR>
int findKStatistics(TYPE &arr, uint32_t k, COMPARATOR cmp) {
    uint32_t left = 0, right = arr.size()-1;

    while (true) {
        uint32_t mid = partition(arr, left, right, cmp);

        if (mid == k)
            return arr[mid];

        if (k < mid)
            right = mid - 1;
        else
            left = mid + 1;
    }
};


int main() {

    int countOfElements, k, tempInput;
    std::cin >> countOfElements >> k;

    std::vector<int> elements;

    for (; countOfElements > 0; --countOfElements) {
        std::cin >> tempInput;
        elements.push_back(tempInput);
    }

    std::cout << findKStatistics(elements, k, Compare());

    return 0;
}

