#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <fstream>
#include "LinkedList.h"
#include "QueueLinkedList.h"
#include "ipAddress.h"
#include "MaxHeap.h"
#include "IPInfo.h"
#include "HashTable.h"

// https://stackoverflow.com/questions/18429021/why-is-infinity-0x3f3f3f3f
#define INF 0x3f3f3f3f

template <class T> class Graph {
private:
  int numNodes;
  int numEdges;
  // Cada nodo tiene un id y un objeto de datos tipo T
  std::map<int, T> nodesInfo;
  // Cada nodo esta almacenado como un objeto ipAddress
  std::vector<ipAddress> ipInfo;
  // Lista de adyacencia (vector de listas de pares <nodo,peso>)
  std::vector<LinkedList<std::pair<int, int>>> adjList;

  void split(std::string line, std::vector<int> &res);
  int binarySearch(ipAddress key);
  HashTable<unsigned int, ipAddress> hashTable;

public:
  Graph();
  ~Graph();
  void loadDirWeightedGraph(std::istream &input);
  void print(int flagInfo = 0);
  void saveToFile();
  std::pair<std::vector<int>, std::vector<int>> shortestPath(int v);
  void maxHeap();
  int bootMaster();
  std::string ipOnIndex(int i);
  void hash();
  unsigned int colisiones();
  void getIPSummary(std::string ip);
};

template <class T> Graph<T>::Graph() {
  numNodes = 0;
  numEdges = 0;
}

template <class T> Graph<T>::~Graph() {
  adjList.clear();
  numNodes = 0;
  numEdges = 0;
}

