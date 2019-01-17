
#ifndef MESA_H
#define MESA_H

#include "mueble.h"
#include <string>

class Mesa : public Mueble{
    private:
        int patas_;
        std::string material_;
    public:
        Mesa(int id, std::string nombre="mesa", std::string material="NO_ASIGNADO", int patas=0, std::string modelo="NO_ASIGNADO",
               std::string fecha="NO_ASIGNADO", std::string color = "NO_ASIGNADO"):Mueble(id, nombre, modelo, fecha, color)
               {material_ = material; patas_ = patas;};
        
        //Observadores
        inline int getPatas() const {return patas_;};
        inline std::string getMaterial() const {return material_;};

        //Modificadores
        inline void setPatas(int patas){patas_ = patas;};
        bool setMaterial(std::string material);

        //Metodos
        bool checkEstado();
};

#endif