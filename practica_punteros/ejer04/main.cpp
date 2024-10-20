#include <iostream>
using namespace std;

struct nodo {
  int info;
  nodo *sgte;
};

void push(nodo *&, int);
int pop(nodo *&);
void reemplazar(nodo *&, int, int);
void desapilar(nodo *&);
void reapilar(nodo *&, nodo *&);
void recorrer_pila(nodo *&);

int main() {
  nodo *pila = NULL;
  int ins = 22;
  int x = 10;
  int y = 5;
  int val = 4;
  push(pila, val);
  val = 10;
  push(pila, val);
  val = 7;
  push(pila, val);
  val = 10;
  push(pila, val);
  val = 10;
  push(pila, val);

  cout << "Fila antes:" << endl;
  recorrer_pila(pila);
  cout << "Reemplazando..." << endl;
  reemplazar(pila, x, y);
  cout << "Fila después:" << endl;
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

void reemplazar(nodo *&pila, int x, int y) {
  int n;
  int insertado = false;
  nodo *aux = NULL;
  while (pila != NULL) {
    n = pop(pila);
    if(n == x) push(aux, y);
    else push(aux, n);
  }
  reapilar(pila, aux);
}

void desapilar(nodo *&pila) {
  int n;
  while (pila != NULL) {
    n = pop(pila);
    cout << n << endl;
  }
}

void recorrer_pila(nodo *&pila)
{
    int n;
    nodo* aux = NULL;
    while (pila != NULL) {
      n = pop(pila);
      push(aux, n);
      cout << n << endl;
    }
    reapilar(pila, aux);
}

void reapilar(nodo *&pila, nodo *&aux) {
  while (aux != NULL)
    push(pila, pop(aux));
}
