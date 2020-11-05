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
    this->registros = r;
    
    if ( 0 < atoi(IpIngresada.c_str()) && atoi(IpIngresada.c_str()) < 150 )
    {
        this->Ip = IpBase + "." + IpIngresada;
        
        for (int i=0; i<registros.size() ; i++) {
        

         /*IP(string ipOri, string ipCorta, string type)*/
         if ( registros[i].getIpD() == Ip){
             //cout<<registros[i]<<endl;
             entrantes.push(registros[i]);
             
         }

         /*IP(string ipOri, string ipCorta, string type)*/
         if (registros[i].getIpO() == Ip){
             //cout<<registros[i]<<endl;
             
             salientes.push_back( registros[i]);
         }
       }
        
    }
    else{
        cout << "\n IP interna no invalida, asegurate de ingresar un numero entre 1 y 150 ";
    }
     
}



//1. mientras ni una ni otra este vacia, getIPcortada 2. string nueva = getIPcortada + "." + ingresada 3. imprimir

void ConexionesComputadoras::setIp(string nueva){
    
    if ( 0 < atoi(nueva.c_str()) && atoi(nueva.c_str()) < 150 )  {
        Ip =  IpBase + "." + nueva;
    } else{
        cout << "\n IP interna no invalida, asegurate de ingresar un numero entre 1 y 150 ";
    }
    
}


//1
string ConexionesComputadoras::getIpInternaNueva(){
    return Ip;
}


//3 y 4
void ConexionesComputadoras::countEntrantes(){
    cout << "\n Las conexiones entrantes son: " << this->entrantes.size();
}

void ConexionesComputadoras::countSalientes(){
    cout << "\n Las conexiones salientes son: " << this->salientes.size();
}

void ConexionesComputadoras::ultimaConexion(){
    
    //no me deja llamar a este getter
    string lastIP = this -> entrantes.top()->getInfo().getIpO() ;
    
    //recortar lastIp
    
    //esta mal creo no pelar
    if(lastIP == IpBase ){
        cout << "\n La última conexión es :" << lastIP <<" y es interna ";
    }
    else{
        cout << "\n La última conexión es :" << lastIP <<" y es externa ";
    }
    
}

void ConexionesComputadoras::conexionesSeguidas(){
    //en salientes, que prev, actual y sig sean iguales
    
    //temporal para guardar posicion previa
    int cont = 0;
        
        //temporal que ira avanzado en la lista/ cambiar a lista mejor para no borrar lo del frente
        /*UserFila  actual = salientes()[0];
        
        UserFila sig = salientes()[1];*/
    //puerto 80 o 443 y que sea el mismo nombreDestino
    //pisiconarme en registro y comparar con sig nombredestino y puerto destino, sino reinciar contador hasta recorrer todo la lista
    int step = 0;
    for (int i = 0; i <= salientes.size() && cont <=3 ; i++) {
        step++;
        if (salientes[i].getPuertoD() == "80" || salientes[i].getPuertoD() == "443") {
            if ((salientes[i+1].getPuertoD() == "80" || salientes[i+1].getPuertoD() == "443")) {
                if (salientes[i].getNombreD() ==  salientes[i+1].getNombreD()) {
                    cont++;
                }else{
                    cont = 0;
                }
            }
        }
    }
    
    if (cont == 3) {
        cout << "\n Se encontraron 3 conexiones seguidas para el sitio " << registros[step-2].getNombreD()<<endl ;
    }else{
        cout << "\n No se encontraron 3 conexiones seguidas "<<endl ;
    }
    
}

map <string, int> ConexionesComputadoras::conexionesPorDia(string dia ){
    
    vector<string> sitio;
    
    for (int i = 0; i <registros.size(); i++){
        if(registros[i].getFecha() == dia){
            
           
            //para saber sitio webd e conexion entrante?
            if (registros[i].getNombreD() != "-" && registros[i].getNombreD() != "server.reto.com") {
                
              //se agregan los validos a un vector
            sitio.push_back(registros[i].getNombreD());
        
            }
        }
        
    }
    
    int tam = sitio.size();
    
    sort(sitio.begin(), sitio.end());
    int cont = 0;
    for(int i = 0; i < tam ; i++){
        //si son iguales, se cuenta
        if (sitio[i] == sitio[i+1]) {
            cont++;
        }else{
            //si son diferentes se agrega el nombre y el numero de veces que apareció y se reincia el contador en cero
            cont = cont + 1;
            pair<string,int> parTemp(sitio[i], cont);
            conexionesXDia.insert(parTemp);
            cont = 0;
            
        }
    }
    
    
    return conexionesXDia;
}//funcion

void ConexionesComputadoras::top(int nTop, string fecha){
    
    map <string, int> conexiones = conexionesPorDia(fecha);
    
    BST<ParConexion> arbolConexiones;
    
    //con for insertar pares de hash tables en el arbol
    
    /*
     for (auto elem : personas) {
            std::cout << "Key: " << elem.first << ", Value: " << elem.second << std::endl;
        }
     */
    for (auto elem : conexiones){
        ParConexion par(elem.first, elem.second);
        arbolConexiones.insert(par);
    }
    
    arbolConexiones.top(nTop);
    
    
    
    
};
    
