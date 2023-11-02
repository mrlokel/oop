#include <iostream>
#include <cstdlib>

class Matrix {
private:
    int** data;     // Указатель на двумерный массив
    int rows;       // Количество строк
    int cols;       // Количество столбцов
    int sum;

public:
    // Конструктор по умолчанию
    Matrix() : rows(0), cols(0), sum(0), data(nullptr) {}

    // Конструктор для создания единичной квадратной матрицы
    Matrix(int size) : rows(size), cols(size), sum(0) {
        data = new int*[size];
        for (int i = 0; i < size; ++i) {
            data[i] = new int[size];
            for (int j = 0; j < size; ++j) {
                data[i][j] = (i == j) ? 1 : 0;
            }
        }
    }

    // Конструктор для создания матрицы указанной размерности
    Matrix(int rows, int cols) : rows(rows), cols(cols), sum(0) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    // Деструктор для освобождения памяти
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Ввод значений матрицы с клавиатуры
    void inputMatrix() {
        std::cout << "Введите элементы матрицы " << rows << "x" << cols << ":\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cin >> data[i][j];
            }
        }
    }

    // Заполнение матрицы случайными числами
    void fillRandom() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = rand() % 100; // Генерация случайных чисел от 0 до 99
            }
        }
    }

    // Вывод матрицы на экран
    void printMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Подсчет суммы элементов матрицы
    void calculateSum() {
        sum = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                sum += data[i][j];
            }
        }
        std::cout << "Сумма элементов матрицы: " << sum << std::endl;
    }
};

int main() {
    // Создание матриц с разными конструкторами
    Matrix M1;          // Конструктор по умолчанию
    Matrix M2(3);       // Конструктор с указанием размерности
    Matrix M3(3, 4);    // Конструктор с указанием размерности
    Matrix M4(2, 3);    // Конструктор с указанием размерности

    std::cout << "Матрица M2:\n";
    M2.printMatrix();

    std::cout << "Матрица M3:\n";
    M3.fillRandom();
    M3.printMatrix();
    M3.calculateSum();

    std::cout << "Матрица M4 (введите элементы с клавиатуры):\n";
    M4.inputMatrix();
    M4.printMatrix();

    return 0;
}
