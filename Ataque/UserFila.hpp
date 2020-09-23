//
//  UserFila.hpp
//  Ataque
//
//  Created by Matías Méndez on 23/09/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#ifndef UserFila_hpp
#define UserFila_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class UserFila {
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
    UserFila(string f, string h, string iO, string pO, string nO, string iD, string pD, string nD):
    fecha(f), hora(h), ipOrigen(iO), puertoOrigen(pO), nombreOrigen(nO), ipDestino(iD),puertoDestino(pD), nombreDestino(nD) {}
    
    //sobrecarga de operador para imrimir y poder ser ocupado en otras clases
    friend std::ostream & operator<<(std::ostream & os, const UserFila & userFila);
};


#endif /* UserFila_hpp */
