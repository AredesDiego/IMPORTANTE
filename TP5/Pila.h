#include <iostream>

typedef int item;
const item indefinido = -9999;

typedef struct Nodo
{
    item dato;
    Nodo *siguiente;
}Nodo;

typedef struct Pila
{
    int altura;
    Nodo *cabecera;
}Pila;

bool ESPILAVACIA(Pila pila)
{
    return pila.altura == 0;
}

Pila PILAVACIA()
{
    Pila pila;

    pila.altura = 0;
    pila.cabecera = NULL;

    return pila;
}

Pila PUSH(Pila pila, item objeto)
{
    Nodo *nuevo = new Nodo;

    nuevo->siguiente = NULL;
    nuevo->dato = objeto;

    nuevo->siguiente = pila.cabecera;
    pila.cabecera = nuevo;

    pila.altura++;
    
    return pila;
}

Pila POP(Pila pila)
{
    Nodo *nodo = pila.cabecera;

    pila.cabecera = nodo->siguiente;
    pila.altura--;

    delete(nodo);
    
    return pila;
}

item TOP(Pila pila)
{
    if(ESPILAVACIA(pila)) return indefinido;
    return pila.cabecera->dato;
}

int ALTURA(Pila pila)
{
    if(ESPILAVACIA(pila)) return indefinido;
    return pila.altura;
}

item FONDO(Pila pila)
{
    if(ESPILAVACIA(pila)) return indefinido;

    Nodo *nodo = pila.cabecera;

    while (nodo->siguiente != NULL)
    {
        nodo = nodo->siguiente;
    }

    return nodo->dato;
}

Pila POPF(Pila pila){
    if (pila.cabecera == NULL || pila.cabecera->siguiente == NULL)
    {
        return POP(pila);
    }else
    {
        item dato = TOP(pila);

        pila = POP(pila);
        return PUSH(POPF(pila), dato);
    }
}

Pila REEMP(Pila pila, item busqueda, item datoNuevo)
{
    Nodo *nodo = pila.cabecera;

    while (nodo != NULL)
    {
        if(nodo->dato == busqueda) 
        {
            nodo->dato = datoNuevo;
        }

        nodo = nodo->siguiente;
    }

    return pila;
}

bool PERTENECE(Pila pila, item busqueda)
{
    Nodo *nodo = pila.cabecera;

    while (nodo != NULL)
    {
        if(nodo->dato == busqueda) 
        {
            return true;
        }
        nodo = nodo->siguiente;
    }

    return false;
}

Pila ELIMINARX(Pila pila, item busqueda)
{
    Nodo *nodo = pila.cabecera;

    while (nodo != NULL)
    {
        if(nodo->dato == busqueda) 
        {
            delete(nodo);
        }

        nodo = nodo->siguiente;
    }

    return pila;
}

Pila ELIMINARX(Pila pila, item dato)
{
    if(ESPILAVACIA(pila)) return pila;

    if (TOP(pila) == dato)
    {
        return ELIMINARX(POP(pila), dato);
    } 
    else
    {
        return PUSH(ELIMINARX(POP(pila), dato), TOP(pila));
    }
}

void MOSTRAR(Pila pila)
{
    if (ESPILAVACIA(pila)) {
        std::cout << "[Vacio]" << std::endl;
        return;
    }
    
    Nodo* nodo = pila.cabecera;
    std::cout << "[Tope: ";
    while (nodo != NULL) {
        std::cout << nodo->dato;
        if (nodo->siguiente != NULL) std::cout << " -> ";
        nodo = nodo->siguiente;
    }
    std::cout << " :Fondo] (Altura: " << pila.altura << ")" << std::endl;
}