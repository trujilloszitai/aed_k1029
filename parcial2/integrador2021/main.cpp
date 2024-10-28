#include <iostream>
using namespace std;

struct Paciente {
  int idTarjeta = 0;
  int idLaboratorio = 0;
};

struct Venta {
  int idTarjeta = 0;
  int idMedicamento = 0;
  int cantidad = 0;
  int dia = 0;
  int mes = 0;
};

struct Dato {
  int idTarjeta = 0;
  int dni = 0;
  char nombre_apellido[100 + 1] = "";
};

struct nodoV {
  Venta info;
  nodoV *sgte;
};

struct nodoD {
  Dato info;
  nodoD *sgte;
};

struct nodoP {
  Paciente info;
  nodoP *sgte;
};

struct Laboratorio {
    int idLaboratorio = 0;
    nodoV* listaVentas;
};

struct nodoL {
    Laboratorio info;
    nodoL* sgte;
};

int cantRegVentas(FILE *&f);
int cantRegDatos(FILE *&f);
nodoP *obtenerNodo(nodoP *, int);
int size(nodoP *);
nodoP *busquedaBinariaP(nodoP *, int);
nodoP *insertarOrdenadoP(nodoP *&, Paciente);
nodoV *insertarOrdenadoV(nodoV *&, Venta);
nodoD *insertarOrdenadoD(nodoD *&, Dato);
nodoP *insertarSinRpetir(nodoP *, Paciente);
void leerArchivoVentas(FILE *&, nodoV *&);
void leerArchivoDatos(FILE *&, nodoD *&);

int main() {
  FILE *fVentas = fopen("ventas.dat", "rb");
  FILE *fDatos = fopen("datos.dat", "rb");
  nodoV *listaV = NULL;
  nodoD *listaD = NULL;

  leerArchivoVentas(fVentas, listaV);
  leerArchivoVentas(fVentas, listaV);

  return 0;
}

int cantRegVentas(FILE *&f) {
  // preservar la posicion actual
  int posActual = ftell(f);
  fseek(f, 0, SEEK_END);
  int desplaz = ftell(f);
  int cantidad = desplaz / sizeof(Venta);
  // vuelvo el puntero a donde estaba
  fseek(f, posActual, SEEK_SET);
  return cantidad;
}

int cantRegDatos(FILE *&f) {
  // preservar la posicion actual
  int posActual = ftell(f);
  fseek(f, 0, SEEK_END);
  int desplaz = ftell(f);
  int cantidad = desplaz / sizeof(Dato);
  // vuelvo el puntero a donde estaba
  fseek(f, posActual, SEEK_SET);
  return cantidad;
}

nodoP *obtenerNodoP(nodoP *listaP, int i) {
  nodoP *aux = listaP;
  int contador = 0;
  while (aux != NULL && contador < i) {
    aux = aux->sgte;
    contador++;
  }
  return aux;
}

nodoV *obtenerNodoV(nodoV *listaP, int i) {
  nodoV *aux = listaP;
  int contador = 0;
  while (aux != NULL && contador < i) {
    aux = aux->sgte;
    contador++;
  }
  return aux;
}

nodoD *obtenerNodoD(nodoD *listaP, int i) {
  nodoD *aux = listaP;
  int contador = 0;
  while (aux != NULL && contador < i) {
    aux = aux->sgte;
    contador++;
  }
  return aux;
}

nodoL *obtenerNodoL(nodoL *listaP, int i) {
  nodoL *aux = listaP;
  int contador = 0;
  while (aux != NULL && contador < i) {
    aux = aux->sgte;
    contador++;
  }
  return aux;
}

void push(nodoL *&pila, Laboratorio val) {
  nodoL *p = new nodoL();
  p->info = val;
  p->sgte = pila;
  pila = p;
}

Laboratorio pop(nodoL *&pila) {
  Laboratorio val;
  nodoL *p = pila;
  val = p->info;
  pila = p->sgte;
  delete p;

  return val;
}

int size(nodoP *listaP) {
  int tamano = 0;
  nodoP *temp = listaP;
  while (temp != NULL) {
    tamano++;
    temp = temp->sgte;
  }
  return tamano;
}

int sizeD(nodoD *listaP) {
  int tamano = 0;
  nodoD *temp = listaP;
  while (temp != NULL) {
    tamano++;
    temp = temp->sgte;
  }
  return tamano;
}

