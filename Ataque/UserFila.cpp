//
//  UserFila.cpp
//  Ataque
//
//  Created by Matías Méndez on 23/09/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#include "UserFila.hpp"
#include <stdio.h>
#include <iostream>

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

string UserFila::getFecha(){
    return fecha;
}

string UserFila::getHora(){
    return hora;
}

string UserFila::getIpO(){
    return ipOrigen;
}

string UserFila::getPuertoO(){
    return puertoOrigen;
}

string UserFila::getNombreO(){
    return nombreOrigen;
}

string UserFila::getIpD(){
    return ipDestino;
}

string UserFila::getPuertoD(){
    return puertoDestino;
}

string UserFila::getNombreD(){
    return nombreDestino;
}

//para comparar todo por fecha

bool UserFila::fecha_asc(UserFila co, UserFila b){
    return co.fecha < b.fecha;
}
