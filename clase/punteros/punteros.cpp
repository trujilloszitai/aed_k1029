#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

struct Alumno
{
	int legajo;
	char nombre[30+1];	
};

struct nodo
{
	Alumno info;
	nodo* sgte;
};

void push(nodo*&, Alumno);
Alumno pop(nodo*&);

int main()
{
//	int* p=NULL;
//	int a=10;
//	p = &a;
	
	/* Alumno* p = new Alumno();
	(*p).legajo = 1;
	cout << p->legajo; */
	
	nodo* pila = NULL;
	Alumno al;
	
	al.legajo = 11;
	strcpy(al.nombre, "Federico");
	push(pila,al);

	al.legajo = 22;
	strcpy(al.nombre, "Fabian");
	push(pila,al);
	
	al.legajo = 33;
	strcpy(al.nombre, "Franco");
	push(pila,al);
	
	while(pila!=NULL)
	{
		al = pop(pila);
		cout << al.legajo << " " << al.nombre << endl;
	}
	
	return 0;
}

void push(nodo*& pila, Alumno al)
{
	nodo* p = new nodo();
	
	p->info = al;
	p->sgte = pila;
	
	pila = p;
}

Alumno pop(nodo*& pila)
{
	Alumno al;
	nodo* p = pila;
	al = p->info;
	pila = p->sgte;
	delete p;
	
	return al;
}