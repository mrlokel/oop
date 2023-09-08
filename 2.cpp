#include <iostream>
#include <ctime>

int** genRandArray(int size, int maxValue){
    int** array = new int* [size];
    for(int i=0; i<size; i++){
        array[i] = new int [rand()];
    }

    int len_arr = 0;

    for(int count=0; *array[count] != '\0'; count++){
        len_arr++;
    }

    for(int i=0; i<size; i++){
        for(int g=0; g<len_arr; g++){
            int random_int = rand()%maxValue;
            array[i][g] = random_int;
        }
    }
    
    return array;
}

void print(int** array){
    int count = 0;
    for(int i=0; *array[1] != '\0'; i++){
        count++;
    }
    // for(int i=0; *array != Null; i++){
    //     count++;
    // } 

    std::cout << count << '\n';

    // int count_1 = 0;
    // for(int i=0; array[i][0] != '\0'; i++){
    //     count_1++;
    // }

    // int count_2 = 0;
    // for(int i_2=0; array[0][i_2] != '\0'; i_2++){
    //     count_2++;
    // }

    // for(int i_3 = 0; i_3 < count_1; i_3++){
    //     for(int i_4 = 0; i_4 < count_2; i_4++){
    //        std::cout << array[i_3][i_4] << '\n'; 
    //     }
    // }
}


int main(){
    srand(time(0));
    int size = 2;
    int maxValue = 100;
    int** arr = genRandArray(size, maxValue);
    print(arr);
    delete arr;
    return 0;
}