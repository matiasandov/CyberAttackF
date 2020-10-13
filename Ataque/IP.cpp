//
//  IP.cpp
//  Ataque
//
//  Created by Matías Méndez on 12/10/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#include "IP.hpp"

IP::IP(string ipOri, string ipCorta, string type){
    IpOriginal = ipOri;
    IpCortada = ipCorta;
    tipo = type;
    
}

string IP::getIpCortada(){
    return this->IpCortada;
}

string IP::getIpOriginal(){
    return this->IpOriginal;
}
