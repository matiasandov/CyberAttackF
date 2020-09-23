//
//  UserFila.cpp
//  Ataque
//
//  Created by Matías Méndez on 23/09/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#include "UserFila.hpp"

ostream & operator<<(std::ostream & os, const UserFila & userFila)
{
    os << userFila.fecha << " - ";
    os << userFila.hora << " - ";
    os << userFila.ipOrigen << " - ";
    os << userFila.puertoOrigen << " - ";
    os << userFila.nombreOrigen << " - ";
    os << userFila.ipDestino << " - ";
    os << userFila.puertoDestino << " - ";
    os << userFila.nombreDestino << " - ";
    os << endl;
    
    return os;
}
