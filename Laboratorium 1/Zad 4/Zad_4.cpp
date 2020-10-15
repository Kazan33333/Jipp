#include <iostream>
using namespace std;

/*Dwie różne liczby całkowite a i b większe od 1 nazwiemy skojarzonymi, jeśli suma wszystkich
różnych dodatnich dzielników a mniejszych od a jest równa b+1, a suma wszystkich różnych dodatnich dzielników b mniejszych od b jest równa a+1.*/

int main()
{
    int a, b;
    cout << "Czy liczby sa skojarzone?" << endl << "Podaj liczby:" << endl << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    int sum1 = 0, sum2 = 0;
    
    for (int i = 1; i <= a / 2; i++) {
        if (a % i == 0) {
            sum1 += i;
        }
    }

    for (int i = 1; i <= b / 2; i++) {
        if (b % i == 0) {
            sum2 += i;
        }
    }

    if (sum1 == b + 1 && sum2 == a + 1) {
        cout << "Liczby sa skojarzone" << endl;
    }
    else {
        cout << "Liczby nie sa skojarzone" << endl;
    }

    return 0;
}