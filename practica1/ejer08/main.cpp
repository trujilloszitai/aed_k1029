#include <iostream>
#include <cstdlib> 
using namespace std;

int main()
{
    // Dados 50 números enteros, informar el promedio de los mayores que 100 y la suma de los menores que -10.
    int greater_than_100_sum = 0;
    int greater_than_100_count = 0;
    int gt100_avg = 0;
    int lower_than_minus10_sum = 0;
    int length = 50;
    int i = 0;

    for (i; i < length; i++)
    {
        int number = rand() % 200 - 50;
        if (number > 100)
        {
            greater_than_100_sum += number;
            greater_than_100_count++;
        }
        else if (number < -10)
        {
            lower_than_minus10_sum += number;
        }
    }

    gt100_avg = greater_than_100_sum / greater_than_100_count;

    cout << "El promedio de los números mayores que 100 es " << gt100_avg << endl;
    cout << "La suma de los números menores que -10 es " << lower_than_minus10_sum << endl;
    return 0;
}
