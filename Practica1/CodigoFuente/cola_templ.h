#ifndef COLA_TEMPL_H
#define COLA_TEMPL_H

template<typename G>
struct nodoCola{
public:
    nodoCola(G data, int i):
        data(data), index(i), sig(nullptr) {}
    G data;
    int index;
    nodoCola<G> *sig;
};

template<typename T>
struct Cola
{

public:
    Cola(): primero(nullptr), ultimo(nullptr) {}
    ~Cola();

    void insertar(T data);
    T sacar();
    T mirar();
    nodoCola<T> *first() {return primero; }
    int size() { return tama; }

private:
    nodoCola<T> *primero;
    nodoCola<T> *ultimo;

    int tama;

    friend class Graficador;
};

template<typename T>
void Cola<T>::insertar(T data){
    nodoCola<T> *nuevo = new nodoCola<T>(data,tama);

    if(ultimo != nullptr) ultimo->sig = nuevo;
    ultimo = nuevo;
    if(!primero) primero = nuevo;

    tama++;
}

template<typename T>
T Cola<T>::sacar(){
    nodoCola<T> *aux;
    T reto;

    aux = primero;
    if(aux == nullptr) return reto;
    primero = aux->sig;
    reto = aux->data;
    delete aux;
    if(primero == nullptr) ultimo = nullptr;

    tama--;
    return reto;
}

template<typename T>
T Cola<T>::mirar(){
    T reto;
    if(primero) reto = primero->data;
    return reto;
}

template<typename T>
Cola<T>::~Cola(){
    while(primero != nullptr) sacar();
}

#endif // COLA_TEMPL_H
