#include <cstddef>
#include <cstring>
#include <iostream>
using namespace std;

struct nodo {
  char info;
  nodo *sgte;
};

void push(nodo *&, char);
char pop(nodo *&);
void desapilar(nodo *&);
void reapilar(nodo *&, nodo *&);
void recorrer_pila(nodo *&);
void reapilar(nodo *&, nodo *&);
void insertar_final(nodo *&, char);
bool inversa(char[]);

int main() {
  nodo *pila = NULL;
  char conjunto1[20 + 1];
  char conjunto2[20 + 1];
  cout << "Conjunto 1: ";
  cin >> conjunto1;
  cout << "Conjunto 2: ";
  cin >> conjunto2;
  char texto[41 + 1];
  strcpy(texto, conjunto1);
  strcat(texto, ".");
  strcat(texto, conjunto2);
  cout << "Texto: " << texto << endl;

  if (inversa(texto)) {
    cout << "Los conjuntos son inversos." << endl;
  } else {
    cout << "Los conjuntos no son inversos." << endl;
  }

  return 0;
}

bool inversa(char txt[]) {
  bool punto = false;
  bool son_inversos = true;
  nodo *sub1 = NULL;
  nodo *sub2 = NULL;
  nodo *aux = NULL;
  int i = 0;
  while (txt[i] != '\0') {
    char val = txt[i];
    if (val != '.') {
      punto ? push(aux, val) : push(sub1, val);
    } else {
      punto = true;
    }

    i++;
  }
  reapilar(sub2, aux);
  i = 0;

  char c1[20 + 1];
  char c2[20 + 1];
  while (sub1 != NULL && sub2 != NULL) {
    c1[i] = pop(sub1);
    c2[i] = pop(sub2);
    if(c2[i] != c1[i]) son_inversos = false;
    i++;
  }

  return son_inversos;
}

void push(nodo *&pila, char val) {
  nodo *p = new nodo();
  p->info = val;
  p->sgte = pila;
  pila = p;
}

char pop(nodo *&pila) {
  char val;
  nodo *p = pila;
  val = p->info;
  pila = p->sgte;
  delete p;

  return val;
}

void desapilar(nodo *&pila) {
  char n;
  while (pila != NULL) {
    n = pop(pila);
    cout << n << endl;
  }
}

void recorrer_pila(nodo *&pila) {
  char n;
  nodo *aux = NULL;
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

void insertar_final(nodo *&pila, char val) {
  char n;
  int insertado = false;
  nodo *aux = NULL;
  while (pila != NULL && insertado == false) {
    n = pop(pila);
    push(aux, n);

    if (pila == NULL) {
      push(pila, val);
      insertado = true;
      reapilar(pila, aux);
    }
  }
}
