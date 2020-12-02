#include "..\include\Laboratorium_4\Macierze.hpp"

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
    std::ifstream file;
    std::vector <double> tab;
    file.open(path.c_str());
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
    int m2r = m2.rows();
    int m2c = m2.cols();
    if (m2r != r || m2c != c) {
        exit (1);
    }
    else {
        Matrix result = Matrix(r, c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                (result.matrix)[i][j] = matrix[i][j] + (m2.matrix)[i][j];
            }
        }
        return result;
    }
}

Matrix Matrix::subtract(Matrix &m2)
{
    int r = rows();
    int c = cols();
    int m2r = m2.rows();
    int m2c = m2.cols();
    if (m2r != r || m2c != c) {
        exit (1);
    }
    else {
        Matrix result = Matrix(r, c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                (result.matrix)[i][j] = matrix[i][j] - (m2.matrix)[i][j];            
            }
        }
        return result;
    }
}

Matrix Matrix::multiply(Matrix &m2)
{
    int r = rows();
    int c = cols();
    int m2r = m2.rows();
    int m2c = m2.cols();
    if (c != m2r) {
        exit(1);
    }
    Matrix result = Matrix(m2c, r);
    double sum = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < m2c; j++) {
            sum = 0;
            for (int k = 0; k < c; k++) {
                sum += matrix[i][k] * (m2.matrix)[k][j];
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
    std::ofstream file;
    file.open((path + filename).c_str());
    if (!file.good()) {
        return false;
    }
    int r = rows();
    int c = cols();
    file << "Wiersze: " << r << ", Kolumny: " << c << std::endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            file << matrix[i][j] << " ";
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
            std::cout << std::setw(7) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}
