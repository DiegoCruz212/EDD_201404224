#ifndef OBJETOS_H
#define OBJETOS_H
#include <string>
#include "cola_templ.h"
#include "pila_templ.h"

struct Avion
{
public:
    Avion(int ti, int pas, int td, int tm, int prob = 0) :
        tipo(ti), pasajeros(pas), tDesabord(td), tMant(tm), prob(prob) {}
    Avion() :
        tipo(0), pasajeros(0), tDesabord(0), tMant(0), prob(0) {}

    int tipo; //1 = pequeno, 2 = mediano, 3 = grande
    int pasajeros;
    int tDesabord;
    int tMant;
    double prob;

    int mMant() { return --tMant; }
    int mDesa() { return --tDesabord; }
};

struct Pasajero{
public:
    Pasajero(int id, int ma, int docs, int tr) :
        id(id), maletas(ma), docs(docs), tRegistro(tr) {}
    Pasajero() {}

    int id;
    int maletas;
    int docs;
    int tRegistro;

    int mTurno() { return --tRegistro; }
};

struct Escritorio{
public:
    Escritorio() {}
    Escritorio(std::string nom) : nombre(nom) {}

    std::string nombre;
    Cola<Pasajero> colaRegistro;
    Pila<int> documentos;

    bool operator==(const Escritorio &e) const {
        return nombre == e.nombre;
    }
    bool operator!=(const Escritorio &e) const {
        return nombre != e.nombre;
    }
    bool operator<(const Escritorio &e) const {
        return nombre < e.nombre;
    }
    bool operator>(const Escritorio &e) const {
        return nombre > e.nombre;
    }
    bool operator<=(const Escritorio &e) const {
        return nombre <= e.nombre;
    }
    bool operator>=(const Escritorio &e) const {
        return nombre >= e.nombre;
    }
};

struct Estacion
{
public:
    Estacion(std::string nom) : nombre(nom), reparando(false) {}
    Estacion() {}
    std::string nombre;
    bool reparando;
    Avion avion;
};

#endif // OBJETOS_H
