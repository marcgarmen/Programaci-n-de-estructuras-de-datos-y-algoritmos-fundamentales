#include "Bitacora.h"



Bitacora::Bitacora() {
  listaRegistros.clear();
}

Bitacora::~Bitacora() {
  listaRegistros.clear();
}
      
// https://cplusplus.com/reference/fstream/ifstream/
//Complejidad: O(n)
void Bitacora::leerArchivo(std::string filePath) {
  std::string month, day, hours, minutes, seconds, ipAdd, port, error;
  int dia, puerto;
  std::ifstream file(filePath);
  if (!file.good()) {
    file.close();
    throw std::invalid_argument("File not found");
  }
  else {
    while (!file.eof()) {
      std::getline(file, month, ' ');
      if (month.length() > 0) {
        std::getline(file, day, ' ');
        std::getline(file, hours, ':');
        std::getline(file, minutes, ':');
        std::getline(file, seconds, ' ');
        std::getline(file, ipAdd, ':');
        std::getline(file, port, ' ');
        std::getline(file, error);
        // crear un objeto de la clase Registro
        Registro tmpRec(month, day, hours, minutes, seconds, ipAdd, port, error);
        listaRegistros.push_back(tmpRec); 
      }
    }
    file.close();
  } 
}
//Complejidad: O(n log n)
void Bitacora::heapSort(){
  AlgorithmSort<Registro> sortObj;
  unsigned int comparaciones, swaps;
  comparaciones=swaps=0;
  sortObj.heapSort(listaRegistros, listaRegistros.size(), comparaciones, swaps);
  std::ofstream archivoHeap("bitacora_ordenada.txt");
  if (!archivoHeap.is_open()) {
      throw std::runtime_error("No se pudo abrir el archivo para escribir la bitácora ordenada.");
  }
  archivoHeap << "Bitacora Ordenada con Heap Sort por IP:"<< std::endl;
  archivoHeap << std::endl;
  for (int i = 0; i < listaRegistros.size(); ++i) {
      Registro registro = listaRegistros[i];
      archivoHeap << registro.getAll() << std::endl;
  }

  archivoHeap.close();
  
}
//Complejidad: O(n log n)
void Bitacora::max_heap() {
std::vector<IPInfo> ipList;
    int repetidos = 1;
    for (int i = 0; i < listaRegistros.size() - 1; i++) {
        if (listaRegistros[i].getIP_decimal() == listaRegistros[i + 1].getIP_decimal()) {
            repetidos++;
        } else {
            IPInfo ipInfo(listaRegistros[i].getIP(), repetidos);
            ipList.push_back(ipInfo);
            repetidos = 1; 
        }
    }

    
    IPInfo lastIPInfo(listaRegistros.back().getIP(), repetidos);
    ipList.push_back(lastIPInfo);

    
    MaxHeap<IPInfo> maxHeap(ipList.size());
    for (const auto& ipInfo : ipList) {
        maxHeap.push(ipInfo);
    }

    
    std::ofstream archivoHeap("ips_con_mayor_acceso.txt");
    if (!archivoHeap.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo para escribir la bitácora");
    }
    archivoHeap << "5 IPs Con Mayor Acceso" << std::endl;
    archivoHeap << std::endl;
    for (int i = 0; i < 5 && !maxHeap.isEmpty(); i++) {
        archivoHeap <<"IP: "<<maxHeap.getTop().getIP() << " con "<<maxHeap.getTop().getIngresos()<<" ingresos."<<std::endl;
        maxHeap.pop();
    }

    archivoHeap.close();
}



