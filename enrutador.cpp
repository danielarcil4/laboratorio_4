#include "enrutador.h"

map<char, char> enrutador::getConexion() const
{
    return conexion;
}

void enrutador::setConexion(const map<char, char> &value)
{
    conexion = value;
}

map<char, map<char, char> > enrutador::getRuta() const
{
    return ruta;
}

void enrutador::setRuta(const map<char, map<char, char> > &value)
{
    ruta = value;
}

enrutador::enrutador(map<char, map<char, char> > ruta)
{

  this->ruta = ruta ;
}
