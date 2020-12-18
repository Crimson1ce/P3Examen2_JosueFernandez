/* 
 * File:   Relacion.cpp
 * Author: Josue_Fernandez
 */

#include "Relacion.h"

#include <iomanip>
using std::setw;

#include <sstream>
using std::istringstream;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <ios>
using std::ios;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

using std::stoi;

Relacion::Relacion(string nombre) {
    this->nombre = nombre;
    this->numTuplas = 0;
    this->numCampos = 0;
}

Relacion::Relacion(string nombre, string campos) {
    this->nombre = nombre;
    this->numTuplas = 0;
    this->numCampos = 0;

    int i=0;
    string token;
    istringstream stream(campos);
    while (getline(stream, token, ',')) {
        if (token == "") continue;
        encabezados.push_back(token);
        this->numCampos++;
//        cout << i++ << "\n";
    }
}

Relacion::~Relacion() {
    liberarTuplas();
}

bool Relacion::guardarRelacion() {
    if (this->nombre == "") {
        return false;
    }

    ofstream archivo;
    archivo.open("Relaciones\\" + nombre + ".txt", ios::out | ios::trunc);

    if (archivo.is_open()) {

        //Guardamos el numero de campos
        archivo << this->numCampos << '\n';

        //Guardamos el numero de tuplas
        archivo << this->numTuplas << '\n';

        //Guardamos los encabezadoss
        for (int i = 0; i < numCampos; i++) {
            archivo << encabezados.at(i) << ',';
        }
        archivo << '\n';

        for (int i = 0; i < numTuplas; i++) {
            archivo << ((Tupla*) tuplas.at(i))->ID << '\n';
            archivo << ((Tupla*) tuplas.at(i))->toString() << '\n';
        }

        archivo.close();
        return true;
    } else {
        archivo.close();
        return false;
    }
}

bool Relacion::cargarRelacion() {
    if (this->nombre == "") {
        return false;
    }

    ifstream archivo;
    archivo.open("Relaciones\\" + nombre + ".txt", ios::in);

    if (archivo.is_open()) {

        int filas, columnas;

        //Conseguimos las filas y las columnas
        archivo >> columnas;
        archivo >> filas;

        //Liberamos las tuplas actuales
        liberarTuplas();

        //Y los encabezados también
        encabezados.clear();

        string header;

        //Creamos un stringstream para separar los headers
        string line;
        archivo >> line;
        istringstream isstream(line);

        this->numCampos = columnas;
        while (getline(isstream, header, ',')) {
            encabezados.push_back(header);
        }

        for (int i = 0; i < filas; i++) {

            string linea;
            archivo >> linea;

            Tupla* tuple = new Tupla(stoi(linea));

            archivo >> linea;
            istringstream ss(linea);

            string token;

            //Cargamos cada nueva tupla
            while (getline(ss, token, ',')) {
                tuple->valores.push_back(token);
            }
            tuple->numValores = columnas;

            tuplas.push_back(tuple);

        }
        this->numTuplas = filas;

        archivo.close();
        return true;
    } else {
        archivo.close();
        return false;
    }
}

void Relacion::setNombre(string nombre) {
    this->nombre = nombre;
}

void Relacion::liberarTuplas() {
    for (int i = 0; i < numTuplas; i++) {
        delete ((Tupla*) tuplas.at(i));
    }
    tuplas.clear();
    numTuplas = 0;
}

string Relacion::getNombre() {
    return this->nombre;
}

bool Relacion::insertarTupla(Tupla* tupla) {
    if (tupla == NULL) {
        return false;
    }
    this->tuplas.push_back(tupla);
    this->numTuplas++;
    return true;
}

void Relacion::imprimmirRelacion() {
    cout << setw(13) << "ID_Number";
    for (int i = 0; i < numCampos; i++) {
        cout << setw(15) << this->encabezados.at(i);
    }
    cout << endl << endl;
    
    
    for (int i = 0; i < tuplas.size(); i++) {
        cout << setw(13) << ((Tupla*) tuplas.at(i))->ID;
        for (int j = 0; j < ((Tupla*)tuplas.at(0))->valores.size(); j++) {
            cout << setw(15) << ((Tupla*) tuplas.at(i))->valores.at(j);
        }
        cout << endl;
    }
    cout << endl;
}

int Relacion::getNumCampos() {
    return this->numCampos;
}

int Relacion::getNumTuplas() {
    return this->numTuplas;
}

vector<Tupla*> Relacion::getTuplas() {
    return this->tuplas;
}

vector<string> Relacion::getEncabezados() {
    return this->encabezados;
}
