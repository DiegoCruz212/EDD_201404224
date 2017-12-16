#ifndef PILA_TEMPL_H
#define PILA_TEMPL_H

template<typename T>
struct Pila
{
private:
    template<typename G>
    struct nodoPila{
    public:
        nodoPila(G data, int i):
            data(data), index(i), sig(nullptr) {}
        G data;
        int index;
        nodoPila<G> *sig;
    };

public:
    Pila(): primero(nullptr), ultimo(nullptr) {}
    ~Pila();

    void insertar(T data);
    T sacar();
    T mirar();
    int size() { return tam; }

private:
    nodoPila<T> *primero;
    nodoPila<T> *ultimo;

    int tam;
};

template<typename T>
Pila<T>::~Pila(){
    while(ultimo != nullptr) sacar();
}

template<typename T>
void Pila<T>::insertar(T data){
    nodoPila<T> *nuevo = new nodoPila<T>(data,tam);
    nuevo->sig = ultimo;
    ultimo = nuevo;

    tam++;
}

template<typename T>
T Pila<T>::sacar(){
    nodoPila<T> *aux;
    T reto;

    if(ultimo == nullptr) return 0;
    aux = ultimo;
    ultimo = aux->sig;
    reto = aux->data;
    delete aux;

    tam--;
    return reto;
}

template<typename T>
T Pila<T>::mirar(){
    T reto;
    reto = ultimo->data;
    return reto;
}

#endif // PILA_TEMPL_H
