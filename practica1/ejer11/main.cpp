#include <iostream>
using namespace std;

int main()
{
    // Dados N valores informar el mayor, el menor y en que posición del conjunto fueron ingresados.
    int length, largest, lowest, lg_index, lw_index;
    length = largest = lowest = lg_index = lw_index = 0;

    cout << "Indique la cantidad de valores a ingresar:";
    cin >> length;

    if (length > 0)
    {
        int i = 1;
        for (i; i <= length; i++)
        {
            int value = 0;
            cout << "Ingrese el valor n°" << i << ": ";
            cin >> value;

            if (i == 1)
            {
                largest = lowest = value;
                lg_index = lw_index = i;
            }
            else
            {
                if (value > largest)
                {
                    largest = value;
                    lg_index = i;
                }
                else if (value < lowest)
                {
                    lowest = value;
                    lw_index = i;
                }
            }
        }

        cout << "El máximo valor ingresado es " << largest << ". Corresponde al elemento n°" << lg_index << " del conjunto" << endl;
        cout << "El menor valor ingresado es " << lowest << ". Corresponde al elemento n°" << lw_index << " del conjunto" << endl;
    }
    else
    {
        cout << "El conjunto de valores debe tener al menos un (1) elemento" << endl;
    }

    return 0;
}
