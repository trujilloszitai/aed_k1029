#include <iostream>
#include <cstring>
using namespace std;

struct Trabajo
{
    char titulo[50 + 1];
    int categoria;
    int fechaPresentacion;
    char correoResp[50 + 1];
    int idEvaluadores[3];
    int resultado[3];
};

struct Evaluador {
    int id;
    int categoria;
    char nombre[50+1];
};

struct Dictamen
{
    int aspFormales;
    int cyt;
    int autores;
    bool rechazado;
};

struct nodoT {
    Trabajo info;
    nodoT* sgte;
};

nodoT* leerArchivoTrabajos(FILE *f) {
    Trabajo t;
    nodoT* lista = NULL;
    while(fread(&t, sizeof(Trabajo), 1, f)){
        push(lista, t);
    }
    return lista;
}

void leerArchivoEvaluadores(FILE* f, Evaluador evaluadores[]) {
    Evaluador e;
    int i = 0;
    for (i; i < 100; i++)
    {
    if (fread(&evaluadores[i], sizeof(Evaluador), 1, f) != 1) {
        return;
    }
    }

}



void guardarArchivoTrabajos(FILE *f, nodoT* listaT) {
    nodoT* lista = listaT;
    fseek(f, 0, SEEK_SET);
    while(lista != NULL) {
        Trabajo t = lista->info;
        fwrite(&t, sizeof(Trabajo), 1, f);
        lista = lista->sgte;
    }
    fclose(f);
}

void insertarTrabajoOrdenado(nodoT*& lista, Trabajo trabajo)
{
    nodoT* temp = NULL;
    temp->info = trabajo;
    temp->sgte = NULL;

    if(lista == NULL || lista->info.categoria > trabajo.categoria || (lista->info.categoria == trabajo.categoria && lista->info.fechaPresentacion > trabajo.fechaPresentacion)) {
        temp->sgte = lista;
        lista = temp;
    } else {
        nodoT* actual = lista;
        while(actual->sgte != NULL && actual->sgte->info.categoria < trabajo.categoria || (actual->sgte->info.categoria == trabajo.categoria && actual->sgte->info.fechaPresentacion <= trabajo.fechaPresentacion)) {
            actual = actual->sgte;
        }
        temp->sgte = actual->sgte;
        actual->sgte = temp;
    }
}

void presentacionTrabajos (FILE* fTrabajos)
{
    nodoT* listaTrabajos = leerArchivoTrabajos(fTrabajos);
    int i = 0;
    for (i; i < 5; i++)
    {
        int dia = i + 1;
        int categoria, nTrabajo;
        cout << "Dia " << dia << " de presentaciones" << endl;
        while (dia == i + 1)
        {
            Trabajo t;
            cout << "Trabajo n°" << nTrabajo << endl;
            cout << "Titulo: ";
            cin >> t.titulo;
            cout << "Categoria: ";
            cin >> t.categoria;
            cout << "Fecha de presentacion: ";
            cin >> t.fechaPresentacion;
            if (categoria < 1 && categoria > 5)
            {
                categoria = t.categoria;
            }
            else {
                if(categoria != t.categoria) {
                    dia++;
                }
            }
            insertarTrabajoOrdenado(listaTrabajos, t);
        }
        guardarArchivoTrabajos(fTrabajos, listaTrabajos);
    }
};

void derivarEvaluadores(FILE* fTrabajos)
{
    int evaluadoresPorCategoria = 100 / 5; 
    nodoT* listaT = leerArchivoTrabajos(fTrabajos);

}