int sizeL(nodoL *listaP) {
  int tamano = 0;
  nodoL *temp = listaP;
  while (temp != NULL) {
    tamano++;
    temp = temp->sgte;
  }
  return tamano;
}
int sizeV(nodoV *listaP) {
  int tamano = 0;
  nodoV *temp = listaP;
  while (temp != NULL) {
    tamano++;
    temp = temp->sgte;
  }
  return tamano;
}

// nodoP* buscar(nodoP* lista,int sucursal)
// {
// 	nodoP* q=lista;
// 	while(q!=NULL && q->info.sucursal!=sucursal)
// 	{
// 		q=q->sgte;
// 	}

// 	return q;
// }

nodoP *busquedaBinariaP(nodoP *listaP, int idTarjeta) {
  int inicio = 0;
  int fin = size(listaP) - 1;

  while (inicio <= fin) {
    int medio = inicio + (fin - inicio) / 2;
    nodoP *nodo_medio = obtenerNodoP(listaP, medio);

    if (nodo_medio->info.idTarjeta == idTarjeta) {
      return nodo_medio; // Valor encontrado
    } else if (nodo_medio->info.idTarjeta < idTarjeta) {
      inicio = medio + 1;
    } else {
      fin = medio - 1;
    }
  }

  return NULL; // Valor no encontrado
}
nodoV *busquedaBinariaV(nodoV *listaV, int idTarjeta) {
  int inicio = 0;
  int fin = sizeV(listaV) - 1;

  while (inicio <= fin) {
    int medio = inicio + (fin - inicio) / 2;
    nodoV *nodo_medio = obtenerNodoV(listaV, medio);

    if (nodo_medio->info.idTarjeta == idTarjeta) {
      return nodo_medio; // Valor encontrado
    } else if (nodo_medio->info.idTarjeta < idTarjeta) {
      inicio = medio + 1;
    } else {
      fin = medio - 1;
    }
  }

  return NULL; // Valor no encontrado
}
nodoD *busquedaBinariaD(nodoD *listaP, int idTarjeta) {
  int inicio = 0;
  int fin = sizeD(listaP) - 1;

  while (inicio <= fin) {
    int medio = inicio + (fin - inicio) / 2;
    nodoD *nodo_medio = obtenerNodoD(listaP, medio);

    if (nodo_medio->info.idTarjeta == idTarjeta) {
      return nodo_medio; // Valor encontrado
    } else if (nodo_medio->info.idTarjeta < idTarjeta) {
      inicio = medio + 1;
    } else {
      fin = medio - 1;
    }
  }

  return NULL; // Valor no encontrado
}

nodoL *busquedaBinariaL(nodoL *listaL, int idTarjeta) {
  int inicio = 0;
  int fin = sizeL(listaL) - 1;

  while (inicio <= fin) {
    int medio = inicio + (fin - inicio) / 2;
    nodoL *nodo_medio = obtenerNodoL(listaL, medio);

    if (nodo_medio->info.idLaboratorio == idTarjeta) {
      return nodo_medio; // Valor encontrado
    } else if (nodo_medio->info.idLaboratorio < idTarjeta) {
      inicio = medio + 1;
    } else {
      fin = medio - 1;
    }
  }

  return NULL; // Valor no encontrado
}

nodoP *insertarOrdenadoP(nodoP *&lista, Paciente info) {
  nodoP *p = new nodoP();
  p->info = info;
  p->sgte = NULL;

  if (lista == NULL || lista->info.idTarjeta > info.idTarjeta) {
    p->sgte = lista;
    lista = p;
  } else {
    // 1)buscar donde pongo el nuevo nodo
    nodoP *q = lista;
    while (q->sgte != NULL && q->sgte->info.idTarjeta < info.idTarjeta) {
      q = q->sgte;
    }
    // reenlazar los nodos
    p->sgte = q->sgte;
    q->sgte = p;
  }

  return p;
}

nodoD *insertarOrdenadoD(nodoD *&lista, Dato info) {
  nodoD *p = new nodoD();
  p->info = info;
  p->sgte = NULL;

  if (lista == NULL || lista->info.dni > info.dni) {
    p->sgte = lista;
    lista = p;
  } else {
    // 1)buscar donde pongo el nuevo nodo
    nodoD *q = lista;
    while (q->sgte != NULL && q->sgte->info.dni < info.dni) {
      q = q->sgte;
    }
    // reenlazar los nodos
    p->sgte = q->sgte;
    q->sgte = p;
  }

  return p;
}

