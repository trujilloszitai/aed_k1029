#include <iostream>
using namespace std;

struct Alumno
{
    char codigo_curso[5+1];
    char legajo[10 + 1];
    int nota;
};

struct Curso
{
    char codigo[5 + 1] = "";
    int cantidad_alumnos = 20;
    int notas[10] = {0};
};

void informar_notas(char[], int[]);
void informar_tasa_aprobacion(char[], int, int);

int main()
{
    const int largo = 20;
    int i = 0;
    int cant_alumnos;
    int cant_cursos = 4;
    int alumnos_totales = 0;
    Curso cursos[largo] = {
        {"K1011", 3},
        {"K1012", 4},
        {"K1013", 5},
        {"K1014", 6},
    };
    int tasa_aprobacion[4][2];

    for (int i = 0; i < 4; i++) alumnos_totales += cursos[i].cantidad_alumnos;
    

    do
    {
        Curso curso = cursos[i];
        const int alumnos_x_curso = curso.cantidad_alumnos;
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
                curso.notas[a.nota - 1]++;
                nota >= 6 ? aprobados++ : desaprobados++;
            }
            j++;
        } while (nota > 0 && nota < 11 && j < curso.cantidad_alumnos);

        tasa_aprobacion[i][0] = aprobados;
        tasa_aprobacion[i][1] = desaprobados;
        informar_notas(curso.codigo, curso.notas);

        i++;
    } while (i < cant_cursos);
    
    return 0;
}

void informar_notas(char codigo[], int cant_notas[])
{
    cout << "Notas del curso " << codigo << ": " << endl;
    for (int j = 0; j < 10; j++)
    {
        if (cant_notas[j] != 0)
            cout << cant_notas[j] << " alumnos sacaron " << j + 1 << endl;
    }
}

void informar_tasa_aprobacion(char codigo[], int aprobados, int desaprobados)
{
        int tasa_aprobados = aprobados / float(aprobados + desaprobados) * 100;
    int tasa_desaprobados = desaprobados / float(aprobados + desaprobados) * 100;

    cout << "Tasa de aprobación del curso " << codigo << ": " << endl;
    cout << "El " << tasa_aprobados << "% del curso aprobó" << endl;
    cout << "El " << tasa_desaprobados << "% del curso desaprobó" << endl;
}