/* 
 * File:   Tupla.h
 * Author: Josue_Fernandez
 */

#ifndef TUPLA_H
#define TUPLA_H

#include <string>
using std::string;

#include <vector>
using std::vector;

class Relacion;

class Tupla {
public:
    Tupla();
    virtual ~Tupla();
    
    string toString();
    
private:
    
    int ID;
    vector<string> valores;
    int numValores;

    friend class Relacion;
    
};

#endif /* TUPLA_H */

