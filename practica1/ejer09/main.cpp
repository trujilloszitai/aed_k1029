#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    /* Se realiza una inspección en una fábrica de pinturas, 
    y se detectaron 20 infracciones. 
    De cada infracción se tomó nota de los siguientes datos:
- Tipo de Infracción (1, 2, 3, o 4)
- Motivo de la Infracción
- Valor de la multa (un entero)
- Gravedad de la infracción (‘L’,‘M’, ‘G’)
Se pide informar al final del proceso:
• Los valores totales de la multa a pagar de acuerdo al tipo de gravedad.
• La leyenda “Clausurar fabrica” si la cantidad de infracciones 3 y 4 con gravedad “G” sean mayor a 3. */

    int length = 5;
    int fine_l, fine_m, fine_g, fatal_infringements;
    fine_l = fine_m = fine_g = fatal_infringements = 0;
    int i = 0;

    // Ingreso de infracciones
    for (i; i < length; i++)
    {
        int lap = i + 1;
        int type, fine = 0;
        char severity;
        // string reason = "";

        cout << "Ingrese el tipo de la infracción " << lap << " (1, 2, 3, 4): ";
        cin >> type;
        /* cout << "Ingrese el motivo de la infracción " << lap << ": ";
        cin >> reason; */
        cout << "Ingrese el valor de la multa por la infracción " << lap << ": ";
        cin >> fine;
        cout << "Ingrese la gravedad de la infracción " << lap << " ('L', 'M', 'G'): ";
        cin >> severity;

        if (severity == 'L' || severity == 'l')
        {
            fine_l += fine;
        }
        else if (severity == 'M' || severity == 'm')
        {
            fine_m += fine;
        }
        else if (severity == 'G' || severity == 'g')
        {
            fine_g += fine;
            if (type == 3 || type == 4)
            {
                fatal_infringements++;
            }
        }
    }

    // Reporte de infracciones
    if (fine_l == 0)
    {
        cout << "No hay infracciones de gravedad 'L'" << endl;
    }
    else
    {
        cout << "Las infracciones de la gravedad 'L' suman un valor de multa de " << fine_l << endl;
    }
    if (fine_m == 0)
    {
        cout << "No hay infracciones de gravedad 'M'" << endl;
    }
    else
    {
        cout << "Las infracciones de la gravedad 'M' suman un valor de multa de " << fine_m << endl;
    }
    if (fine_g == 0)
    {
        cout << "No hay infracciones de gravedad 'M'" << endl;
    }
    else
    {
        cout << "Las infracciones de la gravedad 'G' suman un valor de multa de " << fine_g << endl;
    }

    // Aviso de clausura
    if (fatal_infringements > 3)
    {
        cout << "CLASURAR FÁBRICA MUERTE INEVITABLE gracias" << endl;
    }
    else
    {
        cout << "Está todo bien ^_^" << endl;
    }

    return 0;
}
