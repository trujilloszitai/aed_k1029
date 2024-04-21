#include <iostream>
#include <string>
using namespace std;

int main() {
    int age = 0;
    string rank = "";

    cout << "HOLA USUARIO. A continuación deberá ingresar la edad de John Doe: ";
    cin >> age;

    if (age < 0)
    {
        cout << "John Doe aún no ha nacido." << endl;
        return 0;
    }
    if (age <= 12) 
    {
        rank = "menor";
    }
    else if (age >= 13 && age <= 18)
    {
        rank = "cadete";
    }
    else if (age > 18 && age <= 26)
    {
        rank = "juvenil";
    }
    else
    {
        rank = "mayor";
    }

    cout << "John Doe es un " << rank << endl;
    return 0;
}
