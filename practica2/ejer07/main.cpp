#include <iostream>
using namespace std;

struct Alumno
{
    char legajo[10 + 1];
    int nota;
};

struct Curso
{
    char codigo[4 + 1] = "";
    Alumno alumnos[20] = {
        {"", 0}};
};

void informe_curso(Curso, int, int[], int, int);

int main()
{
    int largo = 20;
    int i = 0;
    int cant_alumnos;

    Curso cursos[largo];

    do
    {
        Curso c;
        cout << "Curso " << i + 1 << endl;
        cout << "Codigo: ";
        cin >> c.codigo;
        cout << "Cantidad de alumnos " << i + 1 << ": ";
        cin >> cant_alumnos;

        if (cant_alumnos > 0 && cant_alumnos < 21)
        {
            int cant_notas[10] = {0};
            int aprobados = 0;
            int desaprobados = 0;
            int nota;

            int j = 0;
            Alumno a;
            do
            {
                cout << "Alumno " << j + 1 << endl;
                cout << "Legajo: ";
                cin >> a.legajo;
                cout << "Nota: ";
                cin >> nota;

                if (nota > 0 && nota < 11)
                {
                    a.nota = nota;
                    cursos[i].alumnos[j] = a;
                    cant_notas[a.nota - 1]++;
                    nota >= 6 ? aprobados++ : desaprobados++;
                }
                j++;
            } while (nota > 0 && nota < 11 && j < cant_alumnos);

            informe_curso(c, i + 1, cant_notas, aprobados, desaprobados);
        }
        i++;
    } while (cant_alumnos > 0 && cant_alumnos < 21 && i < largo);
    return 0;
}

void informe_curso(Curso c, int i, int cant_notas[], int aprobados, int desaprobados)
{
    cout << "Informe del curso " << i << ": " << endl;
    for (int j = 0; j < 10; j++)
    {
        if (cant_notas[j] != 0) cout << cant_notas[j] << " alumnos sacaron " << j + 1 << endl;
    }

    int tasa_aprobados = aprobados / float(aprobados + desaprobados) * 100;
    int tasa_desaprobados = desaprobados / float(aprobados + desaprobados) * 100;

    cout << "El " << tasa_aprobados << "% del curso aprobó" << endl;
    cout << "El " << tasa_desaprobados << "% del curso desaprobó" << endl;
}
