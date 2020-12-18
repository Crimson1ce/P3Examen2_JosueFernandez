/* 
 * File:   main.cpp
 * Author: Josue_Fernandez
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//Prototipos

/* Muestra el menú de opciones. */
int menu();

int main(int argc, char** argv) {

    int opcion = 0;
    
    do {
        
        switch (opcion = menu()) {
            case 1: {
                
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
        }
        
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