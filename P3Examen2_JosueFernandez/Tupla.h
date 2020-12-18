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
    Tupla(int ID);
    virtual ~Tupla();
    
    /* Devuelve los elementos separados por comas */
    string toString();
    
    /* Retorna el ID */
    int getID();
    
    /* Retorna los valores */
    vector<string> getValores();
    
    /* Retorna el numero de valores */
    int getNumValores();
    
    /* Setter del numero de valores */
    void setNumValores(int numero);
    
    void agregarValor(string valor);
    
    string getValor(int i);
    
private:
    
    int ID;
    vector<string> valores;
    int numValores;

    friend class Relacion;
    
};

#endif /* TUPLA_H */

