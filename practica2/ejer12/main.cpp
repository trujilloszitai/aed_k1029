#include <iostream>
#include <cstring>
using namespace std;


struct Fecha
{
    int dia = 0;
    int mes = 0;
    int anio = 0;
};

struct Registro
{
    char nombre[20+1] = "";
    Fecha fechaNacimiento;
    
};

struct ApellidoNombre
{
    char apellido[20+1] = "";
    char nombre[20+1] = "";
};

struct Calificaciones
{
    int nota1 = 0;
    int nota2 = 0;
    int nota3 = 0;
};

struct Alumno
{
    int legajo = 0;
    ApellidoNombre an;
    Calificaciones cal;
};

int buscar_alumno(Alumno[], int, int);

int main() {
    Registro regs[20];
    Alumno alus[20];

    //a
    cout << regs[8].fechaNacimiento.dia << endl;
    //b
    cout << regs[0].nombre << endl;
    //c
    cout << buscar_alumno(alus, 20, 456789);
    //d
    int i = buscarAlumnoPorApellido(alus, 20, "xxxxx");
    Alumno al = alus[i];
    cout << al.legajo << endl;
    cout << al.an.nombre << endl;
    cout << al.an.apellido << endl;
    cout << al.cal.nota1 << endl;
    cout << al.cal.nota2 << endl;
    cout << al.cal.nota3 << endl;


    return 0;
}

int buscar_alumno(Alumno v[], int N, int legajo)
{
    int izq = 0;
    int der = N - 1;
    while (izq <= der)
    {
        int medio = (izq + der) / 2;
        int valor = v[medio].legajo;
        if (valor == legajo)
        {
            return medio;
        }
        else if (valor < legajo)
        {
            izq = medio + 1;
        }
        else
        {
            der = medio - 1;
        }
    }

    return -1;
}

int buscarAlumnoPorApellido(Alumno v[], int N, char apellido[20+1])
{
    int i = 0;
    while(strcmp(v[i].an.apellido, apellido) != 0)
    {
        i++;
        if(i >= N) return -1;
    }
    return i;
}