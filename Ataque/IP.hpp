//
//  IP.hpp
//  Ataque
//
//  Created by Matías Méndez on 12/10/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#ifndef IP_hpp
#define IP_hpp

#include <stdio.h>
#include <iostream>
using namespace std;



class IP{
private:
    string tipo;
    string IpOriginal;
    string IpCortada;
public:
    IP(string,string,string);
    string getIpCortada();
    string getIpOriginal();
};

#endif /* IP_hpp */
