/*
 Дан массив целых чисел A[0..n).
 Не используя других массивов переставить элементы массива A в обратном порядке за O(n). n ≤ 10000.
 */

#include <iostream>
#include <cassert>

void swap(int &a, int&b){
    /*
     Вообще есть много изящных по написанию и задумке способов сделать 
     swap без использования временной переменной (я знаю 3), но все они 
     обладают определенными недостатками, поэтому не буду выпендриваться.
     */
    int temp = a;
    a = b;
    b = temp;

}

void reverseArray(int countOfElements, int *arr){

    for (int i = 0; i <= countOfElements/2-1; i++)
        swap(arr[i], arr[countOfElements-i-1]);
}

int main() {

    int countOfElements; std::cin >> countOfElements;
    int* arr = new int[countOfElements];

    assert(countOfElements >= 0);

    for(int i = 0; i < countOfElements; i++)
        std::cin >> arr[i];

    reverseArray(countOfElements, arr);

    for(int i = 0; i < countOfElements; i++)
        std::cout << arr[i] << " ";

    delete [] arr;

    return 0;
}
