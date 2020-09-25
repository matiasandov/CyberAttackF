//
//  Administrador.cpp
//  Ataque
//
//  Created by Matías Méndez on 22/09/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#include "Administrador.hpp"
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>



auto Administrador::read_fila(){
    /* Crear un vector de vector de strings */
    vector<UserFila> lineas;

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
        
        
        /* Insertar la fila con los campos separados en un vector */
        lineas.push_back(UserFila( f, h, iO, pO, nO, iD, pD, nD));
    }

    /* Cerrar el archivo */
    file.close();

    /* Regresar el vector de líneas leídas */
    return lineas;
}

/* Lectura de los datos como un objeto Persona
vector<UserFila> personas = read_csv_persona("/Users/matiasmendez/Downloads/equipo1.csv"); */

int Administrador::contarRegistros(){
    //atributo de clase
    
    return size;
}

//contar por fecha
int Administrador::contarXdia(string dia ){
    
   //int tam = (int) registros.size()-1;
    
    //registros = Ordenamiento<UserFila>::quicksort(registros,0, tam, UserFila::fecha_asc);
    
    //usamos ordenamiento por sleccion porque fue más rápido ne esta coasion que quicksort y mergesort
    registros = Ordenamiento<UserFila>::seleccion(registros, UserFila::fecha_asc);
    
    int cont = 0;
    
    for (int i = 0; i <size; i++){
        if(registros[i].getFecha() == dia){
            cont = cont +1;
        }
    }
    
    return cont;
}

//busquedas por nombre de origen
void Administrador::busqNombre(string nombre){
    int cont = 0;
    
    for (int i = 0; i < size; i++){
        if(registros[i].getNombreO() == nombre+".reto.com" ){
            //cout << registros[i];
            cont = cont +1;
        }
    }
    cout << " Valores encontrados : " << cont << " para : "<<  nombre << endl;
}

void Administrador::busqNombreDestino(string nombre){
    
    int cont = 0;
    
    for (int i = 0; i < size; i++){
        if(registros[i].getNombreD() == nombre ){
            //cout << registros[i];
            cont = cont +1;
        }
    }
    cout << " Valores encontrados : " << cont << " para : "<<  nombre << endl;
    
}

void Administrador::busqRedInterna(){

    

   
    int i=0;
    //int size= registros.size();

      while (i<size)
      {
      string ip_found=registros[i].getIpO();
      reverse(ip_found.begin(), ip_found.end());
      int pos = ip_found.find(".");
      string cut = ip_found.substr(pos + 1);
      reverse(cut.begin(), cut.end());
      cout<< cut<<endl;
      i++;
      }
    
    
}
//Nombre de destiono = mail
void Administrador::mostrarMail(){
    
    for (int i = 0; i < size; i++){
            cout << registros[i].getNombreD() << endl;
    }
    
}

void Administrador::mostrarRangoPuertosD(int inf, int sup){
    
    
    int puertoDesINT;
    int cont = 0;
    
    for (int i = 0; i < size; i++){
        puertoDesINT =  atoi( registros[i].getPuertoD().c_str() ) ;
        if( inf < puertoDesINT && puertoDesINT < sup ){
            //cout << registros[i];
            cont = cont + 1;
        }
    }
    cout << " Valores encontrados : " << cont << endl;

}
