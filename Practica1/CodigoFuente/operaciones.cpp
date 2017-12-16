#include "operaciones.h"
#include <stdlib.h>
#include <time.h>

Operaciones::Operaciones()
{
    srand(time(NULL));
    esc = 'A';
}

void Operaciones::iniciarSimulacion(int nA, int mE, int kM){
    int i;
    for(i=0;i<mE;i++){
        Escritorio nuevo("E"+std::string(&esc));
        escritorios.insertar(nuevo);
        esc++;
    }
    esc = 'A';
    for(i=0;i<kM;i++){
        Estacion nueva("M"+std::string(&esc));
        mantenimiento.insertarFinal(nueva);
        esc++;
    }

    this->nuAv = nA;
}

Avion Operaciones::crearAvion(){
    int ti, pa, td, tm;
    ti = 1+rand()%(3);
    if(ti == 1){
        pa = 5+rand()%(6);
        td = 1;
        tm = 1+rand()%(3);
    }else if(ti == 2){
        pa = 15+rand()%(11);
        td = 2;
        tm = 2+rand()%(3);
    }else if(ti == 3){
        pa = 30+rand()%(11);
        td = 3;
        tm = 3+rand()%(4);
    }

    Avion nuevo(ti,pa,td,tm);
    return nuevo;
}

Pasajero Operaciones::crearPasajero(int id){
    int ma, dc, tr;
    ma = 1+rand()%(4);
    dc = 1+rand()%(10);
    tr = 1+rand()%(3);

    Pasajero nuevo(id,ma,dc,tr);
    return nuevo;
}

void Operaciones::desabordar(int pas){
    for(int i=1; i<=pas; i++){
        pasajeros.insertar(crearPasajero(i));
    }
}

void Operaciones::pushColaRegistro(){
    escritorios.inicio();
    while(escritorios.actual != nullptr){
        while(escritorios.actual->data.colaRegistro.size()<10 &&
              pasajeros.size()>0){
            Pasajero at = pasajeros.sacar();
            int d = at.docs;
            int m = at.maletas;
            escritorios.actual->data.colaRegistro.insertar(at);
            int i;
            for(i=1;i<=d;i++){
                escritorios.actual->data.documentos.insertar(i);
            }
            dejarEquipaje(m);
        }
        escritorios.siguiente();
    }
}

void Operaciones::popColaRegistro(){
    escritorios.inicio();
    while(escritorios.actual != nullptr){
        if(escritorios.actual->data.colaRegistro.size()>0){
            int t = escritorios.actual->data.colaRegistro.mirar().mTurno();
            if(t==0){
                Pasajero p = escritorios.actual->data.colaRegistro.sacar();
                int m = p.maletas;
                while(escritorios.actual->data.documentos.size()>0){
                    escritorios.actual->data.documentos.sacar();
                }
                sacarEquipaje(m);
            }
        }
        escritorios.siguiente();
    }
}

void Operaciones::dejarEquipaje(int nMaletas){
    int i;
    for(i = 0; i<nMaletas; i++) equipaje.insertar(0);
}

void Operaciones::sacarEquipaje(int nMaletas){
    int i;
    for(i=0; i<nMaletas; i++) equipaje.borrarPrim();
}

void Operaciones::iraMantenimiento(){
    mantenimiento.inicio();
    while(mantenimiento.actual != nullptr){
        if(!mantenimiento.actual->data.reparando){
            mantenimiento.actual->data.avion = esperaMant.sacar();
            mantenimiento.actual->data.reparando = true;
        }
        mantenimiento.siguiente();
    }
}


void Operaciones::darMantenimiento(){
    mantenimiento.inicio();
    while(mantenimiento.actual != nullptr){
        int t = mantenimiento.actual->data.avion.mMant();
        if(t==0){
            mantenimiento.actual->data.reparando = false;
        }
        mantenimiento.siguiente();
    }
}

void Operaciones::turno(){
    if(nuAv>0){
        aterrizaje.insertar(crearAvion());
        nuAv--;
    }
    int td = aterrizaje.mirar().mDesa();
    if(td == 0){
        desabordar(aterrizaje.mirar().pasajeros);
        esperaMant.insertar(aterrizaje.sacar());
    }
    iraMantenimiento();
    pushColaRegistro();


    darMantenimiento();
    popColaRegistro();

    ga.graficarAterrizaje(aterrizaje,pasajeros);
}

