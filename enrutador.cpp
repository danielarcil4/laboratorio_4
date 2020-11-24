#include "enrutador.h"

map<char, char> enrutador::getConexion() const
{
    return conexion;
}

void enrutador::setConexion(const map<char, char> &value)
{
    conexion = value;
}

map<char, map<char, string> > enrutador::getRuta() const
{
    return ruta;
}

void enrutador::setRuta(const map<char, map<char, string> > &value)
{
    ruta = value;
}

enrutador::enrutador(map<char, map<char, string> > ruta)
{

  this->ruta = ruta ;
}