template <class T>
void Graph<T>::split(std::string line, std::vector<int> &res) {
  size_t strPos = line.find(" ");
  size_t lastPos = 0;
  while (strPos != std::string::npos) {
    res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
    lastPos = strPos + 1;
    strPos = line.find(" ", lastPos);
  }
  res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

//Complejidad: O(log n)
template <class T>
int Graph<T>::binarySearch(ipAddress key) {
  int low = 0;
  int high = ipInfo.size() - 1;
  int mid = 0;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (key == ipInfo[mid])
      return mid;
    else if (key < ipInfo[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

template <class T> std::string Graph<T>::ipOnIndex(int i){
  for(int j=0; j<ipInfo.size(); j++){
    return ipInfo[i].getIp();
  }
  return "Error";
}
template <class T> void Graph<T>::loadDirWeightedGraph(std::istream &input) {
  std::string line;
  std::string ip1, ip2, peso;
  int i = 0;
  while (std::getline(input, line)) {  
    if (i == 0) { // Leemos numNodes y numEdges
      std::vector<int> res;
      split(line, res);
      numNodes = res[0];
      numEdges = res[1];
      // Reservar memoria para los renglones de la
      // lista de adyacencia (cero basada)
      adjList.resize(numNodes);
      i++;
      continue;
    }
    else if (i >0 && i <= numNodes) {
      T data = line; // ATENCION: convertir al tipo de dato adecuado
      // map <key, data> con los nodos indexados cero basados
      nodesInfo.insert(std::make_pair(i-1, data));
      // Crear objeto ipAddress
      ipAddress tmpIp(line, i-1);
      ipInfo.push_back(tmpIp);
      // Declara una lista de pares (nodo, peso) vacia para
      // cada renglon de adjList
      LinkedList<std::pair<int, int>> tmpList;
      adjList[i-1] = tmpList;
      if (i == numNodes) {
        std::sort(ipInfo.begin(), ipInfo.end());
      }
      i++;
      continue;
    }
    // Tomamos de la linea solo las 2 ips y el peso de la arista
    std::size_t found = line.find(":", 15);
    ip1 = line.substr(15, found-15);
    std::size_t found2 = line.find(" ", found+1);
    std::size_t found3 = line.find(":", found2+1);
    ip2 = line.substr(found2, found3-found2);
    std::size_t found4 = line.find(" ", found3+1);
    std::size_t found5 = line.find(" ", found4+1);
    peso = line.substr(found4, found5-found4);
    // Buscamos a que numero de nodo corresponde cada ip
    int pos1 = binarySearch(ipAddress(ip1, 0));
    int nodeU = ipInfo[pos1].getIpIndex();
    int pos2 = binarySearch(ipAddress(ip2, 0));
    int nodeV = ipInfo[pos2].getIpIndex();
    int weight = std::stoi(peso);
    // El grafo es dirigido y ponderado
    // se agrega la arista (nodeU, nodeV)
    adjList[nodeU].addLast(std::make_pair(nodeV, weight));
    ipInfo[pos1].addToDegreeOut();
    ipInfo[pos2].addToDegreeIn();
    i++;
  }
}

template <class T> void Graph<T>::print(int flagInfo) {
  std::cout << "numNodes: " << numNodes << std::endl;
  std::cout << "numEdges: " << numEdges << std::endl;
  std::cout << "Adjacency List" << std::endl;
  for (int nodeU = 0; nodeU < numNodes; nodeU++) {
    if (flagInfo) // Se imprime la info del nodo
      std::cout << "vertex " << nodesInfo[nodeU] << ": ";
    else // Se imprime el numero de nodo
      std::cout << "vertex " << nodeU + 1 << ": ";
    NodeLinkedList<std::pair<int, int>> *ptr = adjList[nodeU].getHead();
    while (ptr != nullptr) {
      std::pair<int, int> par = ptr->data;
      int nodeV = par.first;
      int weight = par.second;
      std::string nodeData = (flagInfo) ? nodesInfo[nodeV] + ", " : "";
      std::cout << "{" << nodeData << nodeV + 1 << ", " << weight << "} ";
      ptr = ptr->next;
    }
    std::cout << std::endl;
  }
  std::cout << "Grados del grafo" << std::endl;
  for (int i = 0; i < (int)ipInfo.size(); i++) {
    std::cout << "Ip: " << ipInfo[i].getIp() << " Salida: " << ipInfo[i].getDegreeOut() << " Entrada: " << ipInfo[i].getDegreeIn() << std::endl;
  }
}

template <class T> void Graph<T>::saveToFile(){
  std::ofstream file("grados_ips.txt");
  if (!file.is_open()) {
      throw std::runtime_error("No se pudo abrir el archivo para escribir la bitácora ordenada.");
  }
  file << "Grados IPs:"<< std::endl;
  file << std::endl;
  for (int i = 0; i < (int)ipInfo.size(); i++) {
    file << "Ip: " << ipInfo[i].getIp() << " Grado Salida: " << ipInfo[i].getDegreeOut() << " Grado Entrada: " << ipInfo[i].getDegreeIn() << std::endl;
  }
  file.close();
}

template <class T> void Graph<T>::maxHeap(){
  MaxHeap<IPInfo> maxHeap(ipInfo.size());
  std::vector<IPInfo> IPInfoVector;
  for(int i=0; i<ipInfo.size(); i++){
    std::string ip=ipInfo[i].getIp();
    int degreeOut=ipInfo[i].getDegreeOut();
    IPInfo ipInfo(ip, degreeOut, 0);
      IPInfoVector.push_back(ipInfo);
  }
  for(int i=0; i<IPInfoVector.size(); i++){
    maxHeap.push(IPInfoVector[i]);
  }

  std::ofstream file("mayores_grados_ips.txt");
  if (!file.is_open()) {
      throw std::runtime_error("No se pudo abrir el archivo para escribir la bitácora");
  }
  file << "5 IPs Con Mayor Acceso" << std::endl;
  file << std::endl;
  for (int i = 0; i < 5 && !maxHeap.isEmpty(); i++) {
      file <<"IP: "<<maxHeap.getTop().getIP() << " con "<<maxHeap.getTop().getTotalSalientes()<<" Grados de Salida."<<std::endl;
      maxHeap.pop();
  }

  file.close();
}

template<class T> int Graph<T>::bootMaster(){
  std::vector<IPInfo> IPInfoVector;
  int repetidos;
  for (int i = 0; i < ipInfo.size() - 1; i++) {
      if (ipInfo[i].getIpDecimal() == ipInfo[i + 1].getIpDecimal()) {
          repetidos++;
      } else {
          std::string ip = ipInfo[i].getIp();
          IPInfo ipInfo(ip, repetidos, 0);
          IPInfoVector.push_back(ipInfo);
          repetidos = 1; 
      }
  }
  MaxHeap<IPInfo> maxHeap(IPInfoVector.size());
  for(int i=0; i<IPInfoVector.size(); i++){
    maxHeap.push(IPInfoVector[i]);
  }
  for(int i=0; i<ipInfo.size(); i++){
    if(ipInfo[i].getIp()==maxHeap.getTop().getIP()){
      return ipInfo[i].getIpIndex();
    }
    else{
      return -1;
    }
  }
  return -1;
}
// Algoritmo de Dijstra, complejidad O()
template <class T> std::pair<std::vector<int>, std::vector<int>> Graph<T>::shortestPath(int v) {
  // vector de distancias con el resultado del algoritmo
  std::vector<int> dist(numNodes, INF);
  // vector con los predecesores en el camino mas corto
  std::vector<int> prev(numNodes, -1);
  // Crear una priority queue del STL
  // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
  std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;
  // Insertar el nodo de origen v en la cola de prioridad -- pares <dist, nodo>
  pq.push(std::make_pair(0, v));
  dist[v] = 0;
  prev[v] = -1;
  // Mientras la cola de proridad no este vacia
  while (!pq.empty()) {
    // Exraer un nodo nodeU de la cola de prioridad
    int nodeU = pq.top().second; // pares <dist, nodo>
    pq.pop();
    // Obtener los vecinos de nodeU
    NodeLinkedList<std::pair<int, int>> *ptr = adjList[nodeU].getHead();
    while (ptr != nullptr) {
      std::pair<int, int> par = ptr->data;
      int nodeV = par.first; // nodeV es vecino de nodeU
      int weight = par.second; // peso de la arista (nodeU, nodeV) 
      if (dist[nodeV] > dist[nodeU] + weight) {
        // Actualizar la distancia mas corta hasta nodeV
        dist[nodeV] = dist[nodeU] + weight;
        prev[nodeV] = nodeU;
        pq.push(std::make_pair(dist[nodeV], nodeV));
      }
      ptr = ptr->next;
    }
  }
  return std::make_pair(dist, prev);
}
template<class T> void Graph<T>::hash(){
  hashTable.setMaxSize(ipInfo.size());
  for(int i=0; i<ipInfo.size(); i++){
    hashTable.add(ipInfo[i].getIpDecimal(), ipInfo[i]);
  }
}
template<class T> unsigned int Graph<T>::colisiones(){
  return hashTable.getColisiones();
}
template <class T>
void Graph<T>::getIPSummary(std::string ip) {
    ipAddress IP(ip, 0);
    int indice = hashTable.find(IP.getIpDecimal());

    if (indice == -1) {
        std::cout << "Valor no existente"<<std::endl;
    } else {
        std::cout << "Resumen completo de la información para la IP " << ip << ":\n";

        std::cout << "  - IP: " << ip << "\n";
        std::cout << "  - Valor Tabla Hash: " << indice << "\n";
        std::cout << "  - Grado de Salida: " << ipInfo[indice].getDegreeOut() << "\n";
        std::cout << "  - Grado de Entrada: " << ipInfo[indice].getDegreeIn() << "\n";

        int nodeIndex = binarySearch(IP);
        std::vector<std::pair<std::string, int>> adjacentNodes;

        NodeLinkedList<std::pair<int, int>> *ptr = adjList[nodeIndex].getHead();
        while (ptr != nullptr) {
            std::pair<int, int> par = ptr->data;
            int nodeV = par.first;
            int weight = par.second;

            adjacentNodes.push_back(std::make_pair(ipInfo[nodeV].getIp(), weight));

            ptr = ptr->next;
        }

        std::sort(adjacentNodes.begin(), adjacentNodes.end(),
                  [](const auto &a, const auto &b) { return a.second > b.second; });

        std::cout << "\nLista de direcciones accesadas desde la IP " << ip << " (ordenadas en forma descendente por peso):\n";
        for (const auto &adjacentNode : adjacentNodes) {
            std::cout << "  - IP: " << adjacentNode.first << ", Peso: " << adjacentNode.second << "\n";
        }
    }
}


#endif // _GRAPH_H_
