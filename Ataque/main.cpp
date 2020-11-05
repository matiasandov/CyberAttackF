//
//  main.cpp
//  Ataque
//
//  Created by Matías Méndez on 22/09/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "UserFila.hpp"
#include "Administrador.hpp"
#include "ConexionesComputadoras.hpp"
using namespace std;

auto read_csv_strings(string filename)
{
    /* Crear un vector (matriz) de vector de strings(vectores internos o sea filas) donde se guardara cada linea del documento*/
    vector< vector<string> > lineas;

    /* Crear un input filestream para leer el archivo CSV, o sea objeti que recibe un input */
    ifstream file(filename);

    /* Lanzar excepción: Verificar si no hubo error al abrir el archivo */
    if(!file.is_open()) throw runtime_error("No se puede abrir el archivo");

    /* Definir variable que almacena cada línea del archivo */
    string linea;
    
    /* Leer datos línea a línea, fila a fila, ESTO SE REALIZA PARA CADA LINEA */
    while(getline(file, linea))
    {
        /* Crear un stream de la línea */
        stringstream ss(linea);
    
        /* Variable que almacena cada campo leído, o sea cada columna creo */
        string campo;
        
        /* Cada elemento de la columna se agrega a un vector, es decir cada fila se vuelve a un vector. Almacenar cada campo */
        vector<string> fila;
        
        /* Iterar sobre la línea para extraer cada campo */
        while(std::getline(ss, campo, ','))
        {
            //se agrega cada elemento al vector de cada fila
            fila.push_back(campo);
        }
        
        /* Insertar la fila con los campos separados en un vector */
        lineas.push_back(fila);
    }

    /* Cerrar el archivo */
    file.close();

    /* Regresar el vector de líneas leídas */
    return lineas;
}
                
auto read_csv_USERFILA(string filename)
{
    /* Crear un vector de vector de strings */
    vector<UserFila> lineas;

    /* Crear un input filestream para leer el archivo CSV */
    ifstream file(filename);

    /* Verificar si no hubo error al abrir el archivo */
    if(!file.is_open()) throw std::runtime_error("No se puede abrir el archivo");

    /* Definir variable que almacena cada línea */
    std::string linea;
    
    /* Leer datos línea a línea */
    while(std::getline(file, linea))
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

int main(int argc, const char * argv[])
{
    
   
  
    

    
    ConexionesComputadoras sistema(read_csv_USERFILA("/Users/matiasmendez/Downloads/equipo1.csv"),"55");


   /* cout<<"Ip Utilizada: ";
    cout<<sistema.getIp()<<endl;

    cout<<"\n Ultima conexion de la computadora: ";
    sistema.ultimaConexion();

    cout<<"\n Cantidad de conexiones entrantes: ";
    sistema.countEntrantes();
    cout<<"\n Cantidad de conexiones salientes: ";
    sistema.countSalientes();

    cout<<"\n Conexiones seguidas ";
    sistema.conexionesSeguidas();*/
    
    //sistema.conexionesPorDia("10-8-2020");
    sistema.top(5, "10-8-2020");

  
    
    
    
    
    
    
    
    
    

    return 0;
                                   }
