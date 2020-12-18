/* 
 * File:   main.cpp
 * Author: Josue_Fernandez
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <ios>
using std::ios;

#include <cstdlib>
#include <ctime>

#include "Relacion.h"
#include "Tupla.h"

//Prototipos

/* Muestra el menú de opciones. */
int menu();
/* Carga las relaciones */
void cargarRelaciones();
/* Guarda las relaciones */
void guardarRelaciones();
/* Crea una relacion */
void crearRelacion();
/* Libera las relaciones */
void liberarRelaciones();
/* Crea una tupla para una relacion dada */
void crearTupla(Relacion* relacion);


vector<Relacion*> relaciones;

int main(int argc, char** argv) {

    cargarRelaciones();

    int opcion = 0;

    do {

        switch (opcion = menu()) {
            case 1: //Crear relacion
            {
                crearRelacion();
                break;
            }
            case 2: //Ver relaciones
            {

                if (relaciones.size() == 0) {
                    cout << "No hay relaciones existentes\n";
                    break;
                }

                cout << "Estas son las relaciones disponibles:\n\n";

                for (int i = 0; i < relaciones.size(); i++) {
                    cout << (i + 1) << ". " << ((Relacion*) relaciones.at(i))->getNombre() << endl;
                }
                cout << endl;

                int indice;
                cout << "Ingrese el numero de la relacion que quiere visualizar: ";
                cin >> indice;

                while (indice < 1 || indice > relaciones.size()) {
                    cout << "Ingrese una relacion valida: ";
                    cin >> indice;
                }
                cout << endl;

                --indice;

                ((Relacion*) relaciones.at(indice))->imprimmirRelacion();

                break;
            }
            case 3: //Insertar tupla
            {
                if (relaciones.size() == 0) {
                    cout << "No hay relaciones existentes\n";
                    break;
                }
                
                cout << "Estas son las relaciones disponibles:\n\n";

                for (int i = 0; i < relaciones.size(); i++) {
                    cout << (i + 1) << ". " << ((Relacion*) relaciones.at(i))->getNombre() << endl;
                }
                cout << endl;

                int indice;
                cout << "Ingrese el numero de la relacion a la que quiere insertar una tupla: ";
                cin >> indice;

                while (indice < 1 || indice > relaciones.size()) {
                    cout << "Ingrese una relacion valida: ";
                    cin >> indice;
                }
                cout << endl;

                --indice;

                Relacion* relacion = ((Relacion*) relaciones.at(indice));
                crearTupla(relacion);
                
                break;
            }
            case 4: //Salir
            {
                cout << "Nos vemos!\n";
                break;
            }
        }
        cout << endl;

    } while (opcion != 4);

    liberarRelaciones();
    return 0;
}

int menu() {
    int opcion = 0;

    cout << "\tSISTEMA DE MANEJO DE BASES DE DATOS RELACIONALES\n"
            << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "1. Crear relacion\n"
            << "2. Ver relaciones\n"
            << "3. Insertar tupla\n"
            << "4. Salir\n\n";
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    while (opcion < 1 || opcion > 4) {
        cout << "Ingrese una opcion valida: ";
        cin >> opcion;
    }

    return opcion;
}

void cargarRelaciones() {
    ifstream archivo;
    archivo.open("Relaciones.txt");
    if (archivo.is_open()) {
        string name;
        while (archivo >> name) {
            Relacion* relationship = new Relacion(name);
            if (relationship->cargarRelacion()) {
                relaciones.push_back(relationship);
            }
        }
    }
    archivo.close();
}

void guardarRelaciones() {
    ofstream archivo;
    archivo.open("Relaciones.txt", ios::out | ios::trunc);
    if (archivo.is_open()) {
        for (int i = 0; i < relaciones.size(); i++) {
            if (((Relacion*) relaciones.at(i))->guardarRelacion()) {
                archivo << ((Relacion*) relaciones.at(i))->getNombre() << '\n';
            }
        }
    }
    archivo.close();
}

void crearRelacion() {
    string nombre;
    cout << "Ingrese el nombre de la nueva relacion: ";
    cin >> nombre;

    for (int i = 0; i < relaciones.size(); i++) {
        if (((Relacion*) relaciones.at(i))->getNombre() == nombre) {
            cout << "La relacion ya existe\n";
            return;
        }
    }

    string headers;
    cout << "Ingrese los encabezados de su relacion, separados por comas y sin espacios:\n\n";
    cin >> headers;

    Relacion* relationship = new Relacion(nombre, headers);
    relaciones.push_back(relationship);
    guardarRelaciones();
    return;
}

void liberarRelaciones() {
    for (int i = 0; i < relaciones.size(); i++) {
        delete (((Relacion*) relaciones.at(i)));
    }
    relaciones.clear();
}

void crearTupla(Relacion* relacion){
    srand(time(0));
    int elementos = relacion->getNumCampos();
    bool flag;
    int id;
    do {
        flag = false;
        id = 1000 + (rand()%9000);
        for (int i = 0; i < relacion->getNumTuplas(); i++) {
            if(id == ((Tupla*)relacion->getTuplas().at(i))->getID()){
                flag = true;
                break;
            }
        }
    } while (flag);

    Tupla* tuple = new Tupla(id);
    
    cout << endl;
    for (int i = 0; i < relacion->getNumCampos(); i++) {
        string campo;
        cout << "Ingrese el valor de [" << relacion->getEncabezados().at(i) << "]: ";
        cin >> campo;
        tuple->agregarValor(campo);
        tuple->setNumValores(tuple->getNumValores()+1);
    }
    
    if( relacion->insertarTupla(tuple) ) {
        cout << "\nLa tupla fue insertada exitosamente!\n";
        relacion->guardarRelacion();
    } else {
        cout << "\nError al insertar tupla.\n";
        delete tuple;
    }
    
}