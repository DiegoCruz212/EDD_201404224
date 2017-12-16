#ifndef GRAFIX_H
#define GRAFIX_H
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <string>
#include <sstream>
#include <iostream>
#include "cola_templ.h"
#include "coladoble_templ.h"
#include "listasimple_templ.h"
#include "listadoble_templ.h"
#include "listadoblecircular_templ.h"
#include "pila_templ.h"
#include "objetos.h"

using namespace std;

class Grafix
{
public:
    Grafix();
    void graficarAterrizaje(ColaDoble<Avion> &colaD, Cola<Pasajero> &cola);

private:
    void graficarColaPasajero(Cola<Pasajero> &cola);
    void graficarColaAvion(ColaDoble<Avion> &colaD);
    void graficarListaEscritorios(ListaDoble<Escritorio> &listaD);
    void graficarListaEquipaje(ListaDobleCir<int> &listaDC);
    void graficarListaEstaciones(ListaSimple<Estacion> &listaS);
    void graficarColaMantenimiento(Cola<Avion> &cola);
    void graficarPila(Pila<int> &pila);

    int num;

};

#endif // GRAFIX_H
