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
    
    
    //arbolConexiones.top(nTop);
    int cont = 0;
    arbolConexiones.topN(arbolConexiones.getRoot(), nTop, cont);
    
    
    
    
}

//Funcion para rellenar grafo con conexiones a IP interna (IP base)
Graph<string, int> ConexionesComputadoras::loadGrapConIPs(string fecha){
    
    Graph<string, int> * GrafoXfecha = new Graph<string, int>();
    
    Vertex<string, int> * ipBase1 = new Vertex<string, int>(this->IpBase);
    GrafoXfecha->addVertex(ipBase1);
    
    for (int i = 0; i <registros.size(); i++){
        
        //lo que ocurre es que se voltea la dirección IP de origin y todo lo que está en el útilmo octeto se borra
        string ip_found=registros[i].getIpO();
        reverse(ip_found.begin(), ip_found.end());
        int pos_O = ip_found.find(".");
        string cut_IP_Origen = ip_found.substr(pos_O + 1);
        reverse(cut_IP_Origen.begin(), cut_IP_Origen.end());
        
        string ip_found_Destino =registros[i].getIpD();
        reverse(ip_found_Destino.begin(), ip_found_Destino.end());
        int pos_D = ip_found_Destino.find(".");
        string cut_IP_Destino = ip_found_Destino.substr(pos_D + 1);
        reverse(cut_IP_Destino.begin(), cut_IP_Destino.end());
        
        if(registros[i].getFecha() == fecha){
            
            //no se
            if(cut_IP_Origen == IpBase && cut_IP_Destino != "-"  ){
                
                Vertex<string, int> * IP_Destino = new Vertex<string, int>(cut_IP_Destino);
                GrafoXfecha->addVertex(IP_Destino);
                GrafoXfecha->addEdge(ipBase1, IP_Destino, 1);
            }
            if(cut_IP_Destino == IpBase && cut_IP_Origen != "-"){
                
                Vertex<string, int> * IP_Origen = new Vertex<string, int>(cut_IP_Origen);
                GrafoXfecha->addVertex(IP_Origen);
                GrafoXfecha->addEdge(ipBase1, IP_Origen, 1);
            }
        }
    }
    return *GrafoXfecha;
}

void ConexionesComputadoras::adyacentesIPinterna(string fecha){
    
    //se llama a función para llenar grafos
    Graph<string, int>  GrafoXfecha1 = loadGrapConIPs(fecha);
    
    int cantidadVertex = GrafoXfecha1.nodes.size();
    //buscar nodo de IP Base
    for (int i = 0; i < cantidadVertex; i++) {
        if(GrafoXfecha1.nodes[i]->getInfo() == IpBase){
            
            cout << " \n -----------Para la fecha: " << fecha;
            cout << "\n Cantidad de conexiones de entrada para IP de red interna: " << GrafoXfecha1.nodes[i]->cantidadEntradas;
            cout << "\n Cantidad de conexiones de salidad para IP de red interna: " << GrafoXfecha1.nodes[i]->cantidadSalidas;
            cout << "\n CLAVE DE RED: " << GrafoXfecha1.nodes[i]->getInfo();
        }
        
    }
    
    //delete GrafoXfecha1;
    
}

//Funcion para rellenar grafo con conexiones a sitiosWeb
void ConexionesComputadoras::graphSitiosCount(string fecha, string sitioBuscado){
    
    Graph<string, int> * GrafoSitios = new Graph<string, int>();
    
    Vertex<string, int> * sitioPrincipal = new Vertex<string, int>(sitioBuscado);
    //se creara vertice para el sitio que nos interesa concoer conexiones
    GrafoSitios->addVertex(sitioPrincipal);
    
    for (int i = 0; i <registros.size(); i++){
        
        if(registros[i].getFecha() == fecha && registros[i].getNombreD() == sitioBuscado && (registros[i].getPuertoD() == "80" || registros[i].getPuertoD() =="443" ) ){
               
            Vertex<string, int> * NombreOrigen = new Vertex<string, int>(registros[i].getNombreO());
            GrafoSitios->addVertex(NombreOrigen);
            GrafoSitios->addEdge(NombreOrigen, sitioPrincipal, 1);
        }
    
    }
    
    //contar entradas
    int cantidadVertex = GrafoSitios->nodes.size();
    //buscar nodo de IP Base
    for (int i = 0; i < cantidadVertex; i++) {
        if(GrafoSitios->nodes[i]->getInfo() == sitioBuscado){
            
            cout << " \n -----------Para la fecha: " << fecha;
            cout << " \n para el sitio: " << sitioBuscado;
            cout << "\n Cantidad de conexiones de entrada:  " << GrafoSitios->nodes[i]->cantidadEntradas;
        }
        
    }
    
    delete GrafoSitios;
    
    
}
