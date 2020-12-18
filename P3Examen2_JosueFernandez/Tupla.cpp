/* 
 * File:   Tupla.cpp
 * Author: Josue_Fernandez
 */

#include "Tupla.h"

using std::to_string;

#include <string>
using std::string;

#include <vector>
using std::vector;

Tupla::Tupla(int ID) : ID(ID) {
    numValores = 0;
}

Tupla::~Tupla() {
    valores.clear();
}

string Tupla::toString() {
    string tuple = "";
    for (int i = 0; i < valores.size(); i++) {
        tuple += valores.at(i) + ',';
    }
    return tuple;
}

int Tupla::getID() {
    return this->ID;
}

int Tupla::getNumValores() {
    return this->numValores;
}

vector<string> Tupla::getValores() {
    return this->valores;
}

void Tupla::setNumValores(int numero) {
    this->numValores = numero;
}

void Tupla::agregarValor(string valor) {
    valores.push_back(valor);
    numValores++;
}

string Tupla::getValor(int i) {
    return valores.at(i);
}
