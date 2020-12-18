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
    /* Constructor, recibe el nombre de la relacion */
    Relacion(string nombre);
    
    /* Constructor, recibe el nombre de la relacion y los encabezados*/
    Relacion(string nombre, string campos);
    
    /* Destructor */
    virtual ~Relacion();
    
    /* Setter del nombre */
    void setNombre(string nombre);
    
    /* Getter del nombre */
    string getNombre();
    
    /* Getter del numero de campos */
    int getNumCampos();
    
    /* Getter del numero de tuplas */
    int getNumTuplas();
    
    /* Getter de las tuplas */
    vector<Tupla*> getTuplas();
    
    /* Getter de los encabezados */
    vector<string> getEncabezados();
    
    /* Guarda la relacion en un archivo con su respectivo nombre e información. 
     */
    bool guardarRelacion();
    
    /* Carga la relacion de un archivo con su nombre
     */
    bool cargarRelacion();
    
    /* Libera todas las tuplas */
    void liberarTuplas();
    
    /* Metodo que recibe una tupla y la valida para agregarla a la relación. */
    bool insertarTupla(Tupla* tupla);
    
    /* Imprime la relacion en forma de tabla */
    void imprimmirRelacion();
    
private:
    string nombre;
    vector<string> encabezados;
    vector<Tupla*> tuplas;
    int numTuplas;
    int numCampos;
    
};

#endif /* RELACION_H */

