//
//  ConexionesComputadoras.cpp
//  Ataque
//
//  Created by Matías Méndez on 11/10/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#include "ConexionesComputadoras.hpp"
//el nombre debera ser "/Users/matiasmendez/Downloads/equipo1.csv"



ConexionesComputadoras::ConexionesComputadoras(vector<UserFila> r, string IpIngresada){
    registros = r;
    
    for (int i=0; i<registros.size() ; i++) {
        
        string ip_found = registros[i].getIpO();
        reverse(ip_found.begin(), ip_found.end());
        int pos = ip_found.find(".");
        string cutIPorigen = ip_found.substr(pos + 1);
        reverse(cutIPorigen.begin(), cutIPorigen.end());
       
     
     
//para cortar IP Destino y compararla
       string ip_found2 = registros[i].getIpD();
       reverse(ip_found2.begin(), ip_found2.end());
       int pos2 = ip_found2.find(".");
       string cutIPDestino = ip_found2.substr(pos2 + 1);
       reverse(cutIPDestino.begin(), cutIPDestino.end());
       
    
     /*IP(string ipOri, string ipCorta, string type)*/
     if (cutIPDestino == "10.152.206"){
         entrantes().push( registros[i] );
     }
     
     /*IP(string ipOri, string ipCorta, string type)*/
     if (cutIPorigen == "10.152.206"){
         salientes().enqueue( registros[i]);
     }
   }
    
    IpInternaNueva = IpBase + IpIngresada;
}



//1. mientras ni una ni otra este vacia, getIPcortada 2. string nueva = getIPcortada + "." + ingresada 3. imprimir

void ConexionesComputadoras::generarIpInterna(string IpIngresada){
    
    //no se como hacer para llamar la info de getIpCortada
    string IpGenerada = IpInterna+ "." + IpIngresada ;
    salientes().enqueue(IP(IpGenerada, IpInterna, "origen"));
}

void ConexionesComputadoras::countEntrantes(){
    cout << "\n Las conexiones entrantes son: " << sizeof(entrantes());
}

void ConexionesComputadoras::countSalientes(){
    cout << "\n Las conexiones salientes son: " << sizeof(salientes());
}

void ConexionesComputadoras::ultimaConexion(){
    //no me deja llamar a este getter
      string lastIP = entrantes().top()->getIpOriginal();
    
    if(lastIP.size() == 10){
        cout << "\n La última conexión es :" << lastIP <<" y es interna ";
    }
    else{
        cout << "\n La última conexión es :" << lastIP <<" y es externa ";
    }
    
}
