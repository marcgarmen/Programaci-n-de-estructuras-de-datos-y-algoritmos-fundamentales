/** 
* Ejemplo que implementa dos representaciones de Grafos
* (Matriz de adyacencia y Lista de adyacencia) y el recorrido BFS
* Marco Antonio García Mendoza A01026487
* Didier Aarón Ricardo Hernández Ferreira A01663817
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    nix-env -iA nixpkgs.valgrind
*    valgrind --leak-check=full ./main < TestCases/graph01.txt
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main < TestCases/graph01.txt
**/

#include <iostream>
#include <sstream>
#include "Bitacora.h"

int main() {
  Bitacora myBitacora;
  myBitacora.leerArchivo("bitacoraGrafos.txt");
  myBitacora.gradosIP();
  myBitacora.maxHeap();
  myBitacora.bootMaster_bitacora();
  myBitacora.shortestPath();
  myBitacora.longestPath();
  return 0;
}