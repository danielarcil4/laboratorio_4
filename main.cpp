#include <iostream>
#include <string>
#include <fstream>
#include "enrutador.h"
#include "Funciones.h"
#include <vector>

using namespace std;

string lectura();
void escritura();


int main()
{
    bool verificador_;
    vector<char> enrutadores;
    map <char,map<char,char>> rutas;
    map<char,char > conexion;
    cout<<"Menu Principal: "<<endl;
    cout<<"(1) Aniadir Enrutadores\n"
          "(2) Ruta De Menor Costo\n"
          "(3) Eliminar Enrutadores\n"
          "(4) Salir."<<endl;

    char A;
    cin>>A;
    if(A=='1'){
        while (A!='0') {
            char nombre,nombre1;
            string red2="00";
            short int valor;
            cout<<"Ingrese la letra del nuevo enrutador: "<<endl;
            cin>>nombre1;
            if(nombre1<=122 and nombre1>=97)
                nombre1-=32;
            //verificacion enrutador
            verificador_ = verificador(nombre1);
            if(verificador_){
                //se crea sus conexiones
                cout<<"Ingrese '0' si ya no desea ingresar un nuevo enrutador\n"<<endl;
                cout<<"Ingrese las rutas directamente \n"
                      "conectadas de la siguiente manera \n"<<endl;
                cout<<"Nombre del enrutador conectado al que se acaba de crear: "<<endl;
                cin>>nombre;
                if(nombre!='0'){
                    if(nombre<=122 and nombre>=97)
                        nombre-=32;
                    verificador_=verificador(nombre);
                    if(verificador_)
                        cout<<nombre<<" no esta"<<endl;
                    }
                if(!verificador_){
                    lectura(&enrutadores);
                    enrutadores.push_back(nombre1);
                    escritura(enrutadores);

                    cout<<"Costo de la conexion del nuevo enrutador con el que acaba de ingresar: "<<endl;
                    cin>>valor;
                    system("cls");

                    while(nombre != '0' and valor != 0  ){
                        //-------------------
                        //Ingreso conexiones
                        //-------------------

                        red2[0] = nombre1;
                        red2[1] = nombre;
                        //se escribe en la BD las conexiones con su valor
                        escritura(red2,valor);
                        //se ingresa una a una las conexiones
                        cout<<"Ingrese '0' cuando haya terminado: "<<endl;
                        conexion[nombre] = valor;
                        cout<<"Ingrese el nombre del enrutador conectado al que se acaba de crear: "<<endl;
                        cin>>nombre;
                        if(nombre<=122 and nombre>=97)
                            nombre-=32;
                        cout<<"Ingrese el costo de la conexion del nuevo enrutador con el que acaba de ingresar: "<<endl;
                        cin>>valor;


                            }
                    //se crean sus rutas

                    rutas [nombre1] = conexion;
                    enrutador newrut(rutas);

                        }
                cout<<"Desea agregar otro enrutador?\n"
                      "(1) Si\n"
                      "(0) No"<<endl;
                cin>>A;
                    }
                else{
                    cout<<"El enrutador ya existe!!"<<endl;
                    A='0';
                    }
        }

    }
    else if(A=='2'){
        char letra,final;
        short int i=0,I=100;
        vector<string> conexiones_;
        lectura(&enrutadores);
        conexiones(conexiones_);

        //se crean las claves
        for(auto a:enrutadores){
            letra=a;
            i=0;
            for(auto I:conexiones_){
                if(letra==conexiones_[i][0])
                    conexion[conexiones_[i][1]]=conexiones_[i][2];
                i++;
            }
            rutas[a]=conexion;
            conexion.clear();
        }
        cout<<"Hacer una busqueda\n"
              "Ingresar primer enrutador: "<<endl;
        cin>>letra;
        if(letra<=122 and letra>=97)
            letra-=32;
        verificador_=verificador(letra);
        if(!verificador_){
            cout<<"Ingresar segundo enrutador: "<<endl;
            cin>>final;
            if(final<=122 and final>=97)
                final-=32;
            verificador_=verificador(final);
            if(!verificador_){
                system("cls");
                i=0;
                char primerdato=letra;
                string primerdato_,Ruta_,bloqueado;
                primerdato_+=letra;
                vector<string> repetido;
                repetido.push_back(primerdato_);
                map<char,vector<string>> repetidos;
                for(auto b:rutas){
                    repetidos[b.first];
                }
                i = algoritmo(rutas,letra,final,repetido,primerdato,i,repetidos,I,Ruta_,bloqueado);
                cout<<"Y cuesta: "<<i<<endl;

            }
            else
                cout<<"El enrutador no esta"<<endl;

        }
        else
            cout<<"El enrutador no esta"<<endl;






    }
    else if(A=='3'){

    }

    else
        cout<<"Se ha salido"<<endl;





    return 0;
}
















