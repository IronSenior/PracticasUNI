
#ifndef PUNTO_H
#define PUNTO_H

class Punto{
    private:
        int x_;
        int y_;

    public:
        Punto(int x, int y);

        //Observadores
        inline int getX() const {return x_;};
        inline int getY() const {return y_;};   

        //Operadores
        Punto operator+(Punto &p1);
        Punto operator-(Punto &p1);
        Punto operator++(void); //++x
        Punto operator++(int); //x++
        friend Punto operator+(int plus, Punto &p);
        friend Punto operator+(Punto &p, int plus);

};

#endif