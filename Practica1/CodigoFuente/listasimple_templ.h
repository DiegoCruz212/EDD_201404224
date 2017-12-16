#ifndef LISTASIMPLE_TEMPL_H
#define LISTASIMPLE_TEMPL_H

template<typename G>
struct nodoSimple{
public:
    nodoSimple(G data, int i) : data(data), index(i), sig(nullptr) {}

    G data;
    int index;
    nodoSimple<G> *sig;
};

template<typename T>
struct ListaSimple{

public:
    ListaSimple() : actual(nullptr), primero(nullptr), ultimo(nullptr) {}
    ~ListaSimple();
    void insertarInicio(T data);
    void insertarFinal(T data);
    bool borrar(T data);
    T buscar(T data);
    bool vacia() { return primero == nullptr; }
    void siguiente();
    void anterior();
    void inicio();
    void fin();
    nodoSimple<T> *first() {return primero;}
    T getActual();
    int size() { return tam; }

    nodoSimple<T> *actual;


private:
    nodoSimple<T> *primero;
    nodoSimple<T> *ultimo;
    int tam;
};

template<class T>
ListaSimple<T>::~ListaSimple()
{
   while(!vacia()) {
      actual = primero;
      primero = primero->sig;
      delete actual;
   }
}

template<typename T>
void ListaSimple<T>::inicio(){
    actual = primero;
}

template<typename T>
void ListaSimple<T>::fin(){
    actual = ultimo;
}

template<typename T>
void ListaSimple<T>::siguiente(){
    if(actual != nullptr) actual = actual->sig;
}

template<typename T>
void ListaSimple<T>::anterior(){
    if(actual != nullptr) actual = actual->ant;
}

template<typename T>
T ListaSimple<T>::getActual(){
    if(actual) return actual->data;
    else return 0;
}

template<typename T>
void ListaSimple<T>::insertarFinal(T data){
    nodoSimple<T> *nuevo = new nodoSimple<T>(data,tam);

    if(vacia()){
        insertarInicio(data);
    }else{
        actual = primero;
        while(actual->sig != nullptr) actual = actual->sig;
        actual->sig = nuevo;
        ultimo = nuevo;
    }
}

template<typename T>
void ListaSimple<T>::insertarInicio(T data){
    nodoSimple<T> *nuevo = new nodoSimple<T>(data,tam);
    nuevo->sig = primero;
    primero = nuevo;
}

template<class T>
bool ListaSimple<T>::borrar(T data)
{
   nodoSimple<T> *ant = nullptr;
   nodoSimple<T> *aux = primero;

   if(!vacia()) {
      while(aux && aux->data != data) {
         ant = aux;
         aux = aux->sig;
      }
      if(aux!=nullptr) {
         if(ant != nullptr)
            ant->sig = aux->sig;
         else
           primero = aux->sig;
         delete aux;
         return true;
      }
   }
   return false;
}

template<class T>
T ListaSimple<T>::buscar(const T data)
{
   actual = primero;

   if(!vacia()) {
      while(actual && actual->data != data) {
         actual = actual->siguiente;
      }
   }
   if(actual) return actual->data;
   else return 0;
}

#endif // LISTASIMPLE_TEMPL_H
