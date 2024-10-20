/*
 * Plantillas/Templates NO se toma en los examenes!!
 * 
 */

// plantillas para la generalidads de los datos

#include <iostream>
using namespace std;

/* procedimientos para pilas */

// estructuras con un struct en el campo de informacion
struct tipoInfo
{
        int campo1;
        int campo2;
};
// en el campo de la informacion ahora tendremos un struct de tipoInfo
// declarar el nodo con una plantilla

template<typename T>
struct nodo
{
    T info;
    nodo<T>* siguiente;
};


/*template<typename T>
T suma(T a, T b)
{
    return a+b;
}
// el T es el "sinonimo" del tipo de dato que se pone en la invocacion
// entre < >, de esa forma podemos invocar a la funcion con el tipo de datos
// que nosotros querramos
*/

// procedimientos para pila

// insertar un nodo en una pila
template<typename T>
void push(nodo<T>* &pila, T x)
{
    nodo<T>* p = new nodo<T>;

    p->info = x;

    p->siguiente = pila;

    pila = p;
}

// funcion para eliminar un nodo en la pila

template<typename T>
T pop(nodo<T>* &pila)
{
    nodo<T>* p = pila;
     
    T x = p->info;
     
    pila = p->siguiente;
     
    delete p;
     
    return x;
}


int main()
{
    /*
    int x = suma<int>(3, 4);
    float y = suma<float>(3.5, 4.5);
    */
    
    nodo<int>* pila1 = NULL;
    nodo<tipoInfo>* pila2 = NULL;
    
    int x;
    tipoInfo info;
    
    x = 10;
    info.campo1 = 5;
    info.campo2 = 15;
    
    push<int>(pila1, x);
    push<tipoInfo>(pila2, info);
    
    return 0;
}
