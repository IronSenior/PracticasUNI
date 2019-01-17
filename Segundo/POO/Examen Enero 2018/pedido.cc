
#include "mesa.h"
#include "pedido.h"
#include <cstdlib>
#include <list>
#include <fstream>
#include <string>

bool Pedido::deletePedido(std::string modelo){
    //Borrará modelo de la lista de pedidos
    //Si el modelo no fuese unico y hubiese mas de uno habría que modificar la funcion
    //yo pondría un contador cada vez que borrase y si es diferente a 0 devuelve true (de lo contrario false)
    std::list<Mesa>::iterator mesait;
    for(mesait= pedidos_.begin(); mesait != pedidos_.end(); mesait++){
        if (mesait->getModelo() == modelo){
            pedidos_.erase(mesait);
            return true;
        }
    }

    return false;
}

void Pedido::write(){
    std::ofstream fichero;

    fichero.open("salida.txt");
    int posicion=0;

    std::list<Mesa>::iterator mesait;
    for(mesait= pedidos_.begin(); mesait != pedidos_.end(); mesait++){
        fichero<<posicion<<","<<mesait->getId()<<","<<mesait->getNombre()<<","<<mesait->getModelo()<<","<<mesait->getMaterial()<<std::endl;
        posicion++;
    }
    
    fichero.close();
}


