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
