#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public:
    vector < vector < double > > matrix;
    Matrix(int rows, int cols); /*konstruktor przyjmujący dwa argumenty typu int tworzący macierz o podanych wymiarach zainicjalizowaną zerami*/
    Matrix(int size); /*konstruktor przyjmujący jeden argument typu int tworzący macierz kwadratową o podanym rozmiarze zainicjalizowaną zerami*/
    Matrix(string path); /*dodatkowy konstruktor jako argument przyjmujący ścieżkę do pliku o podanym wcześniej formacie i na jego podstawie tworzący nową macierz na podstawie przekazanego pliku*/
    void set(int n, int m, int val); /*metoda ustawiająca wartość elementu (n, m) na val*/
    double get(int n, int m); /*metoda pobierająca element (n, m)*/
    Matrix add(Matrix m2); /*metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą sumą bieżącej macierzy oraz macierzy przekazanej jako argument*/
    Matrix subtract(Matrix m2); /*metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą różnicą bieżącej macierzy oraz macierzy przekazanej jako argument*/
    Matrix multiply(Matrix m2); /*metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą iloczynem bieżącej macierzy oraz macierzy przekazanej jako argument*/
    int cols(); /*metoda zwracająca liczbę kolumn macierzy*/
    int rows(); /*metoda zwracająca liczbę wierszy macierzy*/
    void print(); /*metoda wyświetlająca macierz na ekranie*/
    void store(string filename, string path); /*metoda zapisująca macierz w pliku; w pliku powinny być zapisane wymiary macierzy (liczba kolumn i liczba wierszy w pierwszym wierszu pliku)*/
};                                            /*oraz jej zawartość (każdy wiersz macierzy w osobnym wierszu pliku)*/

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

Matrix::Matrix(string path)
{

}

void set(int n, int m, int val)
{
    matrix.at(n).at(m) = val;
}

double get(int n, int m)
{
    return matrix.at(n).at(m);
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
    int r = rows();
    int c = cols();
    
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
    matrix matrix1 = matrix(6,4);
    matrix matrix2 = matrix(4,6);
    matrix squarematrix1 = matrix(5);
    matrix squarematrix2 = matrix(5);

    return 0;
}
