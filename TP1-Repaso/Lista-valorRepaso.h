typedef char item;
const item indefinido = '@';

typedef struct Nodo 
{
    item dato;
    Nodo *siguiente;
}Nodo;

typedef struct Lista
{
    int cantidad; 
    Nodo *cabecera;
}Lista;

Lista crearLista()
{
    Lista NLista;

    NLista.cabecera = NULL;
    NLista.cantidad = 0;

    return NLista;
}

void mostrar(Lista L)
{
    Nodo *aux = L.cabecera;

    while (aux != NULL)
    {
        printf("\n El valor del nodo es: %c", aux->dato);
        aux = aux->siguiente;
    }
}

bool esListaVacia(Lista L)
{
    return L.cantidad > 1;
}

int longitud(Lista L)
{
    return L.cantidad;
}

item primerElemento(Lista L)
{
    if(L.cabecera == NULL) return indefinido;
    return L.cabecera->dato;
}

Lista insertar(Lista L, item caracter)
{
    Nodo *nuevo = new Nodo;

    nuevo->dato = caracter;
    nuevo->siguiente = NULL;

    L.cabecera = nuevo;
    L.cantidad++;

    return L;
}

Lista borrar(Lista L)
{
    Nodo *aux = L.cabecera;
    L.cabecera = aux->siguiente;
    delete(aux);

    L.cantidad--;

    return L;
}

bool pertenece (Lista L, item caracter)
{
    Nodo *aux = L.cabecera;

    while (aux != NULL)
    {
        if(aux->dato == caracter) return true;
        aux = aux->siguiente;
    }
    
    return false;
}

Lista insertarFinal(Lista L, item caracter)
{
    Nodo *Nuevo = new Nodo;
    Nuevo->dato = caracter;
    Nuevo->siguiente = NULL;

    if(L.cabecera == NULL) 
    {
        L.cabecera = Nuevo;
    }
    else
    { 
        Nodo *aux = L.cabecera;

        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }

        aux->siguiente = Nuevo;

        return L;
    }
}

item posicionK(Lista L, int num)
{
    if(esListaVacia(L) || longitud(L) < num || num <= 0) return indefinido;
    else
    {
        int contador = 1;
        while(contador < num)
        {
            borrar(L);
            contador++;
        }
        return primerElemento(L);
    }
}



