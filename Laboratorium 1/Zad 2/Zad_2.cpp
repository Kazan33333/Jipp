#include <iostream>
#include <cstring>
using namespace std;

bool palindrome(string tab)
{
    int length = tab.length(); //dlugość wczytanego wyrazu
    length -= 1; //przejście na ostatni element tablicy
    for (int i = 0, j = length; i <= length / 2 + 1, j >= length / 2 + 1; i++, j--) {
        if (isspace(tab[i])) { //pominięcie spacji
            i++;
        }
        if (isspace(tab[j])) {
            j--;
        }
        if (tab[i] != tab[j]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    string word = argv[1];
    cout << word << endl;
    
    if (palindrome(word)) {
        cout << "Podany ciag znakow jest palindromem" << endl;
    }
    else {
        cout << "Podany ciag znakow nie jest palindromem" << endl;
    }

    return 0;
}
