#include "IPInfo.h"
IPInfo::IPInfo(){
  ip="";
  ingresos=0;
}
IPInfo::IPInfo(std::string ip, int accesos){
  this->ip = ip;
  this->ingresos = accesos;
}
void IPInfo::setIngresos(int ingresos){
  this->ingresos=ingresos;
}
void IPInfo::setIP(std::string ip){
  this->ip=ip;
}
int IPInfo::getIngresos(){
  return ingresos;
}
std::string IPInfo::getIP(){
  return ip;
}
bool IPInfo::operator ==(const IPInfo &other) const {
  return this->ingresos == other.ingresos;
}

bool IPInfo::operator !=(const IPInfo &other) const {
  return this->ingresos != other.ingresos;
}

bool IPInfo::operator  >(const IPInfo &other) const {
  return this->ingresos > other.ingresos;
}

bool IPInfo::operator  <(const IPInfo &other) const{
  return this->ingresos < other.ingresos;
}

bool IPInfo::operator >=(const IPInfo &other) const{
  return this->ingresos >= other.ingresos;
}

bool IPInfo::operator <=(const IPInfo &other) const{
  return this->ingresos <= other.ingresos;
}