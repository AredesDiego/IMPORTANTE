typedef char item;
const item indefinido = '@';

typedef struct Nodo
{
    item dato;
    struct Nodo *siguiente;
}Nodo;

typedef struct Lista
{
    Nodo *inicio;
    int cantidad;
}Lista;

void crearLista(Lista *L)
{
    L->cantidad = 0;
    L->inicio = NULL;
}
bool esListaVacia(Lista L)
{
    return L.inicio == NULL;
}
void mostrar(Lista L)
{
    Nodo *aux = L.inicio;

    while (aux != NULL)
    {
        printf("\n El dato es: %c\n", aux->dato);
        aux = aux->siguiente;
    }
}
item primerElemento(Lista L)
{
    if (L.inicio == NULL) return indefinido;
    
    return L.inicio->dato;
}
void insertar(Lista *L, item dato)
{   
    Nodo *nuevoNodo = new Nodo;

    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = L->inicio;
    L->inicio = nuevoNodo;
    L->cantidad++;
}
void borrar(Lista *L)
{
    if(L->inicio != NULL)
    {
        Nodo *aux = L->inicio;
        L->inicio = aux->siguiente;
        delete(aux);
        
        L->cantidad--;
    }
}
int longitud(Lista L)
{
    int contador = 0;

    Nodo *actual = L.inicio;

    while (actual != NULL)
    {
        actual = actual->siguiente;
        contador++;
    }
    
    return contador;
}
bool pertenece(Lista L, item buscado)
{
    Nodo *aux = L.inicio;

    while (aux != NULL && aux->dato != buscado)
    {
        aux = aux->siguiente;
    }
    
    return aux != NULL;
}
void insertarFinal(Lista *L, item datoAgregar)
{
    Nodo *nuevo = new Nodo;
    
    nuevo->dato = datoAgregar;
    nuevo->siguiente = NULL;
    
    if(L->inicio == NULL) 
    {
        L->inicio = nuevo;
    }
    else
    {
        Nodo *aux = L->inicio;

        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        
        aux->siguiente = nuevo;
   
    }

    L->cantidad++;
}
item posicionKEstiloProfe(Lista L, int numero) 
{
    if (numero < 1 || numero > L.cantidad) 
    {
        return indefinido;
    }

    int contador = 1;
    while (contador < numero)
    {
        L.inicio = L.inicio->siguiente; 
        contador++;
    }

    return primerElemento(L); 
}


