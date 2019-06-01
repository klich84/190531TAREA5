#include "particula.h"

Particula::Particula(float x, float y, float velx, float vely, float r)
             : QGraphicsItem()
{
        px = x;
        py = y;
        vx = velx;
        vy = vely;
        rad = r;
}

Particula::~Particula()  //Un destructor por defecto
{
}

QRectF Particula::boundingRect() const  //Implementacion del metodo boundingRect
{
    return QRectF(-1*rad,-1*rad,2*rad,2*rad);   // Creando el area rectangular para delimitar la Particula (es una particula circular)
}

//metodo que actualiza la posicion de la particula

void Particula::moverParticula(float dt, float vertlim)
{
    px += vx*dt;        //Posicion x
    py += vy*dt;        //Pocision y

    setPos(px, vertlim-py);
}

// metodo que verifica que haya sucedido una colision

void Particula::colisionParticula(float horzlim, float vertlim)
{
    //Si la colision es con una barrera en sentido de avance horizontal (adelante o atras)
    if((px < rad) || (px > horzlim - rad))
        vx = -1*vx;

    //Si la colision es con una barrera en sentido de avance vertical (arriba o abajo)
    if((py < rad) || (py > vertlim - rad))
        vy = -1*vy;
}
