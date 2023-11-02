#include <iostream>

template <typename T>
class Matrix {
private:
    T** M; // указатель на указатель для матрицы
    int m; // количество строк
    int n; // количество столбцов

public:
    // Конструктор по умолчанию
    Matrix() : M(nullptr), m(0), n(0) {}

    // Конструктор с параметрами, создает матрицу размером m x n и инициализирует элементы значением 0
    Matrix(int rows, int cols) : m(rows), n(cols) {
        M = new T*[m];
        for (int i = 0; i < m; i++) {
            M[i] = new T[n];
            for (int j = 0; j < n; j++) {
                M[i][j] = 0;
            }
        }
    }

    // Конструктор копирования
    Matrix(const Matrix& other) : m(other.m), n(other.n) {
        M = new T*[m];
        for (int i = 0; i < m; i++) {
            M[i] = new T[n];
            for (int j = 0; j < n; j++) {
                M[i][j] = other.M[i][j];
            }
        }
    }

    // Деструктор для освобождения памяти
    ~Matrix() {
        for (int i = 0; i < m; i++) {
            delete[] M[i];
        }
        delete[] M;
    }

    // Метод для установки значения элемента матрицы
    void SetM(int row, int col, T value) {
        if (row >= 0 && row < m && col >= 0 && col < n) {
            M[row][col] = value;
        }
    }

    // Метод для вывода матрицы
    void Print() const {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << M[i][j] << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << "---------------------" << std::endl;
    }

    // Перегрузка оператора присваивания
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            // Освободить текущие ресурсы
            for (int i = 0; i < m; i++) {
                delete[] M[i];
            }
            delete[] M;

            // Выделить новые ресурсы
            m = other.m;
            n = other.n;
            M = new T*[m];
            for (int i = 0; i < m; i++) {
                M[i] = new T[n];
                for (int j = 0; j < n; j++) {
                    M[i][j] = other.M[i][j];
                }
            }
        }
        return *this;
    }
};

int main() {
    Matrix<int> M1(2, 3);
    M1.Print();

    M1.SetM(0, 1, 1);
    M1.SetM(0, 2, 2);
    M1.SetM(1, 0, 1);
    M1.SetM(1, 1, 2);
    M1.SetM(1, 2, 3);

    M1.Print();

    Matrix<int> M2 = M1;
    M2.Print();

    Matrix<int> M3 = M1;
    M3.Print();

    Matrix<int> M4(2, 3);
    M4 = M1;
    M4.Print();

    return 0;
}
