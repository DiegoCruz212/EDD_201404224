#ifndef LISTADOBLE_TEMPL_H
#define LISTADOBLE_TEMPL_H

template<typename G>
struct nodoDoble{
public:
    nodoDoble(G data, int i) : data(data), index(i), sig(nullptr), ant(nullptr) {}

    G data;
    int index;
    nodoDoble<G> *sig;
    nodoDoble<G> *ant;
};

template<typename T>
struct ListaDoble
{

public:

    ListaDoble() : actual(nullptr), primero(nullptr), ultimo(nullptr) {}
    ~ListaDoble();
    void insertar(T data);
    bool borrar(T data);
    bool vacia() { return primero == nullptr; }
    void siguiente();
    void anterior();
    void inicio();
    void fin();
    nodoDoble<T> *first() {return primero;}
    bool actualExiste() { return actual != nullptr; }
    T getActual();
    int size() { return tam; }
    nodoDoble<T> *actual;

private:
    nodoDoble<T> *primero;
    nodoDoble<T> *ultimo;
    int tam;
};

template<typename T>
ListaDoble<T>::~ListaDoble(){
    nodoDoble<T> *aux;

    actual = primero;
    while(actual!=nullptr){
        aux = actual;
        actual = actual->sig;
        delete aux;
    }
}

template<typename T>
void ListaDoble<T>::inicio(){
    actual = primero;
}

template<typename T>
void ListaDoble<T>::fin(){
    actual = ultimo;
}

template<typename T>
void ListaDoble<T>::siguiente(){
    if(actual != nullptr) actual = actual->sig;
}

template<typename T>
void ListaDoble<T>::anterior(){
    if(actual != nullptr) actual = actual->ant;
}

template<typename T>
T ListaDoble<T>::getActual(){
    if(actual) return actual->data;
    else return 0;
}

template<typename T>
void ListaDoble<T>::insertar(T data){
    nodoDoble<T> *nuevo = new nodoDoble<T>(data, tam);

    actual = primero;
    if(vacia() || actual->data > data){
        primero = nuevo;
        if(actual == nullptr){
            actual = nuevo;
            ultimo = nuevo;
        }else{
            nuevo->sig = actual;
            actual->ant = nuevo;
        }
    }else{
        while(actual->sig != nullptr && actual->sig->data <= data) actual = actual->sig;

        nuevo->sig = actual->sig;
        nuevo->ant = actual;
        actual->sig = nuevo;
        if(nuevo->sig) nuevo->sig->ant = nuevo;
        else ultimo = nuevo;
    }
    tam++;
}

template<typename T>
bool ListaDoble<T>::borrar(T data){
    nodoDoble<T> *aux;

    aux = primero;
    while(aux!=nullptr){
        if(aux->data == data){
            if(aux->sig != nullptr) aux->sig->ant = aux->ant;
            if(aux->ant != nullptr) aux->ant->sig = aux->sig;
            if(aux == primero) primero = primero->sig;
            if(aux == ultimo) ultimo = ultimo->ant;
            if(aux == actual) actual = actual->sig;
            delete aux;
            tam--;
            return true;
        }else{
            aux = aux->sig;
        }
    }
    return false;
}

#endif // LISTADOBLE_TEMPL_H
