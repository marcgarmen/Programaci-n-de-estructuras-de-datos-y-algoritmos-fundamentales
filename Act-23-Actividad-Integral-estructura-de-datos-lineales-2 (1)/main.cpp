/** 
* Ejemplo que implementa objetos de la clase Registro
* que contienen una fecha-hora convertida a Linux timestamp
* para realizar comparaciones (sobrecarga de operadores)
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    nix-env -iA nixpkgs.valgrind
*    valgrind --leak-check=full ./main
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main
**/

#include <iostream>
#include "Bitacora.h"


int main() {
  Bitacora miBitacora;
  Bitacora miBitacora_Copia;
  miBitacora.leerArchivo("bitacora.txt");
  miBitacora_Copia = miBitacora;
  
          miBitacora.leerArchivo("bitacora.txt");
          miBitacora.mergeSort(); 
          miBitacora_Copia.quickSort();
          std::string mes_inicio, dia_inicio, hora_inicio, minuto_inicio, segundo_inicio, mes_fin, dia_fin, hora_fin, minuto_fin, segundo_fin;
          std::cout<<"Mes de Inicio(e.g. Jul): ";
          std::cin>>mes_inicio;
          std::cout<<"Dia de Inicio(e.g. 01): ";
          std::cin>>dia_inicio;
          std::cout<<"Hora de Inicio(e.g. 00): ";
          std::cin>>hora_inicio;
          std::cout<<"Minuto de Inicio(e.g. 00): ";
          std::cin>>minuto_inicio;
          std::cout<<"Segundo de Inicio(e.g. 00): ";
          std::cin>>segundo_inicio;
          std::cout<<"Mes de Fin(e.g. Jul): ";
          std::cin>>mes_fin;
          std::cout<<"Dia de Fin(e.g. 01): ";
          std::cin>>dia_fin;
          std::cout<<"Hora de Fin(e.g. 00): ";
          std::cin>>hora_fin;
          std::cout<<"Minuto de Fin(e.g. 00): ";
          std::cin>>minuto_fin;
          std::cout<<"Segundo de Fin(e.g. 00): ";
          std::cin>>segundo_fin;
          Registro fecha_inicio(mes_inicio, dia_inicio, hora_inicio, minuto_inicio, segundo_inicio, "", "", "");
          Registro fecha_fin(mes_fin, dia_fin, hora_fin, minuto_fin, segundo_fin, "", "", "");
          
          // Realizar la búsqueda en la bitácora
          miBitacora.buscarEnBitacora(fecha_inicio, fecha_fin);

      return 0;
}
