/* 
 * File:   Tupla.cpp
 * Author: Josue_Fernandez
 */

#include "Tupla.h"

using std::to_string;

Tupla::Tupla() {
}

Tupla::~Tupla() {
    valores.clear();
}

string Tupla::toString() {
    string tuple = "";
    tuple += to_string(ID) + ',';
    for (int i = 0; i < numValores; i++) {
        tuple += valores.at(i) + ',';
    }
    return tuple;
}
