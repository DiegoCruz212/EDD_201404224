#ifndef COLADOBLE_TEMPL_H
#define COLADOBLE_TEMPL_H
#include <stdlib.h>

template<typename G>
struct nodoColaD{
public:
    nodoColaD(G data, int i):
        data(data), index(i), sig(nullptr), ant(nullptr) {}

    G data;
    int index;
    nodoColaD<G> *sig;
    nodoColaD<G> *ant;
};

template<typename T>
struct ColaDoble
{

public:
    ColaDoble(): primero(nullptr), ultimo(nullptr), tama(0) {}
    ~ColaDoble();

    void insertar(T data);
    T sacar();
    T mirar();
    nodoColaD<T> *first() { return primero; }
    int size() { return tama; }

private:
    nodoColaD<T> *primero;
    nodoColaD<T> *ultimo;

    int tama;
};

template<typename T>
void ColaDoble<T>::insertar(T data){
    nodoColaD<T> *nuevo = new nodoColaD<T>(data, tama);

    if(ultimo != nullptr) ultimo->sig = nuevo;
    nuevo->ant = ultimo;
    ultimo = nuevo;
    if(!primero) primero = nuevo;

    tama++;
}

template<typename T>
T ColaDoble<T>::sacar(){
    nodoColaD<T> *aux;
    T reto;

    aux = primero;
    if(primero == nullptr) return reto;
//    primero->ant = nullptr;
    if(primero->sig != nullptr){
        primero->sig->ant = primero;
    }
    primero = primero->sig;
    reto = aux->data;
    delete aux;
    if(primero == nullptr) ultimo = nullptr;

    tama--;
    return reto;
}

template<typename T>
T ColaDoble<T>::mirar(){
    T reto;
    reto = primero->data;
    return reto;
}

template<typename T>
ColaDoble<T>::~ColaDoble(){
    while(primero != nullptr) sacar();
}

#endif // COLADOBLE_TEMPL_H
