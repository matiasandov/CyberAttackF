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
    
   
    
    Administrador sistema(read_csv_USERFILA("/Users/matiasmendez/Downloads/equipo1.csv"));
    
    cout << "1. ¿Cuántos registros tiene tu archivo? \n";
    cout << sistema.contarRegistros() << endl;
    
    cout << "2. ¿Cuántos récords hay del segundo día registrado? \n";
    cout << sistema.contarXdia("11-8-2020") << endl;
    
    //_______
    cout << "3. ¿Alguna de las computadoras pertenece a Jeffrey, Betty, Katherine, Scott, Benjamin, Samuel o Raymond? \n";
    
    cout << " \nBusqueda para Jeffrey  \n";
    sistema.busqNombre("jeffrey");
    
    cout << " \nBusqueda para betty  \n";
    sistema.busqNombre("betty");
    
    cout << " \n Busqueda para Katherine  \n";
    sistema.busqNombre("katherine");
    
    cout << " \n Busqueda para Scott  \n";
    sistema.busqNombre("scott");
    
    cout << " \n Busqueda para Benjamin  \n";
    sistema.busqNombre("benjamin");
    
    cout << " \n Busqueda para Samuel \n";
    sistema.busqNombre("samuel");
    
    cout << " \n Busqueda para Raymond\n";
    sistema.busqNombre("raymond");
    

    //______________
    
    cout << " \n 4. ¿Cuál es la dirección de la red interna de la compañía?";
    sistema.busqRedInterna();
    
    cout << " \n 5. ¿Qué servicio de correo electrónico utilizan (algunas ideas: Gmail, Hotmail, Outlook, Protonmail)?";
    sistema.mostrarMail();
    sistema.busqNombreDestino("protonmail.com");
    
    cout << " \n 6. Considerando solamente los puertos destino ¿Qué puertos abajo del 1000 se están usando? Lista los puertos e investiga qué aplicación/servicio lo utiliza generalmente.";
    sistema.mostrarRangoPuertosD(0, 1000);
    
    cout << " \n 7.  Busqueda para computadora: server.reto.com\n";
    sistema.busqNombre("server");
    
    cout <<  " \n Sin embargo si buscamos por Nombre de destino podemos encontrar para server.reto.com lo siguiente: " << endl;
    sistema.busqNombreDestino("server.reto.com");
    
    
    
    
    
    
    
    
    

    return 0;
}
