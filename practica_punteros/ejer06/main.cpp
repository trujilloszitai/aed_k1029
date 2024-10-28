#include <cstddef>
#include <iostream>
using namespace std;

struct Alumno
{
    char nombre[50+1] = "";
    char apellido[50+1] = "";
};

struct nodo {
  Alumno info;
  nodo *sgte;
};

void push(nodo *&, Alumno);
Alumno pop(nodo *&);
void desapilar(nodo *&);
void invertir(nodo *&, nodo *&);
void recorrer_pila(nodo *&);
void invertir(nodo *&, nodo *&);
void insertar_final(nodo *&, Alumno);

int main() {
    nodo* pila = NULL;
    bool ingreso = true;
    int i = 1;

    cout << "---Ingresar Apellido y Nombre---" << endl;
    while(ingreso)
    {
        Alumno al;
        cout << "Nombre " << i << ": ";
        cin >> al.nombre;
        cout << "Apellido " << i << ": ";
        cin >> al.apellido;
        push(pila, al);
    }

    //NI VALE LA PENA HACER ESTE EJERCICIO
    return 0;
}

void push(nodo *&pila, Alumno val) {
  nodo *p = new nodo();
  p->info = val;
  p->sgte = pila;
  pila = p;
}

Alumno pop(nodo*& pila) {
  Alumno val;
  nodo *p = pila;
  val = p->info;
  pila = p->sgte;
  delete p;

  return val;
}

void desapilar(nodo *&pila) {
  Alumno n;
  while (pila != NULL) {
    n = pop(pila);
    cout << n.nombre << endl;
    cout << n.apellido << endl;
  }
}

void recorrer_pila(nodo *&pila) {
  Alumno n;
  nodo *aux = NULL;
  while (pila != NULL) {
    n = pop(pila);
    push(aux, n);
    cout << n.nombre << endl;
    cout << n.apellido << endl;
  }
  invertir(pila, aux);
}

void invertir(nodo *&pila, nodo *&aux) {
  while (aux != NULL)
    push(pila, pop(aux));
}

void insertar_final(nodo *&pila, Alumno val) {
  Alumno n;
  int insertado = false;
  nodo *aux = NULL;
  while (pila != NULL && insertado == false) {
    n = pop(pila);
    push(aux, n);

    if (pila == NULL) {
      push(pila, val);
      insertado = true;
      invertir(pila, aux);
    }
  }
}
