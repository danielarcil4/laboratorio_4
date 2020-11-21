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
    cout<<"(1) Nuevo Enrutador\n"
          "(2) Actualizar rutas\n"
          "(3) Salir."<<endl;

    char A;
    cin>>A;
    if(A=='1'){
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
                    cout<<"Ingrese el costo de la conexion del nuevo enrutador con el que acaba de ingresar: "<<endl;
                    cin>>valor;


                        }
                //se crean sus rutas

                rutas [nombre1] = conexion;
                enrutador newrut(rutas);

                    }
                }
            else
                cout<<"El enrutador ya existe!!"<<endl;
    }
    else if(A=='2'){
        char letra,final;
        short int i=0;
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
        cout<<"Ingresar segundo enrutador: "<<endl;
        cin>>final;
        if(letra<=122 and letra>=97)
            letra-=32;
        if(final<=122 and final>=97)
            final-=32;

        //cout<<"La distacia entre los enrutadores es: "<<rutas[letra][letra2]<<endl;
        system("cls");
        i=0;
        char primerdato=letra;
        vector<char> repetido;
        repetido.push_back(primerdato);
        i = algoritmo(rutas,letra,final,repetido,primerdato,i);


    }






    else
        cout<<"Se ha salido"<<endl;





    return 0;
}
















