#include <iostream>
using namespace std;

int main() {
    //Dado tres valores determinar e imprimir una leyenda según sea: “Forman triangulo” o “No forman triangulo”.
    int s1, s2, s3 = 0;
    cout << "HOLA USUARIO. A continuación deberá ingresar tres valores para determinar si forman un triángulo." << endl;
    cout << "Ingrese el primer valor: ";
    cin >> s1;
    cout << "Ingrese el segundo valor: ";
    cin >> s2;
    cout << "Ingrese el terecer valor: ";
    cin >> s3;

    if (s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1) {
        cout << "Los valores ingresados forman un triángulo." << endl;
    } else {
        cout << "Los valores ingresados no forman un triángulo." << endl;
    }
    return 0;
}
