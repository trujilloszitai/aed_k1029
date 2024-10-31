#include <cstring>
#include <iostream>
using namespace std;

struct colaInfo {
  int prioridad = 0;
  char paciente[100 + 1];
};

struct nodoC {
  colaInfo info;
  nodoC *sgte;
};

struct cola {
  nodoC *frente;
  nodoC *fin;
};

struct nodoL {
  cola info;
  nodoL *sgte;
};

int main() { return 0; }

nodoL* crearColaPrioridad() {
    int i = 0;
    nodoL* listaC = NULL;

    for (; i < 5; i++) {
        cola colaPrioridad;
        nodoC* nodoInicial = new nodoC();
        nodoInicial->info.prioridad = i;
        strcpy(nodoInicial->info.paciente, "");
        nodoInicial->sgte = NULL;
        colaPrioridad.fin = colaPrioridad.frente = nodoInicial;
        push(listaC, colaPrioridad);
    }

    return listaC;
};

void insertarEnPrioridad(nodoL*& lista, colaInfo info)
{

    nodoL* aux = lista;
    int prioridad = info.prioridad;
    int i = 0;
    while(aux->info.frente->info.prioridad != prioridad && aux != NULL) {
        aux = aux->sgte;
    }
    encolar(aux->info.frente, aux->info.fin, info);

}
