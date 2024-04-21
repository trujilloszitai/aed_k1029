#include <iostream>
using namespace std;

int main()
{
    // Dados dos valores enteros A y B, informar la suma, la resta y el producto.
    int a, b, sum, sub1, sub2, mul = 0;
    cout << "HOLA USUARIO. Ingrese dos números (A y B) ENTEROS porfi." << endl;
    cout << "Número A: ";
    cin >> a;
    cout << "Número B: ";
    cin >> b;

    sum = a + b;
    sub1 = a - b;
    sub2 = b - a;
    mul = a * b;

    cout << "La sumatoria de A y B es: " << sum << endl;
    cout << "La diferencia entre A y B es: " << sub1 << endl;
    cout << "La diferencia entre B y A es: " << sub2 << endl;
    cout << "El producto entre A y B es: " << mul << endl;

    return 0;
}