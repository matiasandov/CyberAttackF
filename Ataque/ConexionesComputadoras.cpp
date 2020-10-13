//
//  ConexionesComputadoras.cpp
//  Ataque
//
//  Created by Matías Méndez on 11/10/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#include "ConexionesComputadoras.hpp"
//el nombre debera ser "/Users/matiasmendez/Downloads/equipo1.csv"
ConexionesComputadoras::ConexionesComputadoras(string name){
    fileName = name;
    
    /* Crear un input filestream para leer el archivo CSV */
    ifstream file(fileName);

    /* Verificar si no hubo error al abrir el archivo */
    if(!file.is_open()) throw runtime_error("No se puede abrir el archivo");

    /* Definir variable que almacena cada línea */
    string linea;
    
    /* Leer datos línea a línea */
    while(getline(file, linea))
    {
        /* Crear un steam de la línea */
        stringstream ss(linea);
    
        /* Variables que almacenan cada campo leído */
        string f;
        string h;
        string iO;
        string pO;
        string nO;
        string iD;
        string pD;
        string nD;
        
        /* Iterar sobre la línea para extraer cada campo */
        getline(ss, f, ',');
        getline(ss, h, ',');
        getline(ss, iO, ',');
        getline(ss, pO, ',');
        getline(ss, nO, ',');
        getline(ss, iD, ',');
        //esto no funciona porque yo quiero ingresar un int y getline no se ocupara ints
        getline(ss, pD, ',');
        getline(ss, nD, ',');
        
       
       
//lo que ocurre es que se voltea la dirección IP de origin y todo lo que está en el útilmo octeto se borra
//para cortar IP origen y compararla
           string ip_found = iO;
           reverse(ip_found.begin(), ip_found.end());
           int pos = ip_found.find(".");
           string cutIPorigen = ip_found.substr(pos + 1);
           reverse(cutIPorigen.begin(), cutIPorigen.end());
          
        
        
//para cortar IP Destino y compararla
          string ip_found2 = iD;
          reverse(ip_found2.begin(), ip_found2.end());
          int pos2 = ip_found2.find(".");
          string cutIPDestino = ip_found2.substr(pos2 + 1);
          reverse(cutIPDestino.begin(), cutIPDestino.end());
          
       
        /*IP(string ipOri, string ipCorta, string type)*/
        if (cutIPDestino == "10.152.206"){
            entrantes().push( IP(iD,cutIPDestino,"destino") );
            IpInterna = cutIPDestino;
        }
        
        /*IP(string ipOri, string ipCorta, string type)*/
        if (cutIPorigen == "10.152.206"){
            salientes().enqueue( IP(iO, cutIPorigen, "origen") );
        }
        
    }

    /* Cerrar el archivo */
    file.close();
}


void ConexionesComputadoras::ReadClassifyConexion(){
    /* Crear un vector de vector de strings
    vector<UserFila> lineas;*/

    /* Crear un input filestream para leer el archivo CSV */
    ifstream file(fileName);

    /* Verificar si no hubo error al abrir el archivo */
    if(!file.is_open()) throw runtime_error("No se puede abrir el archivo");

    /* Definir variable que almacena cada línea */
    string linea;
    
    /* Leer datos línea a línea */
    while(getline(file, linea))
    {
        /* Crear un steam de la línea */
        stringstream ss(linea);
    
        /* Variables que almacenan cada campo leído */
        string f;
        string h;
        string iO;
        string pO;
        string nO;
        string iD;
        string pD;
        string nD;
        
        /* Iterar sobre la línea para extraer cada campo */
        getline(ss, f, ',');
        getline(ss, h, ',');
        getline(ss, iO, ',');
        getline(ss, pO, ',');
        getline(ss, nO, ',');
        getline(ss, iD, ',');
        //esto no funciona porque yo quiero ingresar un int y getline no se ocupara ints
        getline(ss, pD, ',');
        getline(ss, nD, ',');
        
       
       
//lo que ocurre es que se voltea la dirección IP de origin y todo lo que está en el útilmo octeto se borra
//para cortar IP origen y compararla
           string ip_found = iO;
           reverse(ip_found.begin(), ip_found.end());
           int pos = ip_found.find(".");
           string cutIPorigen = ip_found.substr(pos + 1);
           reverse(cutIPorigen.begin(), cutIPorigen.end());
          
        
        
//para cortar IP Destino y compararla
          string ip_found2 = iD;
          reverse(ip_found2.begin(), ip_found2.end());
          int pos2 = ip_found2.find(".");
          string cutIPDestino = ip_found2.substr(pos2 + 1);
          reverse(cutIPDestino.begin(), cutIPDestino.end());
          
       
        /*IP(string ipOri, string ipCorta, string type)*/
        if (cutIPDestino == "10.152.206"){
            entrantes().push( IP(iD,cutIPDestino,"destino") );
        }
        
        /*IP(string ipOri, string ipCorta, string type)*/
        if (cutIPorigen == "10.152.206"){
            salientes().enqueue( IP(iO, cutIPorigen, "origen") );
        }
        
    }

    /* Cerrar el archivo */
    file.close();
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
