#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <iostream>
#include <map>

using namespace std;

class enrutador
{
private:

    map<char,map<char,string>> ruta;
    map<char,char> conexion;

public:
    enrutador(map<char,map<char,string>> ruta);

    map<char, char> getConexion() const;
    void setConexion(const map<char, char> &value);

    map<char, map<char, string> > getRuta() const;
    void setRuta(const map<char, map<char, string> > &value);
};

#endif // ENRUTADOR_H
