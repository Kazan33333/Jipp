#include "../include/Laboratorium_7/Macierze.hpp"

int main()
{
    Matrix matrix1 = Matrix(4, 6);
    Matrix matrix2 = Matrix(6, 4);
    Matrix squarematrix1 = Matrix(5);
    Matrix squarematrix2 = Matrix(5);
    srand(time(NULL));
    double tab;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){
            tab = (double)(rand() % 26) / 2;
            matrix1.set(i,j,tab);
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            tab = (double)(rand() % 26) / 2;
            squarematrix1.set(i,j,tab);
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            tab = (double)(rand() % 26) / 2;
            squarematrix2.set(i,j,tab);
        }
    }

    std::cout << "1) Macierz 1 o wymiarach 4x6:" << std::endl << std::endl;
    matrix1.print();
    std::cout << std::endl << "2) Macierz 2 o wymiarach 6x4 (odczyt z pliku):" << std::endl << std::endl;
    matrix2 = Matrix("./txt/File.txt");
    matrix2.print();
    std::cout << std::endl << "3) Macierz kw. 1 o wymiarach 5x5:" << std::endl << std::endl;
    squarematrix1.print();
    std::cout << std::endl << "4) Macierz kw. 2 o wymiarach 5x5:" << std::endl << std::endl;
    squarematrix2.print();
    std::cout << std::endl << "5) Result1 -> Dodawanie (macierz kw. 1 i macierz kw. 2):" << std::endl << std::endl;
    Matrix Result1 = squarematrix1.add(squarematrix2);
    Result1.print();
    std::cout << std::endl << "6) Result2 -> Odejmowanie (macierz kw. 1 i macierz kw. 2):" << std::endl << std::endl;
    Matrix Result2 = squarematrix1.subtract(squarematrix2);
    Result2.print();
    std::cout << std::endl << "7) Result3 -> Mnozenie (macierz 1 i macierz 2):" << std::endl << std::endl;
    Matrix Result3 = matrix1.multiply(matrix2);
    Result3.print();
    std::cout << std::endl << "8) Zapis do pliku: ";
    if(Result3.store("File_store.txt", "./txt/")) {
        std::cout << "Wyniki mnozenia macierzy zapisane do pliku." << std::endl << std::endl;
    }

    /* W lab3 nie uzylem metody get, uzylem ja przy operatorach */
    std::cout << "9) Przeciazanie operatorow" << std::endl; 
    std::cout << std::endl << "--> Dodawanie (macierz kw. 1 i macierz kw. 2):" << std::endl << std::endl;
    Matrix Result4 = squarematrix1 + squarematrix2;
    Result4.print();
    std::cout << std::endl << "--> Odejmowanie (macierz kw. 1 i macierz kw. 2):" << std::endl << std::endl;
    Matrix Result5 = squarematrix1 - squarematrix2;
    Result5.print();
    std::cout << std::endl << "--> Mnozenie (macierz 1 i macierz 2):" << std::endl << std::endl;
    Matrix Result6 = matrix1 * matrix2;
    Result6.print();
    std::cout << std::endl << "--> Czy macierze sa rowne? (1 - tak, 0 - nie) -> " << (Result4 == Result5) << std::endl;
    std::cout << std::endl << "--> Czy macierze nie sa rowne? (1 - tak, 0 - nie) -> " << (Result4 != Result5) << std::endl;
    std::cout << std::endl << "--> Inkrementacja elementow macierzy Result6:" << std::endl << std::endl;
    ++Result6;
    Result6.print();
    std::cout << std::endl << "--> Dekrementacja elementow macierzy Result6:" << std::endl << std::endl;
    --Result6;
    Result6.print();
    std::cout << std::endl;

    return 0;
}
