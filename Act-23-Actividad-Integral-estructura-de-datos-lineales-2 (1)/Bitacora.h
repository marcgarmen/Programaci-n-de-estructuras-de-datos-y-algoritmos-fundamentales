#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "DLinkedList.h"
#include "Registro.h"
#include "SearchAlgorithm.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <regex>
#include <chrono>
class Bitacora {
  private:
    DLinkedList<Registro> listaRegistros;

  public:
    Bitacora();
    ~Bitacora();
    // TO-DO
    void leerArchivo(std::string filePath);
    void mergeSort();
    void quickSort();
    void buscarEnBitacora(Registro fechaInicio, Registro fechaFin);



};


#endif  // _BITACORA_H_
