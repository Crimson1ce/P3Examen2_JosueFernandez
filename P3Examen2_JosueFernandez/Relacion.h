/* 
 * File:   Relacion.h
 * Author: Josue_Fernandez
 */

#ifndef RELACION_H
#define RELACION_H

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Tupla.h"

class Relacion {
public:
    /* Constructor por defecto */
    Relacion();
    
    /* Constructor, recibe el nombre de la relacion */
    Relacion(string nombre);
    
    /* Destructor */
    virtual ~Relacion();
    
    void setNombre(string nombre);
    
    /* Guarda la relacion en un archivo con su respectivo nombre e información. 
     */
    bool guardarRelacion();
    
    /* Carga la relacion de un archivo con su nombre
     */
    bool cargarRelacion(string nombre);
    
    /* Libera todas las tuplas */
    void liberarTuplas();
    
private:
    string nombre;
    vector<string> encabezados;
    vector<Tupla*> tuplas;
    int numTuplas;
    int numCampos;
    
};

#endif /* RELACION_H */

