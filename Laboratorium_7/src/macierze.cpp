#include "../include/Laboratorium_7/Macierze.hpp"

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
    try
    {
        matrix.at(n).at(m) = val;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

double Matrix::get(int n, int m)
{
    double val;
    try
    {
        val = matrix.at(n).at(m);        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return val;
}

Matrix Matrix::add(Matrix &m2)
{
    int r = rows();
    int c = cols();
    int m2r = m2.rows();
    int m2c = m2.cols();
    try
    {
        if (m2r != r || m2c != c) {
            throw std::runtime_error("Liczby wierszy i kolumn nie sa rowne");
        }
        Matrix result = Matrix(r, c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                (result.matrix)[i][j] = matrix[i][j] + (m2.matrix)[i][j];
            }
        }
        return result;
    }
    catch(std::exception& e)
    {
        std::cout << "Matrix add exception: " << e.what() << std::endl;
    }
    return *this;
}

Matrix Matrix::subtract(Matrix &m2)
{
    int r = rows();
    int c = cols();
    int m2r = m2.rows();
    int m2c = m2.cols();
    try
    {
        if (m2r != r || m2c != c) {
            throw std::runtime_error("Liczby wierszy i kolumn nie sa rowne");
        }
        Matrix result = Matrix(r, c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                (result.matrix)[i][j] = matrix[i][j] - (m2.matrix)[i][j];            
            }
        }
        return result;
    }
    catch(std::exception& e)
    {
        std::cout << "Matrix subtract exception: " << e.what() << std::endl;
    }
    return *this;
}

Matrix Matrix::multiply(Matrix &m2)
{
    int r = rows();
    int c = cols();
    int m2r = m2.rows();
    int m2c = m2.cols();
    try
    {
        if (c != m2r) {
            throw std::runtime_error("Liczba kolumn macierzy 1 nie jest rowna liczbie wierszy macierzy 2");
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
    catch(std::exception& e)
    {
        std::cout << "Matrix multiply exception: " << e.what() << std::endl;
    }
    return *this;
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
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cout << std::setw(7) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::operator+(Matrix &m2)
{
    int r = rows();
    int c = cols();
    int m2r = m2.rows();
    int m2c = m2.cols();
    try
    {
        if (m2r != r || m2c != c) {
            throw std::runtime_error("Liczby wierszy i kolumn nie sa rowne");
        }
        Matrix result = Matrix(r, c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                result.set(i, j, (get(i, j) + m2.get(i, j)));
            }
        }
        return result;
    }
    catch(std::exception& e)
    {
        std::cout << "Matrix add exception: " << e.what() << std::endl;
    }
    return *this;
}

Matrix Matrix::operator-(Matrix &m2)
{
    int r = rows();
    int c = cols();
    int m2r = m2.rows();
    int m2c = m2.cols();
    try
    {
        if (m2r != r || m2c != c) {
            throw std::runtime_error("Liczby wierszy i kolumn nie sa rowne");
        }
        Matrix result = Matrix(r, c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                result.set(i, j, (get(i, j) - m2.get(i, j)));
            }
        }
        return result;
    }
    catch(std::exception& e)
    {
        std::cout << "Matrix subtract exception: " << e.what() << std::endl;
    }
    return *this;
}

Matrix Matrix::operator*(Matrix &m2)
{
    int r = rows();
    int c = cols();
    int m2r = m2.rows();
    int m2c = m2.cols();
    try
    {
        if (c != m2r) {
            throw std::runtime_error("Liczba kolumn macierzy 1 nie jest rowna liczbie wierszy macierzy 2");
        }
        Matrix result = Matrix(m2c, r);
        double sum = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < m2c; j++) {
                sum = 0;
                for (int k = 0; k < c; k++) {
                    sum += get(i, k) * m2.get(k, j);
                }
                result.set(i, j, sum);
            }
        }
        return result;
    }
    catch(std::exception& e)
    {
        std::cout << "Matrix multiply exception: " << e.what() << std::endl;
    }
    return *this;
}