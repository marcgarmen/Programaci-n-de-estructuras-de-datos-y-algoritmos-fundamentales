#include "IPInfo.h"

IPInfo::IPInfo() : totalSalientes(0), totalEntrantes(0) {
    ip = "";
}

IPInfo::IPInfo(std::string ip, int totalSalientes, int totalEntrantes)
    : ip(ip), totalSalientes(totalSalientes), totalEntrantes(totalEntrantes) {}

void IPInfo::setIP(std::string ip) {
    this->ip = ip;
}

void IPInfo::setTotalSalientes(int totalSalientes) {
    this->totalSalientes = totalSalientes;
}

void IPInfo::setTotalEntrantes(int totalEntrantes) {
    this->totalEntrantes = totalEntrantes;
}

std::string IPInfo::getIP() const {
    return ip;
}

int IPInfo::getTotalSalientes() const {
    return totalSalientes;
}

int IPInfo::getTotalEntrantes() const {
    return totalEntrantes;
}
