#include <iostream>
using namespace std;

/**
 * @brief  Recibe 3 valores enteros y determina si se trata de un triángulo.
 * 
 * @param  s1:  Primer lado
 * @param  s2:  Segundo lado
 * @param  s3: Tercer lado
 * 
 * @return false
 */
bool is_triangle(int s1, int s2, int s3)
{
    return (s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1);
}

/**
 * @brief  Recibe 3 valores enteros y determina si se trata de un triángulo equilátero, isósceles o escaleno.
 * 
 * Long description
 * 
 * @param  s1:  Primer lado
 * @param  s2:  Segundo lado
 * @param  s3: Tercer lado
 * 
 * @return int. 0 si es equilátero, -1 si es isósceles y 1 si es escaleno.
 */
int triangle_type(int s1, int s2, int s3)
{
    if (s1 == s2 && s2 == s3)
    {
        return 0;
    }
    else if (s1 == s2 || s1 == s3 || s2 == s3)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int main()
{
    // La funcion principal recibe 3 valores que representan los lados de una figura: determinar, en caso de ser un triangulo, de qué tipo se trata

    int s1, s2, s3, res;
    s1 = s2 = s3 = 0;
    cout << "HOLA USUARIO. A continuación deberá ingresar por teclado los tres valores que representan a los lados de una figura. Si se llega a determinar que es un triángulo, veremos si es equilátero, isósceles o escaleno." << endl;
    cout << "Ingrese el primer valor: ";
    cin >> s1;
    cout << "Ingrese el segundo valor: ";
    cin >> s2;
    cout << "Ingrese el terecer valor: ";
    cin >> s3;

    if (is_triangle(s1, s2, s3))
    {
        res = triangle_type(s1, s2, s3);
        switch (res)
        {
        case -1:
            cout << "Los valores ingresados forman un triángulo isósceles." << endl;
            break;
        case 0:
            cout << "Los valores ingresados forman un triángulo equilátero." << endl;
            break;
        case 1:
            cout << "Los valores ingresados forman un triángulo escaleno." << endl;
            break;
        default:
            break;
        }
    }
    else
    {
        cout << "Los valores ingresados no forman un triángulo." << endl;
    }
}
