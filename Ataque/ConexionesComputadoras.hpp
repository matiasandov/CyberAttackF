//
//  ConexionesComputadoras.hpp
//  Ataque
//
//  Created by Matías Méndez on 11/10/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#ifndef ConexionesComputadoras_hpp
#define ConexionesComputadoras_hpp

#include <stdio.h>
#include <iostream>
#include "Administrador.hpp"
#include "/Users/matiasmendez/Desktop/PF/Listas_Enlazadas/Listas_Enlazadas/LinkedList.hpp"
#include "/Users/matiasmendez/Desktop/PF/Listas_Enlazadas/Stack/Stack/Stack.hpp"
#include "/Users/matiasmendez/Desktop/PF/Listas_Enlazadas/Queue/Queue/Queue.hpp"
#include "IP.hpp"

//no se si conexiones sea una herencia de la clase adminsitrador y con el mismo constructor o si deba ser otra dfierente 
class ConexionesComputadoras  {
private:
    vector<UserFila> registros;
    string fileName;
    
    Stack<IP> entrantes();
    Queue<IP> salientes();
    //1. Ip interna que se esta usando
    string IpInterna;
    
public:
    /*ConexionesComputadoras(vector<UserFila> r): Administrador::registros(r){};*/
    //el nombre debera ser "/Users/matiasmendez/Downloads/equipo1.csv"
    ConexionesComputadoras(string name);
    void virtual ReadClassifyConexion();
    void generarIpInterna(string);
    
    void countEntrantes();
    void countSalientes();
    
};



#endif /* ConexionesComputadoras_hpp */
