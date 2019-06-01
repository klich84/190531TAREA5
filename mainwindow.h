#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <particula.h>
#include <QMainWindow>
#include <QTimer>

#define dt 5.0  //controla cuantos pixeles avanza la particula en cada cuadro de escena
#define vertlim 450.0 //Limite vertical
#define horzlim 450.0 //Limite Horizontal

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *timer = new QTimer(this);

private slots:
    void actualizarEscena(void);
    void on_Button1_clicked();
    void on_Button2_clicked();

private:
    Ui::MainWindow *ui;
    Particula *particle = new Particula(10,30,5,5,10);  //Declarando un objeto grafico de la clase Particula
};

#endif // MAINWINDOW_H
