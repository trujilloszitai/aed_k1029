// dadas dos colas retorne la union de las dos colas en una unica cola
// primero la cola1, luego la cola2


// TAREA   TAREA   TAREA   TAREA   TAREA   TAREA
// dos funciones, una que una dos colas una a continuacion de la otra, y otra
// funcion que una dos colas ordenadas manteniendo el orden (apareo)
cola unirColas(nodo* frente1, nodo* frente2, nodo* fin1, nodo* fin2);
cola aparearColas(...);
// TAREA   TAREA   TAREA   TAREA   TAREA   TAREA


#include <iostream>
using namespace std;

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

struct cola
{
    nodo* frente;
    nodo* fin;
};
// decidimos retornar el frente y el fin de la cola en la funcion por lo que
// armamos este struct



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

// funcion que una dos colas
cola unirColas(nodo* frente1, nodo* frente2, nodo* fin1, nodo* fin2)
{
    cola c;
    // es un registro

    c.frente = frente1;
    c.fin = fin2;

    // TERMINAR
}

// unir dos colas ordenadas conservando el orden
// TERMINAR, APAREO



int main()
{
    // declarar los punteros que controlan la estructura

    nodo* frente = NULL;
    // para controlar el frente de la cola

    nodo* fin = NULL;
    // para controlar el final de la cola

    tipoInfo valor;
    // para cargar o extraer los valores de la pila o de la cola

    //cargamos valores en una cola
    valor.campo1 = 5;
    valor.campo2 = 50;
    queue(frente, fin, valor);

    valor.campo1 = 7;
    valor.campo2 = 70;
    queue(frente, fin, valor);

    valor.campo1 = 9;
    valor.campo2 = 90;
    queue(frente, fin, valor);

    valor.campo1 = 11;
    valor.campo2 = 110;
    queue(frente, fin, valor);

    while (frente != NULL)
    {
        // mientras haya datos en la cola

        valor = unqueue(frente, fin);
        // tomamos el valor el campo de la informacion del primer nodo

        cout << valor.campo1 << ", " << valor.campo2 << endl;
    }


    return 0;
}
