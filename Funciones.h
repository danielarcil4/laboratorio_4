#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool verificador(char);
void lectura(vector<char> *ptr);
void conexiones(vector<string> &conexiones_,vector<string> &valores);
void escritura(vector<string> conexiones_,vector<string> valores,string Ruta,short int Costo);
void escritura(vector<char> enrutadores);
int algoritmo(map<char,map<char,string>>,char,char,vector<string>,char,short int,map<char,vector<string>>,short int,string Ruta_,string bloqueado);


#endif // FUNCIONES_H
