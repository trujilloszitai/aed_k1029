#include <iostream>

using namespace std;

int main()
{
    int N = 0;
    int nums[30] = {0};

    while (N<=0 && N<30)
    {
        cout << "Ingrese un número N menor que 30 y distinto de 0: ";
        cin >> N;
    }

    for (int i = 1; i <= N; i++)
    {
        nums[i-1] = i * 2;
    }

    for (int i = 0; i < N; i++)
    {
        cout << nums[i] << endl;
    }

    return 0;
}