#include <iostream>
#include <cstring>
using namespace std;
// una empresa vende motos en la calle, cada una tiene id del 100 al 110, id del chofer, patente, kms acumulados.
// Los choferes tienen id del 1 al 12, nombre y kms acumulados.
// Se pide ingresar los movimientos del día hasta que se cargue un km igual a 0.
// Para los viajes se pide el id de moto, los datos de kms recorridos, el valor por km
// Actualizar los vectores con los km
// Calcular el importe total a facturar

struct Motorbike
{
    int id;
    int rider_id;
    char license_plate[10 + 1];
    int stacked_kms;
};

Motorbike new_motorbike(int id)
{
    Motorbike m;

    m.id = id;
    cout << "Ingrese los datos de la motocicleta ID " << id << endl;
    cout << "ID del chofer (1-12): ";
    cin >> m.rider_id;
    cout << "Patente: ";
    cin >> m.license_plate;
    cout << "Kms acumulados: ";
    cin >> m.stacked_kms;

    return m;
}

void sort_motorbikes(Motorbike (&arr)[10])
{
    int i = 1;
    Motorbike swap;
    for (i; i < 10; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1].id > arr[j].id)
        {
            swap = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = swap;
            j--;
        }
    }
}

struct Rider
{
    int id;
    char name[50 + 1];
    int stacked_kms;
};

Rider new_rider(int id)
{
    Rider r;

    r.id = id;
    cout << "Ingrese los datos del chofer ID " << id << endl;
    cout << "Nombre: ";
    cin >> r.name;
    cout << "Kms acumulados: ";
    cin >> r.stacked_kms;

    return r;
}

bool rider_has_motorbike(int rider_id, Motorbike arr[10])
{
    int i = 0;
    for (i; i < 10; i++)
    {
        if (arr[i].rider_id == rider_id)
            return true;
    }
    return false;
}

int main()
{

    Motorbike motorbikes[10] = {
        {102, 1, "333DDD", 0},
        {109, 3, "333DDD", 0},
        {107, 5, "333DDD", 0},
        {101, 7, "333DDD", 0},
        {100, 9, "333DDD", 0},
        {104, 9, "333DDD", 0},
        {102, 2, "333DDD", 0},
        {103, 4, "333DDD", 0},
        {106, 6, "333DDD", 0},
        {105, 8, "333DDD", 0},
    };
    Rider riders[12] = {
        {1, "Fabian 1", 0},
        {2, "Fabian 2", 0},
        {3, "Fabian 3", 0},
        {4, "Fabian 4", 0},
        {5, "Fabian 5", 0},
        {6, "Fabian 6", 0},
        {7, "Fabian 7", 0},
        {8, "Fabian 8", 0},
        {9, "Fabian 9", 0},
        {10, "Fabian 10", 0},
        {11, "Fabian 11", 0},
        {12, "Fabian 12", 0},
    };
    float total_amount = 0;
    bool not_zero = true;
    int i = 1;
    int kms;

    /* for (int i = 0; i < 12; i++)
    {
        riders[i] = new_rider(i + 1);
    }

    for (int i = 0; i < 10; i++)
    {
        motorbikes[i] = new_motorbike(i + 100);
    } */

    sort_motorbikes(motorbikes);

    while (kms > 0)
    {
        int motorbike_id;
        float price_per_km;

        cout << "Ingrese los datos del viaje (ingrese 0 o menos kms para salir)" << endl;
        cout << "Kms recorridos: ";
        cin >> kms;

        if (kms > 0)
        {
            cout << "ID de la motocicleta: ";
            cin >> motorbike_id;
            cout << "Precio por km: ";
            cin >> price_per_km;
            Motorbike m = motorbikes[motorbike_id - 100];
            if (rider_has_motorbike(m.rider_id, motorbikes))
            {
                int mb_id = motorbike_id - 100;
                int r_id = m.rider_id - 1;
                motorbikes[mb_id].stacked_kms += kms;
                riders[r_id].stacked_kms += kms;
                total_amount += kms * price_per_km;
            }
            else
            {
                cout << "La motocicleta no tiene un chofer asignado." << endl;
            }
            i++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        Motorbike m = motorbikes[i];
        cout << "La motocicleta ID " << m.id << " recorrió " << m.stacked_kms << " kms" << endl;
    }

    for (int i = 0; i < 12; i++)
    {
        Rider r = riders[i];
        cout << "El chofer ID " << r.id << " recorrió " << r.stacked_kms << " kms" << endl;
    }

    cout << "El total a facturar es de $" << total_amount << endl;

    return 0;
}
