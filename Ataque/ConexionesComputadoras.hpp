//
//  ConexionesComputadoras.hpp
//  Ataque
//
//  Created by Matías Méndez on 11/10/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#ifndef ConexionesComputadoras_hpp
#define ConexionesComputadoras_hpp

#include <stdio.h>
#include <iostream>
#include <map>
#include "Administrador.hpp"
#include "/Users/matiasmendez/Desktop/PF/ArbolBinario/ArbolBinario/BST.hpp"
#include "/Users/matiasmendez/Desktop/PF/Listas_Enlazadas/Listas_Enlazadas/LinkedList.hpp"
#include "/Users/matiasmendez/Desktop/PF/Listas_Enlazadas/Stack/Stack/Stack.hpp"
#include "/Users/matiasmendez/Desktop/PF/Listas_Enlazadas/Queue/Queue/Queue.hpp"

#include "ParConexion.hpp"

#include "/Users/matiasmendez/Desktop/PF/Graphs/Graphs/Graph.hpp"


//no se si conexiones sea una herencia de la clase adminsitrador y con el mismo constructor o si deba ser otra dfierente 
class ConexionesComputadoras  {
private:
    vector<UserFila> registros;
    string fileName;
    
    //IP destino = IpBase
    Stack<UserFila> entrantes;
    //Ip origen = IpBase
    vector<UserFila> salientes;
    //1. Ip interna que se esta usando
    string IpBase = "10.152.206";
    string Ip;
    
    map <string, int> conexionesXDia;
    
   
    
    
public:
   
    ~ConexionesComputadoras();
    ConexionesComputadoras(vector<UserFila>, string);
    string getIpInternaNueva();
    void setIp(string);
    string getIp(){return this->Ip;}

    void comp_entrantes();
    
    
    void generarIpInterna(string);
    void ultimaConexion();
    
    void countEntrantes();
    void countSalientes();
    
    //5
    void conexionesSeguidas();
    
    map <string, int> conexionesPorDia(string);
    
    void top(int n, string fecha);
    
    //cargar en grafo conexiones de IP Interna(Ip base)
    Graph<string, int> * loadGrapConIPs(string fecha);
    
    //método para contar incidentes de entrada y de salida
    void adyacentesIPinterna(string fecha);
    
    //que creara grafo para sitiweb indicado y cuente entre sitios webs
    void graphSitiosCount(string fecha, string sitioBuscado);
    
};




#endif /* ConexionesComputadoras_hpp */
