#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double weight;
    double height;
    cout << "\tKalkulator BMI" << endl << "Podaj swoj wzrost (w metrach): ";
    cin >> height;
    cout << "Podaj swoja wage (w kilogramach): ";
    cin >> weight;
    
    double bmi = weight / (height * height);
    cout << "Twoj wspolczynnik BMI wynosi: " << setprecision(4) << bmi << " --> ";

    if (bmi < 16) {
        cout << "Wyglodzenie";
    }
    else if (bmi >= 16 && bmi < 17) {
        cout << "Wychudzenie";
    }
    else if (bmi >= 17 && bmi < 18.5) {
        cout << "Niedowaga";
    }
    else if (bmi >= 18.5 && bmi < 25) {
        cout << "Wartosc prawidlowa";
    }
    else if (bmi >= 25 && bmi < 30) {
        cout << "Nadwaga";
    }
    else if (bmi >= 30 && bmi < 35) {
        cout << "I stopien otylosci";
    }
    else if (bmi >= 35 && bmi < 40) {
        cout << "II stopien otylosci";
    }
    else if (bmi > 40) {
        cout << "Otylosc skrajna";
    }

    cout << endl;
    return 0;
}