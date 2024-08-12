#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Alumno
{
    int legajo;
    char nombre[50 + 1];
};

int main()
{
    // Archivos binarios de estructura, siempre se necesita un struct para leer su estructura
    Alumno al;
    FILE *f = fopen("alumnos.bin", "wb"); // puede ser rb, wb, rb+, wb+

    al.legajo = 111;
    strcpy(al.nombre, "Francisco");

    fwrite(&al, sizeof(Alumno), 1, f);
    f = fopen("alumnos.bin", "rb");
    fclose(f);
    return 0;
}

void leerArchivo(FILE*& f,...)
{
    Alumno al;
    /* fread(&al, sizeof(Alumno), 1, f);
    while(!feof(f)) // Mientras la lectura no llegue a la marca de fin de archivo
    {
        cout << "Legajo: " << al.legajo << endl;
        cout << "Nombre: " << al.nombre << endl;
        fread(&al, sizeof(Alumno), 1, f);
    } */

    while (fread(&al, sizeof(Alumno), 1, f)) // Mientras la lectura no llegue a la marca de fin de archivo
    {
        cout << "Legajo: " << al.legajo << endl;
        cout << "Nombre: " << al.nombre << endl;
    }
}