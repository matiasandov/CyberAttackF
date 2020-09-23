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
#include "Persona.hpp"
#include <vector>
using namespace std;

class Administrador{
private:
    vector<Persona> elementos;
public:
    int contarRegistros();
    int contarXdia();
    void busqNombre();
    void busqRedInterna();
    void busqMail();
    
};

#endif /* Administrador_hpp */
