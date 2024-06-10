#include <iostream>
using namespace std;

int main()
{
    int N;
    int nums[99] = {0};
    int lowestValue;
    int lowestValuesIndex[99] = {-1};
    int oddValuesProductInPairIndex = 0;
    int i = 0; 

    while (N != 0)
    {
        cout << "Ingrese un número N (entero): ";
        cin >> N;

        if (i == 0) lowestValue = N;
        else {
            if (N == lowestValue)
            {
                lowestValuesIndex[i] = i;
            }
        }
    }

    return 0;
}
