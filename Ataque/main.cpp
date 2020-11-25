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
#include "ConexionesComputadora2.hpp"
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
    
   
  
    
    Administrador admin(read_csv_USERFILA("/Users/matiasmendez/Downloads/equipo1.csv"));
    
    vector<UserFila>registros= read_csv_USERFILA("/Users/matiasmendez/Downloads/equipo1.csv");
    
    cout << "------Set de dominios-------";
    admin.setDominios();
    cout << endl << endl;
    
    
    set<string> ips= admin.getDominios();
    
    //para guardar las ips unicas de sitios entrantes
    set<string> ipsUnicasEntrantes;
    
    map<string, ConexionesComputadoras2> mapa_conexiones;
    for (auto i: ips)
    {
        int conexiones_salientes=0;
        int conexiones_entrantes=0;

        for (auto r: registros)
        {
            if (i==r.getNombreO())
            {
                conexiones_salientes++;
            }
            else if(i==r.getNombreD())
            {
                conexiones_entrantes++;
                //para guardar las ips unicas de sitios entrantes
                ipsUnicasEntrantes.insert(r.getIpO());
            }
        }
        pair <string, ConexionesComputadoras2> par=make_pair(i,ConexionesComputadoras2(i,conexiones_entrantes,conexiones_salientes));
        mapa_conexiones.insert(par);
    }

    cout << "--- Map < string, ConexionesComputadoras > ----" << std::endl;
    map<string, ConexionesComputadoras2> ::const_iterator
        mit (mapa_conexiones.begin()),
        mend(mapa_conexiones.end());
    
    for(;mit!=mend;++mit) {
        cout << mit->first << ":" <<mit->second<<endl;
    }
        
    cout << "---------- Ip's únicas entrantes de los nombres destino (Pregunta 4)----" << std::endl;
        set<string>::const_iterator
                sit (ipsUnicasEntrantes.begin()),
                send(ipsUnicasEntrantes.end());
            
            for(;sit!=send; ++sit)
                std::cout << *sit << " \n";
        
    
    return 0;

}
