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
#include "Bitacora.h"
int main() {
  Bitacora miBitacora;
  std::string ip;
  miBitacora.leerArchivo("bitacoraGrafos.txt");
  miBitacora.hash();
  miBitacora.Colisiones();
  std::cout<<std::endl;
  std::cout<<"Introduce IP: ";
  std::cin>>ip;
  std::cout<<std::endl;
  miBitacora.getIPSummary_Bitacora(ip);
}