#include "Bitacora.h"



Bitacora::Bitacora() {

}

Bitacora::~Bitacora() {

}

// https://cplusplus.com/reference/fstream/ifstream/
void Bitacora::leerArchivo(std::string filePath) {
  std::filebuf fb;
  if (fb.open(filePath, std::ios::in)) {
    std::istream is(&fb);
    grafo.loadDirWeightedGraph(is);
    fb.close();
  }
  else {
    throw std::invalid_argument("File not found");
  }
}

void Bitacora::gradosIP(){
  grafo.saveToFile();
}

void Bitacora::maxHeap(){
  grafo.maxHeap();
}

void Bitacora::bootMaster_bitacora(){
  int indice=grafo.bootMaster();
  std::cout<<"El boot master es: "<<grafo.ipOnIndex(indice)<<std::endl;
}
void Bitacora::shortestPath(){
  int indice=grafo.bootMaster();
  std::vector<int>distance=grafo.shortestPath(indice).first;
std::vector<int> previous=grafo.shortestPath(indice).second;
std::ofstream file("distancia_bootmaster.txt");
  if(!file.is_open()){
    std::cout<<"No se pudo abrir el archico"<<std::endl;
  }
  for(int i=0;i<distance.size();i++){
    file<<"IP: "<<grafo.ipOnIndex(i)<<" Distancia: "<<distance[i]<<std::endl;
  }
  file.close();
}

void Bitacora::longestPath(){
    int indice=grafo.bootMaster();
    std::vector<int>distance=grafo.shortestPath(indice).first;
    std::vector<int> previous=grafo.shortestPath(indice).second;
  int indice_maximo=0;
  int medidor;
  for(int i=0; i<distance.size(); i++){
    if(distance[i]>=indice_maximo){
      indice_maximo=distance[i];
      medidor=i;
    }
  }
  std::cout<<"IP mas lejos: "<<grafo.ipOnIndex(medidor)<<" Distancia: "<<distance[medidor];
}

