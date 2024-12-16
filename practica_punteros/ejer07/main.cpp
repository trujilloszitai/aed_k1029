#include <iostream>
using namespace std;

struct nodo {
  int info;
  nodo *sgte;
};

void push(nodo *&, int);
int pop(nodo *&);
void desapilar(nodo *&);
void invertir(nodo *&, nodo *&);
void recorrer_pila(nodo *&);
nodo *invertir(nodo *&);
void insertar_final(nodo *&, int);
void ordenar_pila(nodo *&, bool);

int main() {
  nodo *pila = NULL;
  push(pila, 15);
  push(pila, 79);
  push(pila, 36);
  push(pila, 34);
  push(pila, 65);
  push(pila, 2);

  ordenar_pila(pila, true);

  desapilar(pila);

  return 0;
}

void push(nodo *&pila, int val) {
  nodo *p = new nodo();
  p->info = val;
  p->sgte = pila;
  pila = p;
}

int pop(nodo *&pila) {
  int val;
  nodo *p = pila;
  val = p->info;
  pila = p->sgte;
  delete p;

  return val;
}

int cabeza(nodo *&pila) { return pila->info; }

void desapilar(nodo *&pila) {
  int n;
  while (pila != NULL) {
    n = pop(pila);
    cout << n << endl;
  }
}

void recorrerPila(nodo *&pila) {
  int n;
  nodo *aux = NULL;
  while (pila != NULL) {
    n = pop(pila);
    push(aux, n);
    cout << n << endl;
  }
  pila = invertir(aux);
}

nodo *invertir(nodo *&pila) {
  nodo *aux = NULL;
  while (pila != NULL) {
    push(aux, pop(pila));
  }
  return aux;
}

void insertarFinal(nodo *&pila, int val) {
  int n;
  nodo *aux = NULL;
  while (pila != NULL) {
    n = pop(pila);
    push(aux, n);
  }
  push(pila, val);
  pila = invertir(aux);
}

int size(nodo *pila) {
  int n = 0;
  nodo *aux = pila;
  while (aux != NULL) {
    n++;
    aux = aux->sgte;
  }
  return n;
}

void ordenar_pila(nodo *&pila, bool asc) {
  nodo *aux = NULL;

  while (pila != NULL) {
    int val = pop(pila);

    while (aux != NULL && cabeza(aux) < val) {
      push(pila, pop(aux));
    }

    push(aux, val);
  }

  pila = aux;
}
