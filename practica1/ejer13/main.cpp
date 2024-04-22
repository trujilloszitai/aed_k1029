#include <iostream>
using namespace std;

int main()
{
    /* Dado un conjunto de valores, que finaliza con un valor nulo, determinar e imprimir (si hubo valores):
∙ El valor máximo negativo
∙ El valor mínimo positivo
∙ El valor mínimo dentro del rango -17.3 y 26.9
∙ El promedio de todos los valores. */
    float numbers[10] = {
        60.3,
        23.45,
        -1.7,
        7.81,
        -15.75,
        -70.45,
        -12.1,
        33.3,
        -14.6,
        0.0,
    };
    float left_limit = -17.3;
    float right_limit = 26.9;
    float max_negative = 0;
    float min_positive = 0;
    float min_in_range = 0;

    int length = sizeof(numbers) / sizeof(float);
    int i = 0;
    bool has_values = true;

    while (has_values)
    {
        float number = numbers[i];
        if (number == 0 || i == length || number == 0.0)
        {
            has_values = false;
        }
        else if (i == 0)
        {
            max_negative = (number < 0) ? number : 0;
            min_positive = (number > 0) ? number : 0;
        }
        else
        {
            if (number < 0 && number < max_negative)
            {
                max_negative = number;
            }
            else if (number > 0 && number < min_positive)
            {
                min_positive = number;
            }
        }
        if (number >= left_limit && number <= right_limit)
        {
            if (number < min_in_range || min_in_range == 0)
            {
                min_in_range = number;
            }
        }
        i++;
    }

    if (max_negative == 0)
    {
        cout << "No se ingresaron valores negativos" << endl;
    }
    else
    {
        cout << "El valor máximo negativo es " << max_negative << endl;
    }

    if (min_positive == 0)
    {
        cout << "No se ingresaron valores positivos" << endl;
    }
    else
    {
        cout << "El valor mínimo positivo es " << min_positive << endl;
    }

    if (min_in_range == 0)
    {
        cout << "No hubo valores en el rango [-17.3; 26.9]" << endl;
    }
    else
    {
        cout << "El valor mínimo dentro del rango [-17.3; 26.9] es " << min_in_range << endl;
    }
    return 0;
}
