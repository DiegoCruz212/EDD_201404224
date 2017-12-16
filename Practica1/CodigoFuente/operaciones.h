#ifndef OPERACIONES_H
#define OPERACIONES_H
#include <iostream>
#include "cola_templ.h"
#include "coladoble_templ.h"
#include "listasimple_templ.h"
#include "listadoble_templ.h"
#include "listadoblecircular_templ.h"
#include "pila_templ.h"
#include "objetos.h"
#include "grafix.h"

class Operaciones
{
public:
    Operaciones();

    void iniciarSimulacion(int nA, int mE, int kM);
    void turno();

private:
    Avion crearAvion();
    Pasajero crearPasajero(int id);
    void desabordar(int pas);
    void pushColaRegistro();
    void popColaRegistro();
    void dejarEquipaje(int nMaletas);
    void sacarEquipaje(int nMaletas);
    void iraMantenimiento();
    void darMantenimiento();
    void turno(int nA);

    //Estructuras
    ColaDoble<Avion> aterrizaje;
    Cola<Pasajero> pasajeros;
    ListaDoble<Escritorio> escritorios;
    ListaDobleCir<int> equipaje;
    ListaSimple<Estacion> mantenimiento;
    Cola<Avion> esperaMant;

    //Auxiliares
    char esc;
    int nuAv;
    Grafix ga;
};

#endif // OPERACIONES_H
