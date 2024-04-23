#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char older_name[50] = "";
    char younger_name[50] = "";
    int older_bd, younger_bd;
    older_bd = younger_bd = 0;
    bool end = false;

    int i = 1;
    while (!end)
    {
        char name[50] = "";
        int birthdate = 0;

        cout << "Ingrese el nombre de la persona n°" << i << ": ";
        cin >> name;
        if (strcmp(name, "FIN") == 0 || strcmp(name, "fin") == 0)
            end = true;
        else
        {
            cout << "Ingrese la edad de la persona n°" << i << ": ";
            cin >> birthdate;
            if (i == 1)
            {
                strcpy(younger_name, name);
                strcpy(older_name, name);
                older_bd = younger_bd = birthdate;
            }
            else
            {
                if (birthdate < older_bd)
                {
                    strcpy(older_name, name);
                    older_bd = birthdate;
                }
                else if (birthdate > younger_bd)
                {
                    strcpy(younger_name, name);
                    younger_bd = birthdate;
                }
            }
            i++;
        }
    }

    if (i == 1)
        cout << "No se han ingresado datos." << endl;
    else if (i == 2)
    {
        cout << older_name << " es la persona más vieja y a la vez, la más joven." << endl;
    }
    else
    {
        cout << older_name << " es la persona más vieja (se siente feo decir eso, no sé por qué)." << endl;
        cout << younger_name << " es la persona más joven (eso no)." << endl;
    }

    return 0;
}
