#include <iostream>

using namespace std;

void showResults(int res[11]);

int main()
{
    /*
Escriba un programa que permita ingresar la tirada de un par de dados 50 veces
y muestre una lista donde se vea cuántas veces se dio cada uno de los resultados posibles.
Por cada tirada se deberán ingresar 2 valores, cada uno representa el valor de un dado.
El formato de la salida debe ser el siguiente:
2 salió ... veces
3 salió ... veces
. . 12 salió ... veces
 */
    const int N = 5;
    int i = 0;
    /* int dice1[N];
    int dice2[N]; */

    int results[11] = {0};

    for (i; i < N; i++)
    {
        int value1, value2, combination;
        value1 = value2 = combination = 0;

        cout << "Tiro " << i + 1 << endl;
        while (value1 > 6 || value1 <= 0)
        {
            cout << "Valor del dado 1 (de 1  a 6 ):";
            cin >> value1;
        }
        while (value2 > 6 || value2 <= 0)
        {
            cout << "Valor del dado 2 (de 1  a 6 ):";
            cin >> value2;
        }

        combination = value1 + value2;
        int combinationIndex = combination - 2;

        results[combinationIndex]++;
    }

    showResults(results);

    return 0;
}

void showResults(int res[11])
{
    int i = 0;

    for (i; i < 11; i++)
    {
        cout << "La combinacion '" << i+2 << "' salio " << res[i] << " veces." << endl;
    }
}