/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tabAterriza;
    QWidget *tabRegistro;
    QWidget *tabEquipaje;
    QWidget *tabMant;
    QPushButton *btnIniciar;
    QPushButton *btnTurno;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1004, 709);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 20, 961, 571));
        tabAterriza = new QWidget();
        tabAterriza->setObjectName(QStringLiteral("tabAterriza"));
        tabWidget->addTab(tabAterriza, QString());
        tabRegistro = new QWidget();
        tabRegistro->setObjectName(QStringLiteral("tabRegistro"));
        tabWidget->addTab(tabRegistro, QString());
        tabEquipaje = new QWidget();
        tabEquipaje->setObjectName(QStringLiteral("tabEquipaje"));
        tabWidget->addTab(tabEquipaje, QString());
        tabMant = new QWidget();
        tabMant->setObjectName(QStringLiteral("tabMant"));
        tabWidget->addTab(tabMant, QString());
        btnIniciar = new QPushButton(centralWidget);
        btnIniciar->setObjectName(QStringLiteral("btnIniciar"));
        btnIniciar->setGeometry(QRect(20, 600, 191, 41));
        btnTurno = new QPushButton(centralWidget);
        btnTurno->setObjectName(QStringLiteral("btnTurno"));
        btnTurno->setGeometry(QRect(808, 600, 171, 71));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabAterriza), QApplication::translate("MainWindow", "Aterrizaje", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabRegistro), QApplication::translate("MainWindow", "Registro", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabEquipaje), QApplication::translate("MainWindow", "Equipaje", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabMant), QApplication::translate("MainWindow", "Mantenimiento", Q_NULLPTR));
        btnIniciar->setText(QApplication::translate("MainWindow", "Inciar Simulacion", Q_NULLPTR));
        btnTurno->setText(QApplication::translate("MainWindow", "Siguiente\n"
"Turno", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
