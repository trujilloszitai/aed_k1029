#include <iostream>
using namespace std;

struct nodo {
  int info;
  nodo *sgte;
};

void push(nodo *&, int);
int pop(nodo *&);
void insertar_final(nodo *&, int);
void desapilar(nodo *&);
void reapilar(nodo *&, nodo *&);

int main() {
  nodo *pila = NULL;
  int ins = 22;
  int pos = 6;

  int val = 4;
  push(pila, val);
  val = 10;
  push(pila, val);
  val = 7;
  push(pila, val);
  val = 2;
  push(pila, val);
  val = 23;
  push(pila, val);

  insertar_final(pila, ins);
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

void insertar_final(nodo *&pila, int val) {
  int n;
  int insertado = false;
  nodo *aux = NULL;
  while (pila != NULL && insertado == false) {
    n = pop(pila);
    push(aux, n);

    if(pila == NULL)
    {
        push(pila, val);
        insertado = true;
        reapilar(pila, aux);
    }
  }
}

void desapilar(nodo *&pila) {
  int n;
  while (pila != NULL) {
    n = pop(pila);
    cout << n << endl;
  }
}

void reapilar(nodo *&pila, nodo *&aux) {
  while (aux != NULL)
    push(pila, pop(aux));
}
