#include <iostream>
#include <ctime>

int* genRandArray(int size){
    int* array = new int [size];
    array[0] = size-1;
    for(int i=1; i<size; i++){
        int random_int = rand()%100;
        array[i] = random_int;
    }
    
    return array;
}

int** genRandMatrix(int size){
    int** array = new int* [size];
    for(int i=0; i<size; i++){
        array[i] = genRandArray(size);
    }

    return array;
}

int** genRandMatrix_2(int size){
    int** array = new int* [size];
    for(int i=0; i<size; i++){
        array[i] = genRandArray(rand()%15);
    }

    return array;
}

void printArr(int* array, int size){
    for(int i=0; i<size; i++){
        std::cout << array[i] << ", ";
    }

    std::cout << '\n';
}

void printzamenaright(int** array, int* arr_2, int size){
    std::cout << '\n';
    printArr(arr_2, size);
    std::cout << '\n';
    
    int count = 1;
    for(int i=0; i<size; i++){
        array[i][size-count] = arr_2[i];
        count++;
    }
}

void printzamenaleft(int** array, int* arr_2, int size){
    std::cout << '\n';
    printArr(arr_2, size);
    std::cout << '\n';
    
    int count = 0;
    for(int i=0; i<size; i++){
        array[i][count] = arr_2[i];
        count++;
    }
}

// из центра наружу
void MatrixSpiralNoInCenter(int** arr, int* arr1, int size) {
    arr[(size - 1) / 2][(size - 1) / 2] = arr1[0];
    int x = 1;
    int n = (size - 1) / 2;
    int i, j, gran = 1;
    i = j = n;

    while (gran <= n)
    {
        while (i != n - gran && ((i != n - gran) || (j != n + gran)))
        {
            i--;
            arr[i][j] = arr1[x];
            x++;
        }
        while (j != n - gran && ((i != n - gran) || (j != n + gran)))
        {
            j--;
            arr[i][j] = arr1[x];
            x++;
        }
        while (i != n + gran && ((i != n - gran) || (j != n + gran)))
        {
            i++;
            arr[i][j] = arr1[x];
            x++;
        }
        while (j != n + gran && ((i != n - gran) || (j != n + gran)))
        {
            j++;
            arr[i][j] = arr1[x];
            x++;
        }
        if (i == n - gran && j == n + gran) {
            gran++;
        }
    }
}

// снаружи в центр
void MatrixSpiralInCenter(int** arr, int* arr_1, int size) {
    int x = 0;
    int n = 1;
    int i = 0, j = 0, gran = (size - 1) / 2;

    while (gran >= n)
    {
        while (j != size-n)
        {
            arr[i][j] = arr_1[x];
            j++;
            x++;
            if(j==size-n){
                arr[i][j] = arr_1[x];
                x++;
            }
        }
        while (i != size - n)
        {
            i++;
            arr[i][j] = arr_1[x];
            x++;
        }
        while (j != n - 1)
        {
            j--;
            arr[i][j] = arr_1[x];
            x++;
        }
        while (i != n)
        {
            i--;
            arr[i][j] = arr_1[x];
            x++;
        }
        if (i == n && j == n - 1) {
            n++;
            // i++;
            j++;
        }
    }

    arr[(size - 1) / 2][(size - 1) / 2] = arr_1[size*size-1];
}



void printMatrix(int** array, int size){
    for(int i = 0; i<size; i++){
        for(int j=0; j<size; j++){
            std::cout << array[i][j] << ", ";
        }
        std::cout << '\n';
    }

}

void printMatrix2(int** array, int size){
    for(int i = 0; i<size; i++){
        int size_2 = array[i][0];
        for(int j=0; j<size_2; j++){
            std::cout << array[i][j] << ", ";
        }
        std::cout << '\n';
    }
}

int main(){
    srand(time(0));

    int size_matrix = 5;
    int size_array = size_matrix*size_matrix;

    int** arr = genRandMatrix(size_matrix);
    int* arr_elements_right_left = genRandArray(size_matrix);
    int* arr_2 = genRandArray(size_array);

    std::cout << '\n';

    std::cout << "Элементы справа налево";
    std::cout << '\n' << '\n';
    printMatrix(arr, size_matrix);
    std::cout << '\n';
    printzamenaright(arr, arr_elements_right_left, size_matrix);
    std::cout << '\n';
    printMatrix(arr, size_matrix);

    std::cout << '\n';

    std::cout << "Элементы слева направо";
    std::cout << '\n' << '\n';
    printMatrix(arr, size_matrix);
    std::cout << '\n';
    printzamenaleft(arr, arr_elements_right_left, size_matrix);
    std::cout << '\n';
    printMatrix(arr, size_matrix);

    std::cout << '\n';

    std::cout << "Спираль с левого верха в центр";
    std::cout << '\n' << '\n';
    printMatrix(arr, size_matrix);
    std::cout << '\n';
    printArr(arr_2, size_array);
    std::cout << '\n';
    MatrixSpiralInCenter(arr, arr_2, size_matrix);
    std::cout << '\n';
    printMatrix(arr, size_matrix);

    std::cout << '\n';

    std::cout << "Спираль с центра наружу";
    std::cout << '\n' << '\n';
    printMatrix(arr, size_matrix);
    std::cout << '\n';
    printArr(arr_2, size_array);
    std::cout << '\n';
    MatrixSpiralNoInCenter(arr, arr_2, size_matrix);
    std::cout << '\n';
    printMatrix(arr, size_matrix);

    for(int i=0; i<size_matrix; i++){
        delete[] arr[i];
    }
    delete[] arr;
    delete[] arr_2;
    delete[] arr_elements_right_left;

    std::cout << '\n';
    std::cout << "Вывод подстрочно строк массива";
    std::cout << '\n' << '\n';
    int** arr_one = genRandMatrix_2(size_matrix);
    printMatrix2(arr, size_matrix);
    std::cout << '\n';
    for(int i=0; i<5; i++){
        printArr(arr_one[i], arr_one[i][0]);
        std::cout << '\n';
    }

    for(int i=0; i<size_matrix; i++){
        delete[] arr_one[i];
    }
    delete[] arr_one;

    return 0;
}
