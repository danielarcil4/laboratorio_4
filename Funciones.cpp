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

int algoritmo(map<char,map<char,char>> rutas,char inicio,char final,vector<string> repetido,char primerdato,short int i,map<char,vector<string>> repetidos,short int cont,string Ruta_){
    short int I=0;
    bool L=true;
    string copia_s,copia_pri,copia_in,copia;
    for(auto a=rutas[inicio].begin();a!=rutas[inicio].end();a++){
        copia_s = a->first ,copia_pri=primerdato,copia_in=inicio;

        //repetido.push_back(primerdato);
        //repetidos[inicio].push_back(primerdato);
        bool l=true;

        //Ingresa el dato base a todos
        for(auto b:repetidos[a->first])
            if(b==copia_pri)
                L=false;

        if(L==true)
            repetidos[a->first].push_back(copia_pri);

        L=true;

        //verifica no ir en un camino repetido
        for(auto b:repetidos[inicio]){
            if(copia_s==b){
                l=false;
                }
            }
        if(l==true){
            copia=repetido[0];
            repetido[0]+= a->first;
            for(auto b:repetidos[primerdato]){
                if(repetido[0]==b){
                    l=false;
                    }
                }
            if(l==false){
                repetido.clear();
                repetido.push_back(copia);
                copia=a->first;
                repetidos[inicio].push_back(copia);
            }
            if(repetido[0].length()>1){
                for(auto c:rutas[inicio]){
                    for(auto d:repetidos[inicio]){
                        copia_s=c.first;
                        if(d==copia_s)
                            I++;
                    }

                }
                if(I==rutas[inicio].size()){
                    repetidos[primerdato].push_back(repetido[0]);
                    repetido.clear();
                    repetido.push_back(copia_pri);
                    inicio=primerdato;
                    i=0;
                    return algoritmo(rutas,inicio,final,repetido,primerdato,i,repetidos,cont,Ruta_);
                    }
             }

        }

        if(l==true){
            for(auto b:repetidos[primerdato]){
                if(b==repetido[0])
                    L=false;
            }
            if(rutas[inicio].size()-1>1 and L==true)
                repetidos[primerdato].push_back(repetido[0]);
            L=true;

            for(auto b:repetidos[a->first]){
                if(b==copia_in)
                    L=false;
            }

            if(L==true)
                repetidos[a->first].push_back(copia_in);

            L=true;


            inicio=a->first;

            i+=(a->second-48);
            if(a->first==final){
                if(i<cont){
                    Ruta_.clear();
                    Ruta_= repetido[0];
                    cont=i;
                }
                cout<< "La ruta es: ";
                cout<<repetido[0]<<endl;
                repetidos[primerdato].push_back(repetido[0]);
                repetido.clear();
                repetido.push_back(copia_pri);
                inicio=primerdato;
                cout<<"cuesta: "<<i<<endl;
                i=0;
                }
            return algoritmo(rutas,inicio,final,repetido,primerdato,i,repetidos,cont,Ruta_);
            }
    }
    cout<<"\nLa ruta mas corta es: "<<Ruta_<<endl;
    return cont;

}

