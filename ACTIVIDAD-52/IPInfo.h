#ifndef _IPINFO_H_
#define _IPINFO_H_

#include <string>

class IPInfo {
public:
    std::string ip;
    int totalSalientes;
    int totalEntrantes;

public:
    IPInfo();
    IPInfo(std::string ip, int totalSalientes, int totalEntrantes);
    void setIP(std::string ip);
    void setTotalSalientes(int totalSalientes);
    void setTotalEntrantes(int totalEntrantes);
    std::string getIP() const;
    int getTotalSalientes() const;
    int getTotalEntrantes() const;

    bool operator<(const IPInfo& other) const {
        return totalSalientes < other.totalSalientes;
    }

    bool operator>(const IPInfo& other) const {
        return totalSalientes > other.totalSalientes;
    }
};

#endif // _IPINFO_H_