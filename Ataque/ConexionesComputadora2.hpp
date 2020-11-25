//
//  ConexionesComputadora2.hpp
//  Ataque
//
//  Created by Matías Méndez on 25/11/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#ifndef ConexionesComputadora2_hpp
#define ConexionesComputadora2_hpp


#include <stdio.h>
#include <iostream>
#include <map>
#include <set>

#include "ParConexion.hpp"

using namespace std;

//no se si conexiones sea una herencia de la clase adminsitrador y con el mismo constructor o si deba ser otra dfierente
class ConexionesComputadoras2  {
private:
    string ip;
    int conexiones_entrantes;
    int conexiones_salientes;
    
    
public:
    ConexionesComputadoras2()=default;
    ConexionesComputadoras2(string _ip,
    int _conexiones_entrantes, int _conexiones_salientes): ip(_ip),conexiones_entrantes(_conexiones_entrantes),
    conexiones_salientes(_conexiones_salientes){}
    
    string getIp(){return this->ip;}
    int getConexionesEntrantes(){return this->conexiones_entrantes;}
    int getConexionesSalientes(){return this->conexiones_salientes;}

    friend std::ostream & operator << (std::ostream & os, const ConexionesComputadoras2 & conexion);
};

std::ostream & operator << (std::ostream & os, const ConexionesComputadoras2 & conexion)
 {
     os<< "\n Entradas: " << conexion.conexiones_entrantes<<" -  Salidas: "<< conexion.conexiones_salientes ;
     return os;
      }

#endif /* ConexionesComputadora2_hpp */
