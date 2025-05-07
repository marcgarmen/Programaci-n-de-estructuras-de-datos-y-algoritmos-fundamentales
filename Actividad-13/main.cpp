/** 
** Marco Antonio García Mendoza A01026487
*  Didier Aarón Ricardo Hernández Ferreira A01663817 
Ejemplo que implementa objetos de la clase Registro
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


int main(void) {
  Bitacora bitacora;
  std::string filename;
  filename="bitacora.txt";
  bitacora.leerArchivo(filename);
  //bitacora.bubbleSort();
  bitacora.mergeSort();
  std::string mes_inicio, dia_inicio, hora_inicio, minuto_inicio, segundo_inicio, mes_fin, dia_fin, hora_fin, minuto_fin, segundo_fin;
  
  //std::cout<<"Mes de Inicio(e.g. Jul): ";
  //std::cin>>mes_inicio;
  //std::cout<<"Dia de Inicio(e.g. 01): ";
  //std::cin>>dia_inicio;
  //std::cout<<"Hora de Inicio(e.g. 00): ";
  //std::cin>>hora_inicio;
  //std::cout<<"Minuto de Inicio(e.g. 00): ";
  //std::cin>>minuto_inicio;
  //std::cout<<"Segundo de Inicio(e.g. 00): ";
  //std::cin>>segundo_inicio;
  //std::cout<<"Mes de Fin(e.g. Jul): ";
  //std::cin>>mes_fin;
  //std::cout<<"Dia de Fin(e.g. 01): ";
  //std::cin>>dia_fin;
  //std::cout<<"Hora de Fin(e.g. 00): ";
  //std::cin>>hora_fin;
  //std::cout<<"Minuto de Fin(e.g. 00): ";
  //std::cin>>minuto_fin;
  //std::cout<<"Segundo de Fin(e.g. 00): ";
  //std::cin>>segundo_fin;
  mes_inicio="Jun";
  dia_inicio="01";
  hora_inicio="00";
  minuto_inicio="22";
  segundo_inicio="36";
  mes_fin="Jun";
  dia_fin="01";
  hora_fin="08";
  minuto_fin="23";
  segundo_fin="57";
  Registro fecha_inicio(mes_inicio, dia_inicio, hora_inicio, minuto_inicio, segundo_inicio, "", "", "");
  Registro fecha_fin(mes_fin, dia_fin, hora_fin, minuto_fin, segundo_fin, "", "", "");
  std::cout<<"Fecha 1: "<<fecha_inicio.getAll()<<std::endl;
  std::cout<<"Fecha 2: "<<fecha_fin.getAll()<<std::endl;
  int contador=bitacora.imprimirRegistrosEntreFechas(fecha_inicio, fecha_fin);
  std::cout<<"Resultado: "<<contador<<" Registros"<<std::endl;
  for(int i=0; i<bitacora.listaRegistroFecha.size();i++){
    std::cout<<bitacora.listaRegistroFecha[i].getAll()<<std::endl;
  }
  return 0;
}