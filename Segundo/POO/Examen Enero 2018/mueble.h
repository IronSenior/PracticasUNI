
#ifndef MUEBLE_H
#define MUEBLE_H

#include <string>



class Mueble{
    private:
        int id_;
        std::string nombre_;
        std::string modelo_;
        std::string fecha_;
        std::string color_;

    public:
        Mueble(int id, std::string nombre="NO_ASIGNADO", std::string modelo="NO_ASIGNADO",
               std::string fecha="NO_ASIGNADO", std::string color = "NO_ASIGNADO");

        //Observadores
        inline int getId() const {return id_;};
        inline std::string getNombre() const {return nombre_;};
        inline std::string getModelo() const {return modelo_;};
        inline std::string getFecha() const {return fecha_;};
        inline std::string getColor() const {return color_;};
        std::string getDatos();

        //Modificadores 
        void setID(int id);
        bool setNombre(std::string nombre);
        bool setModelo(std::string modelo);
        bool setFecha(std::string fecha);
        bool setColor(std::string color);


};


#endif