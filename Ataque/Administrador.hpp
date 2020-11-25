//
//  Administrador.hpp
//  Ataque
//
//  Created by Matías Méndez on 22/09/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#ifndef Administrador_hpp
#define Administrador_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include "UserFila.hpp"
#include "Ordenamiento.hpp"
#include "ConexionesComputadoras.hpp"
#include <vector>
#include <set>
#include <map>

using namespace std;

class Administrador{
protected:
    string fileName;
    vector<UserFila> registros;
    set<string> dominios;
    map <string,ConexionesComputadoras> diccionarioDominios;
   
    
public:
    long int size = registros.size();
    Administrador(vector<UserFila> r): registros(r){};
    Administrador(){}
    ~Administrador(){}
    auto read_fila();
    int contarRegistros();
    int contarXdia(string);
    void busqNombre(string);
    void busqRedInterna();
    void mostrarMail();
    void busqNombreDestino(string);
    void mostrarRangoPuertosD(int, int);
    void setDominios();
    set<string> getDominios(){return this->dominios;}
    void mapDominios();
    
};

#endif /* Administrador_hpp */
