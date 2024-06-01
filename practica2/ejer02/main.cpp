#include <iostream>
using namespace std;

int lastNumberIsLowerThan10 (int nums[], int length);

int main()
{
    int N = 0;
    int nums[30] = {0};
    bool printNegatives = false;

    while (N <= 0 && N < 30)
    {
        cout << "Ingrese un número N (entero) menor que 30 y distinto de 0: ";
        cin >> N;
    }

    for (int i=0; i < N; i++) {
        cout << "Ingrese el valor (entero) n°" << i+1 << ": ";
        cin >> nums[i];
    }

    if (lastNumberIsLowerThan10(nums, N)) printNegatives = true;

    for (int i=0; i<N; i++)
    {
        if (printNegatives && nums[i] < 0)
        {
            cout << nums[i] << endl;
        }
        else
        {
            if (nums[i] >= 0 && !printNegatives) cout << nums[i] << endl;
        }
    }
    
    return 0;
}

int lastNumberIsLowerThan10 (int nums[], int length)
{
    return nums[length-1] < 10;
}
