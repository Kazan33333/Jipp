#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    int *tab = new int [argc - 2]; //dynamiczna alokacja pamięci
    int temp;
    for (int i = 0; i < argc - 1; i++) {
        tab[i] = atoi(argv[i + 1]); //atoi - zamiana na int
        cout << tab[i] << " ";
    }

    for (int i = 0; i < argc - 1; i++) { //sortowanie (zastosowałem tu bąbelkowe)
        for (int j = 0; j < argc - 1 - i; j++) {
            if (tab[j] > tab[j + 1]) {
                temp = tab[j + 1];
                tab[j + 1] = tab[j];
                tab[j] = temp;
            }
        }
    }

    cout << endl << "Out = ";
    for (int i = 0; i < argc - 1; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;

    delete[] tab; 
}