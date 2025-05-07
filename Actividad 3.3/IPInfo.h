#ifndef _IPINFO_H_
#define _IPINFO_H_

#include <string>

class IPInfo {
private:
    std::string ip;
    int ingresos;

public:
    IPInfo();
    IPInfo(std::string ip, int ingresos);
    void setIngresos(int ingresos);
    void setIP(std::string ip);
    std::string getIP();
    int getIngresos();
    bool operator ==(const IPInfo &other) const;
    bool operator !=(const IPInfo &other) const;
    bool operator  >(const IPInfo &other) const;
    bool operator  <(const IPInfo &other) const;
    bool operator >=(const IPInfo &other) const;
    bool operator <=(const IPInfo &other) const;
};

#endif // _IPINFO_H_