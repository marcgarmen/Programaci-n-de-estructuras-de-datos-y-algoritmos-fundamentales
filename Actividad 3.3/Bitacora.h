// Bitacora.h
#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Registro.h"
#include "AlgorithmSort.h"
#include "MaxHeap.h"
#include "IPInfo.h"

class Bitacora {
private:
    std::vector<Registro> listaRegistros;
    MaxHeap<IPInfo> maxHeap;

public:
    Bitacora();
    ~Bitacora();
    void leerArchivo(std::string filePath);
    void heapSort();
    void max_heap();
    
};

#endif // _BITACORA_H_
