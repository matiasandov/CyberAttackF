//
//  ParConexion.cpp
//  Ataque
//
//  Created by Matías Méndez on 04/11/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#include "ParConexion.hpp"

template <class T>
std::ostream & operator << (std::ostream & os, const ParConexion & par)
{
    os << "\n " << par.keySitio   ;
    os << "\n "<< par.countSitio  << endl ;
    
    return os;
}
