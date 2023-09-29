#include <iostream>
#include <ctime>
using namespace std;

int* genRandArray(int maxValue){
    int size_array = rand() % 11;
    while (size_array == 0 || size_array == 1){
        size_array = rand() % 11;
    }
    int* array = new int [size_array];
    array[0] = size_array;
    for(int i=1; i<size_array; i++){
        int random_int = rand()%maxValue;
        array[i] = random_int;
    }
    
    return array;
}

int** genRandMatrix(int size, int maxValue){
    int** array = new int* [size];
    for(int i=0; i<=size; i++){
        array[i] = genRandArray(maxValue);
    }

    return array;
}

void printArr(int* array){
    int size = array[0];
    cout << size-1 << ": ";
    for(int i=1; i<size; i++){
        cout << array[i] << ", ";
    }

    cout << '\n';
}

void print(int** array, int size){
    cout << size << "\n";
    for(int i = 0; i<size; i++){
        printArr(array[i]);
    }
}

int main(){
    srand(time(0));
    int size = rand()%10;
    int maxValue = 100;
    int** arr = genRandMatrix(size, maxValue);
    print(arr, size);
    delete arr;
    return 0;
}