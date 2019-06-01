#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <particula.h>
#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(actualizarEscena()));
    QGraphicsScene *escena = new QGraphicsScene();  //Reservando memoria para un puntero a un objeto escena de Qt
    ui->Fondo->setScene(escena);  //Montando la escena en el widget GraphicsView
    escena->addItem(particle); //Agregando el objeto grafico a la escena
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizarEscena(void)
{
    particle->moverParticula(dt, vertlim);
    particle->colisionParticula(horzlim, vertlim);
}

void MainWindow::on_Button1_clicked()
{
    timer->start(35);
    actualizarEscena();
}

void MainWindow::on_Button2_clicked()
{
    timer->stop();
}
