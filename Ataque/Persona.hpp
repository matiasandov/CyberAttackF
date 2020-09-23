//
//  Persona.hpp
//  Ataque
//
//  Created by Matías Méndez on 22/09/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//


#ifndef Persona_hpp
#define Persona_hpp

#include <iostream>
using namespace std;

class Persona {
private:
    string fecha;
    string hora;
    string ipOrigen;
    string puertoOrigen;
    string nombreOrigen;
    string ipDestino;
    string puertoDestino;
    string nombreDestino;
    
public:
    //constructor
    Persona(string f, string h, string iO, string pO, string nO, string iD, string pD, string nD):
    fecha(f), hora(h), ipOrigen(iO), puertoOrigen(pO), nombreOrigen(nO), ipDestino(iD),puertoDestino(pD), nombreDestino(nD) {}
    
    //sobrecarga de operador para imrimir y poder ser ocupado en otras clases
    friend std::ostream & operator<<(std::ostream & os, const Persona & persona);
};

#endif /* Persona_hpp */
