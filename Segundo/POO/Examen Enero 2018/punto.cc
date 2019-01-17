
#include "punto.h"


Punto Punto::operator +(Punto &p1){
    Punto aux((x_+p1.getX()), (y_+p1.getY()));
    return aux;
}
Punto Punto::operator -(Punto &p1){
    Punto aux((x_-p1.getX()), (y_-p1.getY()));
    return aux;
}

Punto Punto::operator ++(void){
    ++x_;
    ++y_;
    return *this;
}

Punto Punto::operator ++(int){
    x_++;
    y_++;
    return *this;
}

Punto operator+(int plus, Punto &p){
    Punto aux((p.getX()+plus),(p.getY()+plus));
    return aux;
}

Punto operator+(Punto &p, int plus){
    Punto aux((p.getX()+plus),(p.getY()+plus));
    return aux;
}

