typedef char item;
const item indefinido = '@';

typedef struct Nodo
{
    item dato;
    Nodo *siguiente;
}Nodo;

typedef struct Baul
{
    int capacidad;
    int ocupado;
    Nodo *primero;
    Nodo *ultimo;
}Baul;

Baul BAULVACIO(int capacidad)
{
    Baul baul;

    baul.capacidad = capacidad;
    baul.ocupado = 0;
    baul.primero = NULL;
    baul.ultimo = NULL;

    return baul;
}

Baul GUARDAR(Baul baul, item objeto)
{
    Nodo *nuevo = new Nodo;
    nuevo->dato = objeto;
    nuevo->siguiente = baul.primero;

    if (baul.primero == NULL)
    {
        baul.ultimo = nuevo;
    }

    baul.primero = nuevo;
    baul.ocupado++;

    return baul;
}

int DISPONIBLE(Baul baul)
{
    return baul.capacidad - baul.ocupado;
}

Baul AGREGAR(Baul baul, item objeto)
{
    if(DISPONIBLE(baul) > 0) return GUARDAR(baul, objeto);
    return baul;
}

int CAPACIDAD(Baul baul)
{
    return baul.capacidad;
}

bool ESTAVACIO(Baul baul)
{
    return baul.ocupado == 0;
}

item ULTIMO(Baul baul)
{
    if(ESTAVACIO(baul)) return indefinido;

    return baul.primero->dato;
}

item PRIMERO(Baul baul)
{
    if(ESTAVACIO(baul)) return indefinido;

    return baul.ultimo->dato;
}

Baul QUITARULTIMO(Baul *baul)
{
    if (ESTAVACIO(*baul)) return *baul;
    
    Nodo *nodo = baul->primero;
    baul->primero = baul->primero->siguiente;

    if(baul->primero == NULL)
        baul->ultimo = NULL;
    
    delete (nodo);
    baul->ocupado--;

    return *baul;
}

Baul VACIAR(Baul baul)
{
    Nodo *nodo = baul.primero;
    Nodo *Nodoaux = NULL;

    while (nodo != NULL)
    {
        Nodoaux = nodo->siguiente;
        delete(nodo);
        nodo = Nodoaux;
    }

    baul.primero = NULL;
    baul.ultimo = NULL;
    baul.ocupado = 0;

    return baul;
}

bool CONTIENE(Baul baul, item objeto)
{
    Nodo *nodo = baul.primero;

    while(nodo != NULL)
    {
        if(nodo->dato == objeto) return true;
        nodo = nodo->siguiente;
    }

    return false;
}

int OCUPADO(Baul baul)
{
    return baul.ocupado;
}

int moverObjetos(Baul baul, Baul baul2)
{
    int objetosMovidos = 0;

    while (!ESTAVACIO(baul))
    {
        baul2 = AGREGAR(baul2, ULTIMO(baul));
        baul = QUITARULTIMO(&baul);
        objetosMovidos++;
    }
    
    return objetosMovidos;
}

void MOSTRAR(Baul baul)
{
    Nodo *nodo = baul.primero;

    printf("\nLa capacidad del baul es: %d\n", baul.capacidad);
    printf("\nEl baul tiene ocupado: %d lugares\n", baul.ocupado);
    
    while (nodo != NULL)
    {
        printf("\nEl baul tiene el siguiente objeto: %c \n", nodo->dato);
        nodo = nodo->siguiente;
    }
}