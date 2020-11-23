#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <iomanip>

class Matrix {
public:
    std::vector < std::vector < double > > matrix;
    Matrix(int rows, int cols);
    Matrix(int size);
    Matrix(std::string path);
    ~Matrix();
    void set(int n, int m, double val);
    double get(int n, int m);
    Matrix add(Matrix &m2);
    Matrix subtract(Matrix &m2);
    Matrix multiply(Matrix &m2);
    int cols();
    int rows();
    void print();
    bool store(std::string filename, std::string path);
};

Matrix::Matrix(int rows, int cols)
{
    std::vector <double> tab;
    for(int j = 0; j < cols; j++) {
        tab.push_back(0);
    }
    for (int i = 0 ; i < rows ; i++) {
        matrix.push_back(tab);
    }
}

Matrix::Matrix(int size)
{
    std::vector <double> tab;
    for (int j = 0; j < size; j++) {
        tab.push_back(0);
    }
    for (int i = 0 ; i < size ; i++) {
        matrix.push_back(tab);
    }
}

Matrix::Matrix(std::string path)
{
    std::fstream file;
    std::vector <double> tab;
    file.open(path, std::ios::in);
    if (file.good()) {
        int rows, cols;
        file >> rows >> cols;
        int sth;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                file >> sth;
                tab.push_back(sth);
            }
            matrix.push_back(tab);
            tab.clear();
        }
    }
    file.close();
}

Matrix::~Matrix(){}

void Matrix::set(int n, int m, double val)
{
    matrix.at(n).at(m) = val;
}

double Matrix::get(int n, int m)
{
    return matrix.at(n).at(m);
}

Matrix Matrix::add(Matrix &m2)
{
    int r = rows();
    int c = cols();
    Matrix result = Matrix(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            (result.matrix)[i][j] = matrix[i][j] + (m2.matrix)[i][j];
        }
    }
    return result;
}

Matrix Matrix::subtract(Matrix &m2)
{
    int r = rows();
    int c = cols();
    Matrix result = Matrix(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            (result.matrix)[i][j] = matrix[i][j] - (m2.matrix)[i][j];            
        }
    }
    return result;
}

Matrix Matrix::multiply(Matrix &m2)
{
    int r = rows();
    int c = cols();
    int m2r = m2.rows();
    int m2c = m2.cols();
    Matrix result = Matrix(r, c);
    double sum = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < m2c; j++) {
            sum = 0;
            for (int k = 0; k < c; k++) {
                sum += matrix[i][k] * (m2.matrix)[j][k];
            }
            (result.matrix)[i][j] = sum;
        }
    }
    return result;
}

int Matrix::cols()
{
    return matrix[0].size();
}

int Matrix::rows()
{
    return matrix.size();
}

bool Matrix::store(std::string filename, std::string path)
{
    std::fstream file;
    if (!file.good()) {
        return false;
    }
    int r = rows();
    int c = cols();
    file << "Wiersze: " << r << ", " << "Kolumny: " << c;
    file << std::endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            file << matrix[i][j];
        }
        file << std::endl;
    }
    file.close();
    return true;
}

void Matrix::print()
{    
    int r = rows();
    int c = cols();
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

int main()
{
    Matrix matrix1 = Matrix(6,4);
    Matrix matrix2 = Matrix(4,6);
    Matrix squarematrix1 = Matrix(5);
    Matrix squarematrix2 = Matrix(5);
    srand(time(NULL));
    double tab;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++){
            tab = (double)(rand() % 100);
            matrix1.set(i,j,tab);
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){
            tab = (double)(rand() % 100);
            matrix2.set(i,j,tab);
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            tab = (double)(rand() % 100);
            squarematrix1.set(i,j,tab);
            tab = (double)(rand() % 100);
            squarematrix2.set(i,j,tab);
        }
    }

    std::cout << "1) Macierz 1 o wymiarach 6x4" << std::endl << std::endl;
    matrix1.print();
    std::cout << std::endl << "2) Macierz 2 o wymiarach 4x6" << std::endl << std::endl;
    matrix2.print();
    std::cout << std::endl << "3) Macierz kw. 1 o wymiarach 5x5" << std::endl << std::endl;
    squarematrix1.print();
    std::cout << std::endl << "4) Macierz kw. 2 o wymiarach 5x5" << std::endl << std::endl;
    squarematrix2.print();
    std::cout << std::endl << "5) Dodawanie:" << std::endl << std::endl;
    Matrix result1 = squarematrix1.add(squarematrix2);
    result1.print();
    std::cout << std::endl << "6) Odejmowanie:" << std::endl << std::endl;
    Matrix result2 = squarematrix1.subtract(squarematrix2);
    result2.print();
    std::cout << std::endl << "7) Mnozenie:" << std::endl << std::endl;
    Matrix result3 = matrix1.multiply(matrix2);
    result3.print();
    std::cout << std::endl << "8) Zapis do pliku:" <<std::endl;
    if(result3.store("File_store", "./Txt/")) {
        std::cout << "The file has been saved" << std::endl;
    }
    std::cout << "9) Zapis konstruktora do pliku:" <<std::endl;
    Matrix result4 = Matrix("./Txt/File");
    result4.print();

    return 0;
}
