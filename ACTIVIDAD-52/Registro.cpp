#include "Registro.h"

//complejidad de O(1)
Registro::Registro() {
  mes = "";
  dia = "";
  horas = "";
  minutos = "";
  segundos = "";
  ip = "";
  puerto = "";
  falla = "";
  fechaHora = 0;
  ipDecimal = 0;
}

//complejidad de O(n log n)
Registro::Registro(std::string _mes, std::string _dia, std::string _horas, std::string _minutos, std::string _segundos, std::string _ip, std::string _puerto, std::string _falla) {
    mes = _mes;
    dia = _dia;
    horas = _horas;
    minutos = _minutos;
    segundos = _segundos;
    ip = _ip;
    puerto = _puerto;
    falla = _falla;
    // Convertir a Linux timestamp
    dateStruct.tm_hour = std::stoi(horas);
    dateStruct.tm_min = std::stoi(minutos);
    dateStruct.tm_sec = std::stoi(segundos);
    dateStruct.tm_mday = std::stoi(dia);
    // resuelve problemas de compatibilidad con Windows
    dateStruct.tm_isdst = 0;
    for (int i = 0; i < (int)meses.size(); i++) {
      if (meses[i] == mes)
        dateStruct.tm_mon = i;
    }
    dateStruct.tm_year = 2024 - 1900; // asumimos el año 2024
    // Obtener el Linux timestamp
    // https://cplusplus.com/reference/ctime/mktime/
    fechaHora = mktime(&dateStruct);
    //std::cout << "fechaHora: " << fechaHora << std::endl;

    //Conversion de la ip a fecha decimal
    int posInit = 0;
    int posFound = 0;
    std::string splitted;
    std::vector<std::string> results;
    while(posFound >= 0) {
      posFound = ip.find(".", posInit);
      splitted = ip.substr(posInit, posFound - posInit);
      posInit = posFound + 1;
      results.push_back(splitted);
    }
  int oct3 = std::stoi(results[0]); //octeto 3
  int oct2 = std::stoi(results[1]);
  int oct1 = std::stoi(results[2]);
  int oct0 = std::stoi(results[3]);
  ipDecimal = (oct3 *std::pow(256,3)) + (oct2 *std::pow(256,2)) + (oct1 *std::pow(256,1)) + oct0;
}

//complejidad de O(1)
std::string Registro::getAll() const {
  return mes + " " + dia + " " + horas + ":" + minutos + ":" + segundos + " " + ip + ":" + puerto + " " + falla;  
}

//complejidad de O(1)
unsigned int Registro::getIpDecimal() const {
  return ipDecimal;
}

//complejidad de O(1)
std::string Registro::getIpStr() const {
  return ip;
}

//complejidad de O(1)
// sobrecarga de operadores de comparacion
bool Registro::operator ==(const Registro &other) const {
  return this->ipDecimal == other.ipDecimal;
}

//complejidad de O(1)
bool Registro::operator !=(const Registro &other) const {
  return this->ipDecimal != other.ipDecimal;
}

//complejidad de O(1)
bool Registro::operator  >(const Registro &other) const {
  return this->ipDecimal > other.ipDecimal;
}

//complejidad de O(1)
bool Registro::operator  <(const Registro &other) const{
  return this->ipDecimal < other.ipDecimal;
}

//complejidad de O(1)
bool Registro::operator >=(const Registro &other) const{
  return this->ipDecimal >= other.ipDecimal;
}

//complejidad de O(1)
bool Registro::operator <=(const Registro &other) const{
  return this->ipDecimal <= other.ipDecimal;
}