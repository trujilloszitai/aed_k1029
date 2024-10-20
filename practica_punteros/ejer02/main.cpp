#include <iostream>
using namespace std;

struct nodo {
  int info;
  nodo *sgte;
};

void push(nodo*&, int);
int pop(nodo*&);
void insertar(nodo*&, int, int);
void desapilar(nodo*&);
void reapilar(nodo*&, nodo*&);

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

  insertar(pila, ins, pos);
  desapilar(pila);

  return 0;
}

void push(nodo*& pila, int val) {
  nodo *p = new nodo();
  p->info = val;
  p->sgte = pila;
  pila = p;
}

int pop(nodo*& pila) {
  int val;
  nodo *p = pila;
  val = p->info;
  pila = p->sgte;
  delete p;

  return val;
}

void insertar(nodo*& pila, int val, int posicion) {
  int cont = 0;
  int n;
  int insertado = false;
  nodo *aux = NULL;
  while (pila != NULL && insertado == false) {
    if (cont == posicion - 1) {
      push(pila, val);
      insertado = true;
      reapilar(pila, aux);
    } else {
      n = pop(pila);
      push(aux, n);
    }
    cont++;
  }
  if (insertado == false) {
    reapilar(pila, aux);
  }
}

void desapilar(nodo*& pila) {
  int n;
  while (pila != NULL) {
    n = pop(pila);
    cout << n << endl;
  }
}

void reapilar(nodo*& pila, nodo*& aux) {
  while (aux != NULL)
    push(pila, pop(aux));
}
