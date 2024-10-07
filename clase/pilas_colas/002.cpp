#include <iostream>
using namespace std;

/* procedimientos para pilas y colas */

// estructuras con un struct en el campo de informacion
struct tipoInfo
{
        int campo1;
        int campo2;
};
// en el campo de la informacion ahora tendremos un struct de tipoInfo

// estructura autorreferenciada
struct nodo
{
    tipoInfo info;            // informacion
    nodo*    siguiente;       // puntero al proximo nodo
};

// procedimientos para pila

// insertar un nodo en una pila
void push(nodo* &pila, tipoInfo x)
{
// la funcion devuelve void, recibe como parametro el puntero de la pila
// que siempre se modifica y el entero x a cargar en el nodo que
// se va a crear

nodo* p = new nodo;
// con un puntero auxiliar p se pide memoria para crear un nuevo nodo

p->info = x;
//(*p).info = x; forma alternativa de expresarlo
// al campo info del nodo apuntado por p le asignamos el parametro x

p->siguiente = pila;
// hacemos que el siguiente nodo creado apunte a pila, que es
// el anterior primero

pila = p;
// el nuevo nodo pasa a ser el comienzo de la estructura
}

// funcion para eliminar un nodo en la pila
tipoInfo pop(nodo* &pila)
{
    // la funcion retorna el campo info que esta en el primer nodo y elimina a x
    
    nodo* p = pila;
    // creamos un puntero auxiliar p y le asignamos el comienzo de la pila
    
    tipoInfo x = p->info;
    // a x le asignamos el campo info que esta en el primer nodo
    
    pila = p->siguiente;
    // hacemos que pila apunte al nodo siguiente
    
    delete p;
    // eliminamos la instancia del que era el primer nodo
    
    return x;
    // retorna el valor que estaba en el primer nodo
}

// funciones para una cola
// insertar un nodo en una cola
void queue(nodo* &frente, nodo* &fin, tipoInfo x)
{
    // los punteros son al principio y al final, y tambien tiene
    // el valor a cargar x
    
    nodo* p = new nodo;
    // utilizamos un puntero auxiliar p para pedir memoria
    
    p->info = x;
    // al campo de la informacion le asignamos el parametro
    
    p->siguiente = NULL;
    // el siguiente de este nodo es NULL porque como base del ultimo nodo
    // no va a tener siguiente
    
    if (frente == NULL)
    {
        // si la cola esta vacia el frente debe apuntar al nuevo nodo
        frente = p;
    } else {
        // si no esta vacia, el siguiente del ultimo tiene que ser el nuevo nodo
        fin->siguiente = p;
    }
 
    fin = p;
    // el puntero al final apunta al nodo creado
}

// funcion para eliminar un nodo de una cola
// retorna el valor que esta en el primer nodo y lo elimina
tipoInfo unqueue(nodo* &frente, nodo* &fin)
{
    // recibe como parametros los punteros de control de la estructura por referencia
    
    nodo* p = frente;
    // le asignamos el puntero p el principio de la estructura
    
    tipoInfo x = p->info;
    // le asignamos el campo de la informacion del primer nodo
    
    frente = p->siguiente;
    // avanzamos con frente a nodo siguiente
    
    if (frente == NULL)
    {
        // si frente es NULL debemos hacer NULL tambien a fin
        fin = NULL;
    }
    
    
    delete p;
    // eliminamos la instancia de p
    
    return x;
}

int main()
{
    // declarar los punteros que controlan la estructura
    
    nodo* pila = NULL;
    // controlara a la pila y tiene que tener NULL como valor de inicializacion
    
    nodo* frente = NULL;
    // para controlar el frente de la cola
    
    nodo* fin = NULL;
    // para controlar el final de la cola
    
    tipoInfo valor;
    // para cargar o extraer los valores de la pila o de la cola
    
    //cargamos valores en una pila y en una cola    
    valor.campo1 = 5;
    valor.campo2 = 50;
    push(pila, valor);
    queue(frente, fin, valor);
    
    valor.campo1 = 7;
    valor.campo2 = 70;
    push(pila, valor);
    queue(frente, fin, valor);
    
    valor.campo1 = 9;
    valor.campo2 = 90;
    push(pila, valor);
    queue(frente, fin, valor);
    
    valor.campo1 = 11;
    valor.campo2 = 110;
    push(pila, valor);
    queue(frente, fin, valor);
    // recorrer la pila y mostrar los valores
    while (pila != NULL)
    {
        // mientras haya datos en la pila
        
        valor = pop(pila);
        // tomamos el valor el campo de la informacion del primer nodo
        
        cout << valor.campo1 << ", " << valor.campo2 << endl;
    }
    cout << endl;
    
    while (frente != NULL)
    {
        // mientras haya datos en la cola
        
        valor = unqueue(frente, fin);
        // tomamos el valor el campo de la informacion del primer nodo
        
        cout << valor.campo1 << ", " << valor.campo2 << endl;
    }

    
    return 0;
}
