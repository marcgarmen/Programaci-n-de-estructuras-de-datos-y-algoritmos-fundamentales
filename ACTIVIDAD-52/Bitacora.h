#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Registro.h"
#include "Graph.h"


class Bitacora {
  private:
    //std::vector<Registro> listaRegistros;
    Graph<std::string> grafo;


  public:
    Bitacora();
    ~Bitacora();
    void leerArchivo(std::string filePath);
    void gradosIP();
    void maxHeap();
    void bootMaster_bitacora();
    void shortestPath();
    void longestPath();
    void hash();
    void Colisiones();
    void getIPSummary_Bitacora(std::string ip);

};


#endif  // _BITACORA_H_
