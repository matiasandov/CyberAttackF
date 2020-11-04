//
//  ParConexion.hpp
//  Ataque
//
//  Created by Matías Méndez on 04/11/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#ifndef ParConexion_hpp
#define ParConexion_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class ParConexion{
protected:
    string keySitio;
    int countSitio;
    
public:
    
    ParConexion(string _keySitio, int _countSitio){
        keySitio = _keySitio;
        countSitio = _countSitio;
    }
    
    int getCountSitio();
    
    bool operator==(ParConexion uf){
        if (keySitio==uf.keySitio &&
            countSitio==uf.countSitio )
            {
                return true;
            }
            else
            {
                return false;
            }
    }
    
    bool operator!=(ParConexion uf){
        if (keySitio!=uf.keySitio &&
            countSitio!=uf.countSitio )
            {
                return true;
            }
            else
            {
                return false;
            }
    }
    
    
};

#endif /* ParConexion_hpp */
