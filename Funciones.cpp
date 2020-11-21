#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

void lectura(vector<char> *ptr){
    ifstream lectura;
    char b;
    vector<char> enrutadores;

    lectura.open("../lab_4/BD/enrutadores.txt");

    if (!lectura.is_open())
       {
         cout << "Error abriendo el archivo" << endl;
         exit(1);
       }
    lectura>>b;

    while(!lectura.eof()){
        enrutadores.push_back(b);
        lectura>>b;
    }
    *ptr=enrutadores;

}

void escritura(vector<char> enrutadores){
    ofstream escritura;
    escritura.open("../lab_4/BD/enrutadores.txt");

    if (!escritura.is_open())
       {
         cout << "Error abriendo el archivo" << endl;
         exit(1);
       }

     for(auto a:enrutadores){
        escritura<<a<<endl;
     }

     escritura.close();

}

void escritura(string Ruta,short int Costo){

    ofstream escritura;
    escritura.open("../lab_4/BD/topologia.txt",ios::app);

    if (!escritura.is_open())
       {
         cout << "Error abriendo el archivo" << endl;
         exit(1);
       } 

    escritura<<Ruta<<" "<<Costo<<endl;

    escritura.close();
}

void conexiones(vector<string> &conexiones_){
    string data,enrutadores;

    ifstream lectura;
    lectura.open("../lab_4/BD/topologia.txt");

    if (!lectura.is_open())
       {
         cout << "Error abriendo el archivo" << endl;
         exit(1);
       }

    lectura>>data;


    while(!lectura.eof()){
        enrutadores+=data;
        cout <<"Ruta: "<< data <<" ";
        lectura>>data;
        enrutadores+=data;
        cout<<"Costo: "<< data << endl;
        lectura>>data;
        conexiones_.push_back(enrutadores);
        enrutadores="";
    }
    lectura.close();
}

bool verificador(char nombre){
    ifstream lectura;
    char b;
    lectura.open("../lab_4/BD/enrutadores.txt");

    if (!lectura.is_open())
       {
         cout << "Error abriendo el archivo" << endl;
         exit(1);
       }
    lectura>>b;
    while(!lectura.eof()){
        if(nombre==b){
            return false;
        }
        lectura>>b;
    }
    return true;
}

int algoritmo(map<char,map<char,char>> rutas,char inicio,char final,vector<char> repetido,char primerdato,short int i){

    for(auto a=rutas[inicio].begin();a!=rutas[inicio].end();a++){
        bool l=true;
        for(auto b:repetido){
            if(a->first==b){
                l=false;
                }
            }
        if(primerdato==inicio and l==true){
            repetido.push_back(a->first);
            }
        if(l==true){
            cout<< "El enrutador conectado es: ";
            inicio=a->first;
            cout<< a->first <<endl;
            i+=(a->second-48);
            if(a->first==final){
                inicio=primerdato;
                cout<<i<<endl;
                i=0;
                }
            return algoritmo(rutas,inicio,final,repetido,primerdato,i);
            }
        }
    return i;


}

