#include "Bitacora.h"
Bitacora::Bitacora() {}
Bitacora::~Bitacora() { listaRegistros.clear(); }
void Bitacora::leerArchivo(std::string filePath) {
  std::ifstream archivo(filePath);
  if (!archivo.is_open()) {
      throw std::runtime_error("No se pudo abrir el archivo: " + filePath);
  }

  std::string linea;
  while (std::getline(archivo, linea)) {
      // Definir la expresión regular para extraer datos
      std::regex patron(R"((\w{3}) (\d{1,2}) (\d{1,2}):(\d{1,2}):(\d{1,2}) ([\d\.]+):(\d+) (.+))");

      std::smatch coincidencias;
      if (std::regex_match(linea, coincidencias, patron)) {
          // Extraer componentes de la coincidencia
          std::string mes = coincidencias[1];
          std::string dia = coincidencias[2];
          std::string horas = coincidencias[3];
          std::string minutos = coincidencias[4];
          std::string segundos = coincidencias[5];
          std::string ip = coincidencias[6];
          std::string puerto = coincidencias[7];
          std::string falla = coincidencias[8];

          // Crear un objeto Registro y agregarlo al vector listaRegistros
          Registro registro(mes, dia, horas, minutos, segundos, ip, puerto, falla);
          listaRegistros.push_back(registro);
      } else {
          std::cerr << "No se pudo extraer datos de la línea: " << linea << std::endl;
      }
  }

  archivo.close();
}
void Bitacora::bubbleSort() {
  AlgorithmSort<Registro> sortObj;
  unsigned int comparaciones, swaps;
  comparaciones = swaps = 0;
  sortObj.bubbleSort(listaRegistros, listaRegistros.size(), comparaciones,
                     swaps);
}
void Bitacora::mergeSort() {
  AlgorithmSort<Registro> sortObj;
  unsigned int comparaciones, swaps;
  comparaciones = swaps = 0;
  sortObj.mergeSort(listaRegistros, 0, listaRegistros.size() - 1, comparaciones);
}
int Bitacora::busquedaBinaria(Registro dato) {
  SearchAlgorithm<Registro> searchObj;
  int comparaciones;
  return searchObj.busquedaBinaria(listaRegistros, dato, comparaciones);
}
int Bitacora::imprimirRegistrosEntreFechas(Registro fecha_inicio,Registro fecha_fin) {
  int contador=0;
  int inicio = busquedaBinaria(fecha_inicio);
  int fin = busquedaBinaria(fecha_fin);


  if (inicio == -1 || fin == -1) {
      std::cerr << "Al menos una de las fechas no se encuentra en la bitácora." << std::endl;
      return -1;
  }

  for (int i = inicio; i <= fin; i++) {
      listaRegistroFecha.push_back(listaRegistros[i]);
      contador++;
  }
  return contador;
}