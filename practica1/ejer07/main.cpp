#include <iostream>
using namespace std;

int main()
{
    /* Calcular la velocidad (metros/segundo) de los participantes de
    una carrera de 1500mts dado el tiempo en segundos en recorrerla y
    determinar el nombre del mas veloz. Y si el tiempo fuera en minutos + segundos? */
    int distance = 1500;
    int winner_speed = 0;
    string winner_name = "";
    int runners_times[3] = {
        0,
        0,
        0,
    };
    const int times_size = sizeof(runners_times) / sizeof(int);
    string runners_names[times_size] = {
        "",
        "",
        "",
    };

    for (int i = 0; i < times_size; i++)
    {
        cout << "Ingrese el nombre del corredor " << i + 1 << ": ";
        cin >> runners_names[i];
        cout << "Ingrese el tiempo en segundos del corredor " << i + 1 << ": ";
        cin >> runners_times[i];

        string name = runners_names[i];
        int time = runners_times[i];
        int speed = distance / time;

        if (speed > winner_speed)
        {
            winner_speed = speed;
            winner_name = name;
        }
    }

    cout << "El corredor mas veloz es " << winner_name << " con una velocidad de " << winner_speed << " m/s" << endl;

    return 0;
}
