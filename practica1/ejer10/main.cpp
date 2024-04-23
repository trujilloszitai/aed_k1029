#include <iostream>
using namespace std;

int main()
{
  bool end = false;
  int earn_less_1520, earn_less_2780, earn_less_5999, earn_more_5999;
  earn_less_1520 = earn_less_2780 = earn_less_5999 = earn_more_5999 = 0;
  int i = 0;

  while (!end)
  {
    float salary = 0;
    i++;

    cout << "Ingrese el salario del empleado " << i << ": ";
    cin >> salary;

    if (salary > 0 && salary < 1520) earn_less_1520++;
    else if (salary >= 1520 && salary < 2780) earn_less_2780++;
    else if (salary >= 2780 && salary < 5999) earn_less_5999++;
    else if (salary >= 5999) earn_more_5999++;
    else end = true;
  }

  if (earn_less_1520 == 0) cout << "No hay empleados que ganen menos de $1520" << endl;
  else cout << "Hay " << earn_less_1520 << " empleado/s que ganan menos de $1520" << endl;
  if (earn_less_2780 == 0) cout << "No hay empleados que ganen $1520 o más pero menos de $2780" << endl;
  else cout << "Hay " << earn_less_2780 << " empleado/s que ganan $1520 o más pero menos de $2780" << endl;
  if (earn_less_5999 == 0) cout << "No hay empleados que ganen $2780 o más pero menos de $5999" << endl;
  else cout << "Hay " << earn_less_5999 << " empleado/s que ganan $2780 o más pero menos de $5999" << endl;
  if (earn_more_5999 == 0) cout << "No hay empleados que ganen $5999 o más" << endl;
  else cout << "Hay " << earn_more_5999 << " empleado/s que ganan $5999 o más" << endl;

  return 0;
}
