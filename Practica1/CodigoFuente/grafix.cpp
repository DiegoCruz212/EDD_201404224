#include "grafix.h"

Grafix::Grafix()
{

}

stringstream graphviz;
stringstream relaciones;

void Grafix::graficarAterrizaje(ColaDoble<Avion> &colaD, Cola<Pasajero> &cola){
    graphviz.str(std::string());
    relaciones.str(std::string());
    QFile file("aterrizaje.dot");
    file.open(QIODevice::ReadWrite | QIODevice::Truncate);
    QTextStream texto(&file);
    texto<<"digraph G {\r\n node[shape=record, style=filled, fillcolor=khaki1, fontcolor=black]; \r\n"<<endl;
    graficarColaAvion(colaD);
    graficarColaPasajero(cola);
    texto<< QString::fromStdString(graphviz.str()) << endl;
    texto<< QString::fromStdString(relaciones.str()) <<  endl;
    texto<<"}"<<endl;
    file.close();
    system("dot -Tpng aterrizaje.dot -o aterrizaje.png");
}

void Grafix::graficarColaAvion(ColaDoble<Avion> &colaD){
    num = 0;
    nodoColaD<Avion> *aux = colaD.first();
    while(aux!=nullptr){
        graphviz << "a" << num << " [ label = \"{ " << "Avion" << num << endl;
        graphviz << "}\"]\r\n" << endl;

        if(aux->sig)
            relaciones<<"a" << num << "->" << "a" << num+1 << "\r\n";
        if(aux->ant)
            relaciones<<"a" << num << "->" << "a" << num-1 << "\r\n";
        aux = aux->sig;
        num++;
    }
}

void Grafix::graficarColaPasajero(Cola<Pasajero> &cola){
    num = 0;
    nodoCola<Pasajero> *aux = cola.first();
    while(aux!=nullptr){
        graphviz << "p" << num << " [ label = \"{ " << "Pasajero" + num << endl;
        graphviz << "}\"]\r\n" << endl;

        if(aux->sig)
            relaciones<<"p" << num << "->" << "p" << num+1 << "\r\n";

        aux = aux->sig;
        num++;
    }
}

void Grafix::graficarListaEquipaje(ListaDobleCir<int> &listaDC){
    num=0;
    nodoDobleCir<int> *aux = listaDC.first();
    while(aux->sig!= aux){
        graphviz << "m" << num << " [ label = \"{ " << "Maleta" << num << endl;
        graphviz << "}\"]\r\n" << endl;

        if(aux->sig)
            relaciones<<"m" << num << "->" << "m" << num+1 << "\r\n";
        if(aux->ant)
            relaciones<<"m" << num << "->" << "m" << num-1 << "\r\n";
        aux = aux->sig;
        num++;
    }
    graphviz << "m" << num << " [ label = \"{ " << "Maleta" << num << endl;
    graphviz << "}\"]\r\n" << endl;

    if(aux->sig)
        relaciones<<"m" << num << "->" << "m" << num+1 << "\r\n";
    if(aux->ant)
        relaciones<<"m" << num << "->" << "m" << num-1 << "\r\n";
}

void Grafix::graficarListaEscritorios(ListaDoble<Escritorio> &listaD){
    num=0;
    nodoDoble<Escritorio> *aux = listaD.first();
    while(aux->sig!= nullptr){
        graphviz << "e" << num << " [ label = \"{ " << "Escritorio" << num << endl;
        graphviz << "}\"]\r\n" << endl;

        if(aux->sig)
            relaciones<<"e" << num << "->" << "e" << num+1 << "\r\n";
        if(aux->ant)
            relaciones<<"e" << num << "->" << "e" << num-1 << "\r\n";
        aux = aux->sig;
        num++;
    }
}

void Grafix::graficarListaEstaciones(ListaSimple<Estacion> &listaS){
    num = 0;
    nodoSimple<Estacion> *aux = listaS.first();
    while(aux!=nullptr){
        graphviz << "es" << num << " [ label = \"{ " << "Estacion" + num << endl;
        graphviz << "}\"]\r\n" << endl;

        if(aux->sig)
            relaciones<<"es" << num << "->" << "es" << num+1 << "\r\n";

        aux = aux->sig;
        num++;
    }
}
