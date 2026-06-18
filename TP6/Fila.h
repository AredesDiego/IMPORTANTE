#include <iostream>

typedef int item;
const item indefinido = -9999;

typedef struct Nodo
{
    item dato;
    Nodo *siguiente;
}Nodo;

typedef struct Fila
{
    int longitud;
    Nodo *frente;
    Nodo *final;
}Fila;

Fila FILAVACIA()
{
    Fila fila;
    fila.longitud = 0;
    fila.final = NULL;
    fila.frente = NULL;

    return fila;
}

bool ESFILAVACIA(Fila fila)
{
    return fila.longitud == 0;
}

item FRENTE(Fila fila)
{
    if(ESFILAVACIA(fila)) return indefinido;
    return fila.frente->dato;
}

Fila ENFILA(Fila fila, item dato)
{
    Nodo *nodo = new Nodo;

    nodo->dato = dato;
    nodo->siguiente = NULL;


    if(ESFILAVACIA(fila))
    {
        fila.final = nodo;
        fila.frente = nodo;
    }

    fila.final->siguiente = nodo;
    fila.final = nodo;

    return fila;
}

Fila DEFILA(Fila fila)
{
    Nodo *nodo = fila.frente;

    fila.frente = nodo->siguiente;
    fila.longitud--;

    delete(nodo);

    return fila;
}

Fila CONCATENAR(Fila fila, Fila fila2)
{
    Nodo *nodo = fila2.frente;

    fila.final->siguiente = nodo;
    fila.final = fila2.final;
    fila.longitud += fila2.longitud;

    return fila;
}