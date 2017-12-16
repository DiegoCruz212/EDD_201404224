#include "mainwindow.h"
#include <QApplication>
#include "operaciones.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    ListaDobleCir<int> prueba;
//    for(int i=0; i<5;i++) prueba.insertar(i);

//    prueba.inicio();
//    do{
//        std::cout<<prueba.actual->data<<std::endl;
//        prueba.siguiente();
//        if(prueba.primero) prueba.borrarPrim();
//    }while(prueba.actual->sig != prueba.primero);
//    if(prueba.primero) prueba.borrarPrim();

    Operaciones o;
    o.iniciarSimulacion(4,3,3);
    o.turno();
    o.turno();

    return a.exec();
}
