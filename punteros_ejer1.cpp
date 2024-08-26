#include <iostream>
using namespace std;

struct nodo
{
	int info;
	nodo* sgte;
};

void push(nodo*&, int);
int pop(nodo*&);
int ins_tercera(nodo*&, int);
void desapilar(nodo*&);

int main()
{
	nodo* pila = NULL;
	int ins = 22;
	
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
	int res = ins_tercera(pila, ins);
	
	if(res == 1)
	{
		cout << "insertado" << endl;
	}
	else
	{
		cout << "no se insertó" << endl;
	}
	
	desapilar(pila);
	
	return 0;
}

void push(nodo*& pila, int val)
{
	nodo* p = new nodo();
	p->info = val;
	p->sgte = pila;
	pila = p;
}

int pop(nodo*& pila)
{
	int val;
	nodo* p = pila;
	val = p->info;
	pila = p->sgte;
	delete p;
	
	return val;
}

int ins_tercera(nodo*& pila, int val)
{
	int cont = 0;
	int n;
	int res = 0;
	while(pila!=NULL)
	{
		if(cont == 2)
		{
			push(pila, val);
			res = 1;
		}
		else
		{
			n = pop(pila);
			cout << n << endl;
		}
		cont++;
	}
	
	return res;
}

void desapilar(nodo*& pila)
{
	int n;
	while(pila!=NULL)
	{
		n = pop(pila);
		cout << n << endl;
	}
}