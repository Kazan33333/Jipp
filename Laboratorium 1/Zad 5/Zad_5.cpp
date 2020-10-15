#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    const int a = 2, b = 3;
    int t1[a][b], t2[a][b], t3[a][b];
    cout << "\tDodawanie macierzy 2 x 3" << endl << "Pierwsza macierz:" << endl;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            t1[i][j] = rand() % 31; //losowanie liczb z przedziału <0, 30>
            cout << t1[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "Druga macierz:" << endl;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            t2[i][j] = rand() % 31;
            cout << t2[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "Macierz wynikowa:" << endl;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            t3[i][j] = t1[i][j] + t2[i][j];
            cout << t3[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}