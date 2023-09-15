#include <iostream>
#include <ctime>

int* genRandArray(int size, int maxValue){
    int* array = new int [size];
    array[0] = size;
    for(int i=1; i<size; i++){
        int random_int = rand()%maxValue;
        array[i] = random_int;
    }
    
    return array;
}

int** genRandMatrix(int size, int maxValue){
    int** array = new int* [size];
    for(int i=0; i<size; i++){
        array[i] = genRandArray(size, maxValue);
    }
    
    return array;
}

void print(int** array, int size){
    for(int i=0; i<size; i++){
        int len_arr = array[0][i];
        for(int j=0; j<len_arr; j++){
            std::cout << array[len_arr][i] << '\n';
        }
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