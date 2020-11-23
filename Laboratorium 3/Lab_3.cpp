#include <iostream>
#include <vector>

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
        tab.push_back(0); //wypełniam zerami
    }
    for (int i = 0 ; i < rows ; i++) {
        matrix.push_back(tab); //wypełniam vector vectorami
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

Matrix::Matrix(string path)
{
    std::fstream file;
    file.open();
}

Matrix::~Matrix(){}

void Matrix::set(int n, int m, int val)
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
            (Matrix.matrix)[i][j] = matrix[i][j] + (m2.matrix)[i][j];
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
            (Matrix.matrix)[i][j] = matrix[i][j] - (m2.matrix)[i][j];            
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
                sum += matrix[i][k] * (m2matrix)[j][k];
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
}

int main()
{
    Matrix matrix1 = matrix(6,4);
    Matrix matrix2 = matrix(4,6);
    Matrix squarematrix1 = matrix(5);
    Matrix squarematrix2 = matrix(5);

    return 0;
}
