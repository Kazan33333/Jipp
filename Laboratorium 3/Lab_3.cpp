#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public:
    vector < vector < double > > matrix;
    Matrix(int rows, int cols);
    Matrix(int size);
    void set(int n, int m, int val);
    double get(int n, int m);
    Matrix add(Matrix m2);
    Matrix subtract(Matrix m2);
    Matrix multiply(Matrix m2);
    int cols();
    int rows();
    //void print();
};

Matrix::Matrix(int rows, int cols)
{
    vector <double> tab;
    for(int j = 0; j < cols; j++) {
        tab.push_back(0); //wypełniam zerami
    }
    for (int i = 0 ; i < rows ; i++) {
        matrix.push_back(tab); //wypełniam vector vectorami
    }
}

Matrix::Matrix(int size)
{
    vector <double> tab;
    for (int j = 0; j < size; j++) {
        tab.push_back(0);
    }
    for (int i = 0 ; i < size ; i++) {
        matrix.push_back(tab);
    }
}

void set(int n, int m, int val)
{
    
}

double get(int n, int m)
{

}

Matrix Matrix::add(Matrix m2)
{
    int r = rows();
    int c = cols();
    Matrix result = matrix;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            (Matrix.matrix)[i][j] = matrix[i][j] + (m2.matrix)
        }
    }
}

Matrix Matrix::subtract(Matrix m2)
{
    int r = rows();
    int c = cols();
    Matrix result = matrix;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            (Matrix.matrix)[i][j] = matrix[i][j] - (m2.matrix)
        }
    }
}

Matrix Matrix::multiply(Matrix m2)
{

}

int Matrix::cols()
{
    return matrix[0].size();
}

int Matrix::rows()
{
    return matrix.size();
}

int main()
{

    return 0;
}