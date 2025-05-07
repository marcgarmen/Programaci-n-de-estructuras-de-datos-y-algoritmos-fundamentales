#include "Bitacora.h"
#include "SearchAlgorithm.h"
Bitacora::Bitacora() {
    // Implementación del constructor
}

Bitacora::~Bitacora() {
    // Implementación del destructor
}
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

          // Crear un objeto Registro y agregarlo a la listaRegistros
          Registro registro(mes, dia, horas, minutos, segundos, ip, puerto, falla);
          listaRegistros.addLast(registro);
      } else {
          std::cerr << "No se pudo extraer datos de la línea: " << linea << std::endl;
      }
  }

  archivo.close();
}

void Bitacora::mergeSort() {
  auto start_time = std::chrono::high_resolution_clock::now();
  listaRegistros.mergeSort();
  auto end_time = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

  std::ofstream archivoOrdenado("bitacora_ordenada_mergeSort.txt");
  if (!archivoOrdenado.is_open()) {
    throw std::runtime_error("No se pudo abrir el archivo para escribir la bitácora ordenada.");
  }

  archivoOrdenado << "Tiempo transcurrido en mergeSort: " << duration << " microsegundos" << std::endl;
  archivoOrdenado << std::endl;
  for (int i = 0; i < listaRegistros.getNumElements(); ++i) {
    Registro registro = listaRegistros.getData(i);
    archivoOrdenado << registro.getAll() << std::endl;
  }

  archivoOrdenado.close();
}
void Bitacora::quickSort(){
  auto start_time = std::chrono::high_resolution_clock::now();
  listaRegistros.quickSort();
  auto end_time = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

  std::ofstream archivoOrdenado("bitacora_ordenada_quickSort.txt");
  if (!archivoOrdenado.is_open()) {
    throw std::runtime_error("No se pudo abrir el archivo para escribir la bitácora ordenada.");
  }

  archivoOrdenado << "Tiempo transcurrido en mergeSort: " << duration << " microsegundos" << std::endl;
  archivoOrdenado << std::endl;
  for (int i = 0; i < listaRegistros.getNumElements(); ++i) {
    Registro registro = listaRegistros.getData(i);
    archivoOrdenado << registro.getAll() << std::endl;
  }

  archivoOrdenado.close();
}
void Bitacora::buscarEnBitacora(Registro fechaInicio, Registro fechaFin) {
    // Crear un vector ordenado con las fechas de la bitácora
    std::vector<Registro> registrosOrdenados = listaRegistros.toArray();
    SearchAlgorithm<Registro> searchAlgorithm;

    // Realizar búsqueda binaria
    int indexInicio = searchAlgorithm.busquedaBinaria(registrosOrdenados, fechaInicio, indexInicio);
    int indexFin = searchAlgorithm.busquedaBinaria(registrosOrdenados, fechaFin, indexFin);

    // Verificar y corregir índices si es necesario
    if (indexInicio >= registrosOrdenados.size()) {
        indexInicio = registrosOrdenados.size() - 1;
    }

    if (indexFin >= registrosOrdenados.size()) {
        indexFin = registrosOrdenados.size() - 1;
    }

    // Abrir archivo para escribir los resultados
    std::ofstream archivoResultados("resultados_busqueda.txt");
    if (!archivoResultados.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo para escribir los resultados de la búsqueda.");
    }

    // Escribir resultados en el archivo
    archivoResultados << "Fecha 1: " << fechaInicio.getAll() << std::endl;
    archivoResultados << "Fecha 2: " << fechaFin.getAll() << std::endl;
    archivoResultados << std::endl;
    archivoResultados << registrosOrdenados[indexInicio].getAll()<<std::endl;
    // Imprimir registros en el archivo sin duplicados
    for (int i = indexInicio; i <= indexFin; ++i) {
        if (i == 0 || registrosOrdenados[i] != registrosOrdenados[i - 1]) {
            archivoResultados << registrosOrdenados[i].getAll() << std::endl;
        }
    }

    // Cerrar el archivo
    archivoResultados.close();
}
