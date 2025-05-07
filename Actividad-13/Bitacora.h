#ifndef _BITACORA_H_
#define _BITACORA_H_

#include "AlgorithmSort.h"
#include "Registro.h"
#include "SearchAlgorithm.h"
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
class Bitacora {
private:
  std::vector<Registro> listaRegistros;

public:
  Bitacora();
  ~Bitacora();
  // TO-DO
  void leerArchivo(std::string filePath);
  // ordenamiento
  void bubbleSort();
  void mergeSort();
  // busqueda
  int busquedaBinaria(Registro dato);
  // print
  int imprimirRegistrosEntreFechas(Registro fecha_inicio,Registro fecha_fin);
  std::vector<Registro> listaRegistroFecha;
};

#endif // _BITACORA_H_
