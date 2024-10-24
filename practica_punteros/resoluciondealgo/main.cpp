#include <iostream>
#include <cstring>
using namespace std;
struct envios{
	int sucursal;
	int ciudad;
	int cantKilos;
	float valorxkilo;
};

struct infoLS{
	int ciudad;
	int kilos;
	float cxkilo;
};

struct nodoLS{
	infoLS infoLS;
	nodoLS* sgte;
};

struct infoLP{
	int sucursal;
	nodoLS* listaSec;
};

struct nodoLP{
	infoLP info;
	nodoLP* sgte;
};

struct tvector{
	int contador;
	nodo* lista;
};

int cantReg(FILE*& );
void encolar(nodo*& ,nodo*& ,alumno);
alumno desencolar(nodo*&,nodo*&);
void push(nodo*& pila,alumno);
alumno pop(nodo*&);
nodo* insertarOrdenado(nodo*&,alumno);
nodoLP* insertarsinRepetir(nodoLP*&,infoLP);

int main()
{
	....
	envios env;
	infoLP infoLP;
	infoLS infoLS;
	nodoLP* listaPPal=NULL;
	while(fread(&env,....))
	{
		infoLP.sucursal = env.sucursal;
		infoLP.listaSec = NULL;
		nodoLP* p = insertarsinRepetir(listaPPal,
		infoLP);
		infoLS.ciudad = env.ciudad;
		infoLS.cxkilo = env.valorxkilo;
		infoLS.kilos = env.cantKilos;
		insertarOrdenadoLS(p->info.listaSec,infoLS);
	}

	return 0;
}
nodoLP* buscar(nodoLP* lista,int sucursal)
{
	nodoLP* q=lista;
	while(q!=NULL && q->info.sucursal!=sucursal)
	{
		q=q->sgte;
	}

	return q;
}

alumno pop(nodo*& pila)
{
	alumno aux; //aux para guardar la info
	nodo* p=pila; //preservo la direccion del nodo
	aux = p->info;// le doy la info al aux
	pila = pila->sgte; // pila apunta al anterior
	delete p; //libero la memoria
	return aux;//retorna el dato
}

void push(nodo*& pila,alumno al)
{
	nodo* p=new nodo();
	p->info = al;
	p->sgte = pila;
	pila = p;
}

void encolar(nodo*& fte,nodo*& fin,alumno al)
{
	nodo* p=new nodo();//reservo espacio en mem.
	p->info=al;//guardo la info
	p->sgte=NULL;//inicializo el ptro

	if(fte==NULL){ //si es la prim.vez
		fte=p; //enlazo al fte
	}
	else{
		fin->sgte = p;
		//cuando hay datos actualizo el
		//ptro del que va a dejar ser ultimo.
	}
	fin=p; //apunto fin al nodo nuevo
}

alumno desencolar(nodo*& fte,nodo*& fin)
{
	alumno aux; //AUX para devolver el dato
	nodo* p=fte;//aux para el nodo que se borra
	aux=p->info;//recupero la info
	fte=p->sgte;//avanzo el ptro a fte
	if(fte==NULL)
	{//si no hay mas nodos
		fin=NULL; //fin apunta a null
	}
	delete p;// libero el nodo
	return aux; // retorno el contenido de info
}
int cantReg(FILE*& f)
{
	//preservar la posicion actual
	int posActual=ftell(f);
	fseek(f,0,SEEK_END);
	int desplaz=ftell(f);
	int cantidad=desplaz/sizeof(alumno);
	//vuelvo el puntero a donde estaba
	fseek(f,posActual,SEEK_SET);
	return cantidad;
}

nodoLP* insertarOrdenadoLP(nodoLP*& lista,infoLP lp)
{
	nodoLP* p=new nodoLP();
	p->info = lp;
	p->sgte=NULL;

	if(lista==NULL||
	   lista->info.sucursal > lp.sucursal)
	   {
	   	   p->sgte=lista;
	   	   lista = p;
	   }
	   else
	   {
	   	 //1)buscar donde pongo el nuevo nodo
	   	 nodoLP* q=lista;
	   	 while(q->sgte!=NULL &&
			  q->sgte->info.sucursal < lp.sucursal)
		  {
		  	 q=q->sgte;
		  }
		  //reenlazar los nodos
		  p->sgte=q->sgte;
		  q->sgte=p;
	   }

	   return p;
}
nodoLS* insertarOrdenadoLS(nodoLS*& lista,infoLS ls)
{
	nodoLS* p=new nodoLS();
	p->info = ls;
	p->sgte=NULL;

	if(lista==NULL||
	   lista->info.ciudad > ls.ciudad)
	   {
	   	   p->sgte=lista;
	   	   lista = p;
	   }
	   else
	   {
	   	 //1)buscar donde pongo el nuevo nodo
	   	 nodoLS* q=lista;
	   	 while(q->sgte!=NULL &&
			  q->sgte->info.ciudad < ls.ciudad)
		  {
		  	 q=q->sgte;
		  }
		  //reenlazar los nodos
		  p->sgte=q->sgte;
		  q->sgte=p;
	   }

	   return p;
}
nodoLP* insertarsinRepetir(nodoLP*& lista,
						   infoLP info)
{
	nodoLP* aux=buscar(lista,info.sucursal);
	if(aux!=NULL)
	{
		aux=insertarOrdenadoLP(lista,info);
	}
	return aux;
}
