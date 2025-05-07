
/** 
* Ejemplo que implementa objetos de la clase Registro
* que contienen una fecha-hora convertida a Linux timestamp
* para realizar comparaciones (sobrecarga de operadores)
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind
*    nix-env -iA nixpkgs.valgrind
*    valgrind --leak-check=full ./main
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main
*
*  Didier Aarón Ricardo Hernández Ferreira A01663817
*  Marco Antonio García Mendoza A01026487
**/

#include <iostream>
#include "Bitacora.h"

int main() {
  Bitacora miBitacora;
  miBitacora.leerArchivo("bitacoraHeap.txt");
  miBitacora.heapSort();
  miBitacora.max_heap();
  return 0;
}
