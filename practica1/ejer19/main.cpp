#include <iostream>
using namespace std;

/*
Desarrolle un procedimiento que reciba el costo en pesos de un abono telefónico,
 la cantidad de minutos libres que incluye el abono, el cargo en pesos por minuto
  excedente y la cantidad de minutos utilizados por un abonado, retorne la
  cantidad de minutos excedidos y el monto en pesos a abonar (costo del abono mas
    minutos excedidos por el costo de minutos excedidos) mas el 21% del valor del IVA.
    UTILICE FUNCIONES.
 */

void resumen_edesur(float, int, float, int);
float calc_extra_mins(float, int);
float iva(float);

int main()
{
    float cost = 100;
    int free_mins = 30;
    float cost_per_min = 2.50;
    int used_mins = 0;

    cout << "¿Cuántos minutos usaste, pibe?: ";
    cin >> used_mins;

    resumen_edesur(cost, free_mins, cost_per_min, used_mins);
    return 0;
}

void resumen_edesur(float cost, int free_mins, float cost_per_min, int used_mins)
{
    float total_cost, exceeded_mins_cost;
    total_cost = exceeded_mins_cost = 0;

    int exceeded_mins = (free_mins >= used_mins) ? 0 : used_mins - free_mins;
    cost = (cost > 0) ? cost : 1;

    exceeded_mins_cost = calc_extra_mins(cost_per_min, exceeded_mins);

    total_cost = cost + exceeded_mins_cost;
    total_cost += iva(total_cost);

    cout << "El cliente se excedio por " << exceeded_mins << " minutos. El coste total del servicio es de $" << total_cost << endl;
}

float iva(float gross)
{
    return (gross / 100) * 21;
}

float calc_extra_mins(float cost_per_min, int mins)
{
    if (cost_per_min > 0 && mins > 0)
        return (mins * cost_per_min);
    return 0;
}
