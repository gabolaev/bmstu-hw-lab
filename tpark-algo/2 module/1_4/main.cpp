#include <iostream>
#include <vector>
#include <algorithm>

class stringIsLess
{
public:
    bool operator()(const std::string l, const std::string r) {
        int i = 0;
        for (; l[i] == r[i]; ++i);
        return l[i] < r[i];
    }
};

template <class T, class Compare>
void insertionSort(T* arr, int from, int to, Compare cmp){

    for(int i = from; i <= to; ++i){
        int tempPosition = i;
        T nowValue = arr[i];
        while((tempPosition > 0) && (cmp(nowValue, arr[tempPosition-1]))){
            arr[tempPosition] = arr[tempPosition-1];
            --tempPosition;
        }
        arr[tempPosition] = nowValue;
    }
}


int main() {

    std::vector<std::string> inputs;

    int n;
    std::cin >> n;

    std::string input;
    for(; n > 0; --n){
        std::cin >> input;
        inputs.push_back(input);
    }

    insertionSort(&inputs, 0, inputs.size(), stringIsLess());

    std::for_each(inputs.begin(), inputs.end(), [](std::string _i){
       std::cout << _i <<  std::endl;
    });
}
