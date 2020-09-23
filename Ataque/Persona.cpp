//
//  Persona.cpp
//  Ataque
//
//  Created by Matías Méndez on 22/09/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#include "Persona.hpp"


std::ostream & operator<<(std::ostream & os, const Persona & persona)
{
    os << persona.fecha << " - ";
    os << persona.hora << " - ";
    os << persona.ipOrigen << " - ";
    os << persona.puertoOrigen << " - ";
    os << persona.nombreOrigen << " - ";
    os << persona.ipDestino << " - ";
    os << persona.puertoDestino << " - ";
    os << persona.nombreDestino << " - ";
    os << endl;
    
    return os;
}
