#include "Macierze.cpp"

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
    matrix2 = Matrix("./Txt/File.txt");
    matrix2.print();
    std::cout << std::endl << "3) Macierz kw. 1 o wymiarach 5x5:" << std::endl << std::endl;
    squarematrix1.print();
    std::cout << std::endl << "4) Macierz kw. 2 o wymiarach 5x5:" << std::endl << std::endl;
    squarematrix2.print();
    std::cout << std::endl << "5) Dodawanie (macierz kw. 1 i macierz kw. 2):" << std::endl << std::endl;
    Matrix result1 = squarematrix1.add(squarematrix2);
    result1.print();
    std::cout << std::endl << "6) Odejmowanie (macierz kw. 1 i macierz kw. 2):" << std::endl << std::endl;
    Matrix result2 = squarematrix1.subtract(squarematrix2);
    result2.print();
    std::cout << std::endl << "7) Mnozenie (macierz 1 i macierz 2):" << std::endl << std::endl;
    Matrix result3 = matrix1.multiply(matrix2);
    result3.print();
    std::cout << std::endl << "8) Zapis do pliku: ";
    if(result3.store("File_store.txt", "./Txt/")) {
        std::cout << "Wyniki mnozenia macierzy zapisano do pliku." << std::endl << std::endl;
    }

    return 0;
}