nodoV *insertarOrdenadoV(nodoV *&lista, Venta info) {
  nodoV *p = new nodoV();
  p->info = info;
  p->sgte = NULL;

  if (lista == NULL || lista->info.idTarjeta > info.idTarjeta) {
    p->sgte = lista;
    lista = p;
  } else {
    // 1)buscar donde pongo el nuevo nodo
    nodoV *q = lista;
    while (q->sgte != NULL && q->sgte->info.idTarjeta < info.idTarjeta) {
      q = q->sgte;
    }
    // reenlazar los nodos
    p->sgte = q->sgte;
    q->sgte = p;
  }

  return p;
}

nodoL *insertarOrdenadoL(nodoL *&lista, Laboratorio info) {
  nodoL *p = new nodoL();
  p->info = info;
  p->sgte = NULL;

  if (lista == NULL || lista->info.idLaboratorio > info.idLaboratorio) {
    p->sgte = lista;
    lista = p;
  } else {
    // 1)buscar donde pongo el nuevo nodo
    nodoL *q = lista;
    while (q->sgte != NULL && q->sgte->info.idLaboratorio < info.idLaboratorio) {
      q = q->sgte;
    }
    // reenlazar los nodos
    p->sgte = q->sgte;
    q->sgte = p;
  }

  return p;
}

nodoP *insertarsinRepetir(nodoP *&lista, Paciente info) {
  nodoP *aux = busquedaBinariaP(lista, info.idTarjeta);
  if (aux != NULL) {
    aux = insertarOrdenadoP(lista, info);
  }
  return aux;
}

nodoL *insertarsinRepetirL(nodoL *&lista, Laboratorio info) {
  nodoL *aux = busquedaBinariaL(lista, info.idLaboratorio);
  if (aux != NULL) {
    aux = insertarOrdenadoL(lista, info);
  }
  return aux;
}

nodoL* listadoLaboratorios(nodoP* listaP, nodoV* listaV) {
  nodoL *listaLab = NULL;
  nodoP *auxP = listaP;
  nodoV *auxV = listaV;

  while (auxP != NULL) {
    Laboratorio lab;
    lab.idLaboratorio = auxP->info.idLaboratorio;
    int idT = auxP->info.idTarjeta;
    nodoV* ventasLab = NULL;

    while (auxV != NULL) {
        while(auxV->info.idTarjeta == idT) {
            insertarOrdenadoV(ventasLab, auxV->info);
        }
        auxV = auxV->sgte;
    }
    lab.listaVentas = ventasLab;

    insertarsinRepetirL(listaLab, lab);

    auxP = auxP->sgte;
  }

  return listaLab;
}

void leerArchivoVentas(FILE *&f, nodoV *&lista) {
  Venta v;
  while (fread(&v, sizeof(Venta), 1,
               f)) // Mientras la lectura no llegue a la marca de fin de archivo
  {
    lista = insertarOrdenadoV(lista, v);
  }
}

void leerArchivoDatos(FILE *&f, nodoD *&lista) {
  Dato d;
  while (fread(&v, sizeof(Dato), 1,
               f)) // Mientras la lectura no llegue a la marca de fin de archivo
  {
    lista = insertarOrdenadoD(lista, d);
  }
}

void generarListado(nodoL*& listaL, nodoP*& listaP, nodoD*& listaD)
{
    nodoL* listaLab = listaL;
    nodoP* listaPac = listaP;
    nodoD* listaDat = listaD;

    while(listaLab != NULL)
    {
        Laboratorio lab = pop(listaL);
        nodoV* ventas = lab.listaVentas;
        cout << "LABORATORIO " << lab.idLaboratorio << ":" << endl;
        while(ventas != NULL) {
            Venta v = ventas->info;
            int idT = v.idTarjeta;
            Dato d = busquedaBinariaD(listaDat, idT)->info;
            Paciente p = busquedaBinariaP(listaPac, idT)->info;
            cout << "ID TARJETA " << idT << " Nombre y apellido: " << d.nombre_apellido << endl;
            cout << "IdMedicamento " << v.idMedicamento << " Cantidad " << v.cantidad << " Dia " << v.dia << " Mes " << v.mes << endl;
        }
    }
}
