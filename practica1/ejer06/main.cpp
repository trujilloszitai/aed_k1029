#include <iostream>
#include <string>
using namespace std;

int main()
{
    /*     Se ingresa una edad, mostrar por pantalla alguna de las siguientes leyendas:
    ∙ ‘menor’ si la edad es menor o igual a 12
    ∙ ‘cadete’ si la edad esta comprendida entre 13 y 18
    ∙ ‘juvenil’ si la edad es mayor que 18 y no supera los 26
    ∙ ‘mayor’ en el caso que no cumpla ninguna de las condiciones anteriores */
    
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
