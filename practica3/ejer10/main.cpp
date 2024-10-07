#include <iostream>
using namespace std;

struct Alumno {
    int legajo = 0;
    char nombreCompleto[30+1] = "";
    char domicilio[20+1] = "";
    int codigoPostal = 0;
    int telefono = 0;
    int añoIngreso = 0;
};

struct Operacion {
    char codigo;
    Alumno datos;
};

int main() {
    Alumno alumnos[10] = {
        {22211121, "Sanchez Lilly", "Norway", 6397, 1114190705, 2015},
        {22211122, "Malone Della", "Vatican City", 3205, 1188904993, 2018},
        {22211123, "Fisher Angel", "Cuba", 7966, 1143964049, 2021},
        {22211124, "Holmes Evelyn", "South Georgia", 640, 1164877417, 2019},
        {22211125, "Rios Gordon", "Mexico", 5920, 1169104514, 2003},
        {22211126, "Carson Travis", "Serbia", 1792, 1154743246, 2023},
        {22211127, "Powers Millie", "Turkey", 8640, 1121013186, 2003},
        {22211128, "Tyler Gary", "Syria", 8462, 1156049631, 2006},
        {22211129, "Bryant Jack", "Åland Islands", 3707, 1194037380, 2011},
        {22211120, "Cook Mike", "Lebanon", 9507, 1103789722, 2012},
    };
    Operacion operaciones[100];
    int cantidad = 10;
    int i = 0;

    FILE *f = fopen("ALUMNOS.dat", "wb");

    while(i < cantidad)
    {
        Alumno al = alumnos[i];
        fwrite(&al, sizeof(Alumno), 1, f);
        i++;
    }



    return 0;
}

int cantReg(FILE*& f)
{
	//preservar la posicion actual
	int posActual=ftell(f);
	fseek(f,0,SEEK_END);
	int desplaz=ftell(f);
	int cantidad=desplaz/sizeof(Alumno);
	//vuelvo el puntero a donde estaba
	fseek(f,posActual,SEEK_SET);
	return cantidad;
}

void ordenar_alumnos(Alumno v[], int N, bool asc)
{
    int i, j;
    Alumno aux;
    bool compare;
    for (i = 1; i < N; i++) // pasos
    {
        for (j = 1; j <= N - i; j++) // comparaciones
        {
            compare = asc ? v[j - 1].legajo > v[j].legajo : v[j - 1].legajo < v[j].legajo;

            if (compare) // condicion a cumplir para intercambio
            {                          // intercambio
                aux = v[j - 1];
                v[j - 1] = v[j];
                v[j] = aux;
            }
        }
    }
}
