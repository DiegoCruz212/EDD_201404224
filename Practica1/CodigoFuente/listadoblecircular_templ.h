#ifndef LISTADOBLECIRCULAR_TEMPL_H
#define LISTADOBLECIRCULAR_TEMPL_H

template<typename G>
struct nodoDobleCir{
public:
    nodoDobleCir(G data, int i) : data(data), index(i), sig(nullptr), ant(nullptr) {}

    G data;
    int index;
    nodoDobleCir<G> *sig;
    nodoDobleCir<G> *ant;
};

template<typename T>
struct ListaDobleCir
{

public:
    ListaDobleCir() : primero(nullptr), actual(nullptr), ultimo(nullptr), tam(0) {}
    ~ListaDobleCir();
    void insertar(T data);
    bool borrar(T data);
    void borrarPrim();
    bool vacia() { return primero == nullptr; }
    void siguiente();
    void anterior();
    void inicio();
    T getActual();
    nodoDobleCir<T> *first() {return primero;}
    int size() { return tam; }

    nodoDobleCir<T> *primero;
    nodoDobleCir<T> *actual;
    nodoDobleCir<T> *ultimo;

private:
    int tam;
};

template<typename T>
ListaDobleCir<T>::~ListaDobleCir(){
    nodoDobleCir<T> *aux;
    while(actual->sig != actual){
        aux = actual;
        aux->ant->sig = aux->sig;
        aux->sig->ant = aux->ant;
        actual = actual->sig;
        delete aux;
    }
    delete actual;
    actual = nullptr;
}

template<typename T>
void ListaDobleCir<T>::inicio(){
    actual = primero;
}

template<typename T>
void ListaDobleCir<T>::siguiente(){
    if(actual != nullptr) actual = actual->sig;
}

template<typename T>
void ListaDobleCir<T>::anterior(){
    if(actual != nullptr) actual = actual->ant;
}

template<typename T>
T ListaDobleCir<T>::getActual(){
    return actual->data;
}

template<typename T>
void ListaDobleCir<T>::insertar(T data){
    nodoDobleCir<T> *nuevo = new nodoDobleCir<T>(data, tam);

    if(vacia()){
        primero = nuevo;
        ultimo = nuevo;
        actual = nuevo;
        nuevo->ant = ultimo;
        nuevo->sig = primero;
    }else{
        primero->ant = nuevo;
        ultimo->sig = nuevo;
        nuevo->ant = ultimo;
        nuevo->sig = primero;
        ultimo = nuevo;
    }
    tam++;
}

template<typename T>
bool ListaDobleCir<T>::borrar(T data){
    nodoDobleCir<T> *aux;
    bool b=false;
    aux = primero;

    while(aux->data != data && b==false){
        if(aux->sig == primero) b = true;
        aux = aux->sig;
    }
    if(aux->data == data){
        if(aux->sig == aux){
            delete aux;
            actual = nullptr;
            primero = nullptr;
            ultimo = nullptr;
        }else{
            if(aux->sig != nullptr) aux->sig->ant = aux->ant;
            if(aux->ant != nullptr) aux->ant->sig = aux->sig;
            if(aux == primero) primero = primero->sig;
            if(aux == actual) actual = actual->sig;
            if(aux == ultimo) ultimo = ultimo->sig;
            delete aux;
        }
        tam--;
        return true;
    }
    return false;
}

template<typename T>
void ListaDobleCir<T>::borrarPrim(){
    nodoDobleCir<T> *aux;
    aux = primero;
    primero = primero->sig;
    if(aux->ant) aux->ant->sig = aux->sig;
    if(aux->sig) aux->sig->ant = aux->ant;
    if(aux == ultimo){
        aux->sig = nullptr;
        aux->ant = nullptr;
    }
    tam--;
    delete aux;
}

#endif // LISTADOBLECIRCULAR_TEMPL_H
