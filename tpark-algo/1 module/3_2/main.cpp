#include <iostream>

int binarySearch(const int *arr, int left, int right){

    while(left <= right){

        int middle = left + (right-left)/2;

        if (((arr[middle] > arr[middle-1]) && (arr[middle] > arr[middle+1])) || left == right){
            return middle;
        }else{
            if ((arr[middle] < arr[middle-1]) && (arr[middle] > arr[middle+1])){
                right = middle-1;
            }else{
                left = middle+1;
            }
        }
    }
    return 0;
}

int findTheBend(int * arr, int n){

    int powerOfTwo = 1;
    while((powerOfTwo < n) && (arr[powerOfTwo] >= arr[powerOfTwo - 1]) && (arr[powerOfTwo] <= arr[powerOfTwo + 1]))
        powerOfTwo *= 2;

    int left = powerOfTwo/2;

    if(powerOfTwo > (n-1)) {
        powerOfTwo = (n-1);
    }

    return binarySearch(arr, left, powerOfTwo);
}

int main() {

    int n;
    std::cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    int result = findTheBend(arr, n);
    std::cout << result << std::endl;
}