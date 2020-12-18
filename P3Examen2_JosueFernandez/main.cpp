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

#include <Relacion.h>
#include <Tupla.h>

//Prototipos

/* Muestra el menú de opciones. */
int menu();
/* Carga las relaciones */
void cargarRelaciones();
/* Guarda las relaciones */
void guardarRelaciones();


vector<Relacion*> relaciones;

int main(int argc, char** argv) {

    cargarRelaciones();

    int opcion = 0;

    do {

        switch (opcion = menu()) {
            case 1:
            {

                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                cout << "Nos vemos!\n";
                break;
            }
        }
        cout << endl;

    } while (opcion != 4);


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