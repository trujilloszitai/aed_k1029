#include <iostream>
using namespace std;

int main() {
    //Realizar la suma de todos los números pares entre 2 y 10000
    int sum = 0;
    int i = 2;

    cout << "HOLA USUARIO, aguarde un momento, estamos calculando la suma de todos los números pares entre 2 y 10000, esto puede llevar algunos minutos..." << endl;
    for (i; i <= 10000; i+=2) {
        sum += i;
    }
    cout << "La suma de todos los números pares entre 2 y 10000 es: " << sum << endl;
    return 0;
}
