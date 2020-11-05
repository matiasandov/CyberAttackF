//
//  ParConexion.cpp
//  Ataque
//
//  Created by Matías Méndez on 04/11/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#include "ParConexion.hpp"


std::ostream & operator << (std::ostream & os, const ParConexion & par)
{
    os << "\n " << par.keySitio   ;
    os << "\n "<< par.countSitio  << endl ;
    
    return os;
}

bool ParConexion::operator <( ParConexion & other)
{
    return (countSitio < other.countSitio);
}

bool ParConexion::operator >( ParConexion & other)
{
    return (countSitio > other.countSitio);
}
