#include <iostream>
using namespace std;

int main() {
    // Dado un numero entero de la forma (AAAAMMDD), que representa una fecha valida mostrar el dio, mes y año que representa
    int date, day, month, year = 0;
    cout << "HOLA USUARIO. Ingrese una fecha en formato AAAAMMDD porfi: ";
    cin >> date;
    day = date % 100;
    month = (date / 100) % 100;
    year = date / 10000;

    cout << "La fecha ingresada es: " << day << "/" << month << "/" << year << endl;

    return 0;
}
