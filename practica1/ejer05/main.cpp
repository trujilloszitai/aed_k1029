#include <iostream>
using namespace std;

int main()
{
    int s1, s2, s3;
    cout << "HOLA USUARIO. A continuación deberá ingresar por teclado los tres valores que representan a los lados de un triángulo para determinar si es equilátero, isósceles o escaleno." << endl;
    cout << "Ingrese el primer valor: ";
    cin >> s1;
    cout << "Ingrese el segundo valor: ";
    cin >> s2;
    cout << "Ingrese el terecer valor: ";
    cin >> s3;

    if (s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1)
    {
        if (s1 == s2 && s2 == s3)
        {
            cout << "Los valores ingresados forman un triángulo equilátero." << endl;
        }
        else if (s1 == s2 || s1 == s3 || s2 == s3)
        {
            cout << "Los valores ingresados forman un triángulo isósceles." << endl;
        }
        else
        {
            cout << "Los valores ingresados forman un triángulo escaleno." << endl;
        }
    }

    else
    {
        cout << "Los valores ingresados no forman un triángulo." << endl;
    }
    return 0;
}
