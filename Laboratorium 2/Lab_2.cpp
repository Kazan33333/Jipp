#include <iostream>
using namespace std;

void swap_if_smaller(int *no1, int *no2)
{
    if (*no1 > *no2) {
        int temp = *no1;
        *no1 = *no2;
        *no2 = temp;
    }
}

void swap_numbers(int &no1, int &no2)
{
    int temp = no1;
    no1 = no2;
    no2 = temp;
}

void swap_no(int &no1, int *no2)
{
    int temp = no1;
    no1 = *no2;
    *no2 = temp;
}

int product_sum(int no1, int no2, int *product)
{
    *product = no1 * no2;
    int sum = no1 + no2;
    return sum;
}

void my_swap(int *no1, int *no2)
{
    int temp = *no1;
    *no1 = *no2;
    *no2 = temp;
}

void swap_overload(int &no1, int &no2)
{
    int temp = no1;
    no1 = no2;
    no2 = temp;
}

void swap_overload(double &no1, double &no2)
{
    double temp = no1;
    no1 = no2;
    no2 = temp;
}

int main()
{
    /*Zad 1*/
    int a, b;
    cout << "Podaj dwie liczby calkowite: " << endl << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    swap_if_smaller(&a, &b);
    cout << "1) " << "a = " << a << ", " << "b = " << b << "\t\t<-- Zamiana (poprzez wskazniki) jesli b jest mniejsze od a" << endl;

    /*Zad 2*/
    swap_numbers(a, b);
    cout << "2) " << "a = " << a << ", " << "b = " << b << "\t\t<-- Zamiana (poprzez referencje)" << endl;

    /*Zad 3*/
    swap_no(a, &b);
    cout << "3) " << "a = " << a << ", " << "b = " << b << "\t\t<-- Zamiana (poprzez wskaznik i referencje)" << endl;

    /*Zad 4*/
    int product = 0;
    int sum = product_sum(a, b, &product);
    cout << "4) " << "a * b = " << product << "\t\t<-- Iloczyn" << endl << "   a + b = " << sum << "\t\t<-- Suma" << endl;

    /*Zad 5*/
    my_swap(&a, &b);
    cout << "5) " << "a = " << a << ", " << "b = " << b << "\t\t<-- Zamiana (poprzez wskazniki)" << endl;

    /*Zad 6*/
    swap_overload(a,b);
    cout << "6) " << "a = " << a << ", " << "b = " << b << "\t\t<-- Zamiana - przeciazenie funkcji" << endl;

    return 0;
}
