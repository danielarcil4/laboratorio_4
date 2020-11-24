#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <iostream>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

class enrutador
{
private:

    map<char,map<char,string>> ruta;

public:
    enrutador(map<char,map<char,string>> ruta);

    bool verificador(char);

    void lectura(vector<char> *ptr);

    void conexiones(vector<string> &conexiones_,vector<string> &valores);

    void escritura(vector<string> conexiones_,vector<string> valores,string Ruta,short int Costo);

    void escritura(vector<char> enrutadores);

    int algoritmo(map<char,map<char,string>>,char,char,vector<string>,char,short int,map<char,vector<string>>,short int,string Ruta_,string bloqueado);

    void crearRutas(map<char,string > conexion,map <char,map<char,string>> &rutas,vector<char> enrutadores,vector<string> conexiones_,vector<string> valores);

};

#endif // ENRUTADOR_H
