#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

void lectura(vector<char> *enrutadores){
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
        enrutadores->push_back(b);
        lectura>>b;

    }
   // *ptr=enrutadores;

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

void escritura(vector<string> conexiones_,vector<string> valores,string Ruta,short int Costo){
    short int i=0;
    ofstream escritura;
    escritura.open("../lab_4/BD/topologia.txt");

    if (!escritura.is_open())
       {
         cout << "Error abriendo el archivo" << endl;
         exit(1);
       }

    for(auto a:conexiones_)
    {
        escritura<<conexiones_[i] <<" "<<valores[i] <<endl;
        i++;
    }


    if(Ruta!="0" and Costo!=0){
        escritura<<Ruta[0]<<Ruta[1]<<" "<<Costo<<endl;
        escritura<<Ruta[1]<<Ruta[0]<<" "<<Costo<<endl;
    }


    escritura.close();
}

void conexiones(vector<string> &conexiones_,vector<string> &valores){
    string data;

    ifstream lectura;
    lectura.open("../lab_4/BD/topologia.txt");

    if (!lectura.is_open())
       {
         cout << "Error abriendo el archivo" << endl;
         exit(1);
       }

    lectura>>data;


    while(!lectura.eof()){
        conexiones_.push_back(data);
        lectura>>data;
        valores.push_back(data);
        lectura>>data;       
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

int algoritmo(map<char,map<char,string>> rutas,char inicio,char final,vector<string> repetido,char primerdato,short int i,map<char,vector<string>> repetidos,short int cont,string Ruta_,string bloqueado){
    short int I=0;
    bool L=true;
    string copia_s,copia_pri,copia_in,copia;
    for(auto a=rutas[inicio].begin();a!=rutas[inicio].end();a++){
        copia_s = a->first ,copia_pri=primerdato,copia_in=inicio;

        //verifica no ir a un enrutador donde ya paso otro enrutador
        copia.clear();
        if(inicio!=final){
            for(auto b:repetidos){
                for(auto c:repetidos[b.first]){
                    if(c==copia_in)
                        L=false;
                   }
                if(L==true and b.first!=primerdato and b.first!=repetido[0][repetido[0].length()-2])
                    repetidos[b.first].push_back(copia_in);
            }
        }

        L=true;

        bool l=true;

        //Ingresa el dato base a todos
        for(auto b:repetidos[a->first])
            if(b==copia_pri)
                L=false;

        if(L==true)
            repetidos[a->first].push_back(copia_pri);

        L=true;

        //verifica no ir en una ruta repetida
        for(auto b:repetidos[inicio]){
            if(copia_s==b){
                l=false;
                }
            }

        if(l==true){
            copia.clear();
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
                if(repetido[0].size()==1){
                    for(auto b:repetidos){
                        if(b.first!=primerdato)
                            repetidos[b.first].clear();
                    }
                }
                copia=a->first;
                repetidos[inicio].push_back(copia);
            }
            I=0;
            if(repetido[0].length()>1){
                for(auto c:rutas[inicio]){
                    for(auto d:repetidos[inicio]){
                        copia_s=c.first;
                        if(d==copia_s)
                            I++;
                    }

                }
                if(I==rutas[inicio].size() and l==false){
                    if(inicio==bloqueado[0]){
                        for(auto b:repetidos){
                            if(b.first!=primerdato)
                                repetidos[b.first].clear();
                        }
                    }
                    repetidos[primerdato].push_back(repetido[0]);
                    repetido.clear();
                    repetido.push_back(copia_pri);
                    inicio=primerdato;
                    i=0;
                    return algoritmo(rutas,inicio,final,repetido,primerdato,i,repetidos,cont,Ruta_,bloqueado);
                    }
             }

        }

        if(l==true){

            inicio=a->first;

            if(a->second[1]!='\0'){
                i+=(a->second[0]-48)*10;
                i+=(a->second[1]-48);
            }
            else
                i+=(a->second[0]-48);

            if(a->first==final){
                bloqueado=copia_in;
                for(auto b:repetidos){
                    if(b.first!=primerdato and b.first!=copia_in[0])
                        repetidos[b.first].clear();
                }
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
                repetido.push_back(copia_in);
                inicio=primerdato;
                cout<<"cuesta: "<<i<<endl;
                i=0;
                }
            else{
                //verifica que a donde va se pueda ir
                I=0;
                for(auto b:repetidos[a->first]){
                    if(b==copia_in)
                        L=false;
                }
                if(L==true)
                    repetidos[a->first].push_back(copia_in);
                L=true;
                for(auto b:rutas[a->first]){
                    copia.clear();
                    copia=b.first;
                    for(auto c:repetidos[a->first]){
                        if(copia==c){
                            I++;
                        }
                    }
                }

                if(I==rutas[a->first].size()){
                    repetidos[primerdato].push_back(repetido[0]);
                    repetido.clear();
                    repetido.push_back(copia_pri);
                    inicio=primerdato;
                    i=0;
                    return algoritmo(rutas,inicio,final,repetido,primerdato,i,repetidos,cont,Ruta_,bloqueado);
                    }
            }
            return algoritmo(rutas,inicio,final,repetido,primerdato,i,repetidos,cont,Ruta_,bloqueado);
            }
    }
    cout<<"\nLa ruta mas corta es: "<<Ruta_<<endl;
    return cont;

}

