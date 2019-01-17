
#ifndef PEDIDO_H
#define PEDIDO_H

#include "mesa.h"
#include <cstdlib>
#include <string>
#include <list>


class Pedido{
    private:
        std::list<Mesa> pedidos_;
    public:
        Pedido();

        //Metodos
        void addPedido(Mesa mesa);
        inline int size(){return pedidos_.size();};
        bool deletePedido(std::string modelo);
        void write();

        
        
};
#endif