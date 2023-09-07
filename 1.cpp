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

void print(int* array){
    int count = 0;
    for(int i=0; i<10; i++){
        if (array[i] != '\0'){
            count++;
        }
    }

    for(int i=0; i<count; i++){
        std::cout << array[i];
        std::cout << "\n";
    }
}

int main() {
    srand(time(0));
    int size = rand() % 10;
    int maxValue = 100;
    int* arr = genRandArray(size, maxValue);
    print(arr);
    delete arr;

    return 0;
}