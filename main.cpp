#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include<algorithm>
#define NOMBRE_EXCEL "Tabla_Harris-Benedict.csv"

using namespace std;

void ordenaporcalorias(vector<vector<string>> s){
vector<int> resp, resp2;
int i, ii, iii=0;
for(i=0;i<s.size();i++){
    resp.push_back(stoi(s[i][6]));
    resp2.push_back(stoi(s[i][6]));
}

int x, y, aux, mini;

    for(x=0;x<resp.size();x++){
        mini=x;
        for(y=x+1;y<resp.size();y++){
            if (resp[y]<resp[mini]){
                mini = y;
            }
        }
        aux = resp[x];
        resp[x] = resp[mini];
        resp[mini] = aux;
    }

for(i=0;i<resp.size();i++){
    for(ii=0;ii<resp2.size();ii++){
      if (resp[i]==resp2[ii]){
        cout<<"El paciente numero "<<iii+1<<" en el ordenamiento es "<<s[ii][0]<<" con "<<s[ii][6]<<" calorias."<<endl;
        iii++;
      }
    }
}
cout<<endl;
}

void ordenaporalfabeto(vector<vector<string>> s){
vector<string> resp, resp2;
int i, ii, iii=0;
for(i=0;i<s.size();i++){
    resp.push_back(s[i][0]);
    resp2.push_back(s[i][0]);
}

int x, y, mini;
string aux;

    for(x=0;x<resp.size();x++){
        mini=x;
        for(y=x+1;y<resp.size();y++){
            if (resp[y]<resp[mini]){
                mini = y;
            }
        }
        aux = resp[x];
        resp[x] = resp[mini];
        resp[mini] = aux;
    }

for(i=0;i<resp.size();i++){
    for(ii=0;ii<resp2.size();ii++){
      if (resp[i]==resp2[ii]){
        cout<<"El paciente numero "<<iii+1<<" en el ordenamiento es "<<s[ii][0]<<endl;
        iii++;
      }
    }
}

cout<<endl;
}

int consumocalorico(vector<string> datos){
float kg, cm, a, e, tmb;
kg=stoi(datos[2]);
cm=stoi(datos[3]);
a=stoi(datos[4]);
e=stoi(datos[5]);
if (datos[1] == "Masculino"){
    tmb = 66+(13.7*kg)+(5*cm)-(6.8*a);
}
else if (datos[1] == "Femenino"){
    tmb = 655+(9.6*kg)+(1.8*cm)-(4.7*a);
}

if (e==1){
    tmb=tmb*1.2;
}

else if (e==2){
    tmb=tmb*1.375;
}

else if (e==3){
    tmb=tmb*1.55;
}

else if (e==4){
    tmb=tmb*1.72;
}

else if (e==5){
    tmb=tmb*1.9;
}

return tmb;
}

void imprimir(vector<vector<string>> vector_final){
int i;
for(i=0;i<vector_final.size();i++){
    cout<<"----------------------------------------------------"<<endl;
    cout<<"Nombre del paciente: "<<vector_final[i][0]<<endl;
    cout<<"Sexo: "<<vector_final[i][1]<<endl;
    cout<<"Peso en kilogramos: "<<vector_final[i][2]<<endl;
    cout<<"Estatura en cm: "<<vector_final[i][3]<<endl;
    cout<<"Edad: "<<vector_final[i][4]<<endl;
    cout<<"Cantidad de ejercicio realizado: ";

    if (vector_final[i][5]=="1"){
    cout<<"Muy Poca o inexistente"<<endl;
    }

    else if (vector_final[i][5]=="2"){
    cout<<"Ligera"<<endl;
    }

    else if (vector_final[i][5]=="3"){
    cout<<"Moderada"<<endl;
    }

    else if (vector_final[i][5]=="4"){
    cout<<"Alta"<<endl;
    }

    else if (vector_final[i][5]=="5"){
    cout<<"Extrema"<<endl;
    }

    cout<<"Cantidad de calorias a consumir: "<<vector_final[i][6]<<endl;
}
    cout<<"----------------------------------------------------"<<endl<<endl;
}
void seleccion(vector<vector<string>> s){
int sel;
cout<<"Calorex"<<endl;
cout<<"1: Ordena los pacientes por consumo calorico ascendente."<<endl;
cout<<"2: Ordena los pacientes por orden alfabetico."<<endl;
cout<<"3: Salir."<<endl;
cout<<"Seleccione el numero de una opcion a ejecutar: "<<endl;
cin>>sel;
cout<<endl;

while((sel<=0)||(sel>3)){
cout<<"Seleccione un digito correcto."<<endl;
cout<<"1: Ordena los pacientes por consumo calorico ascendente."<<endl;
cout<<"2: Ordena los pacientes por orden alfabetico."<<endl;
cout<<"3: Salir."<<endl;
cout<<"Seleccione el numero de una opcion a ejecutar: "<<endl;
cin>>sel;
cout<<endl;
}
if (sel == 1){
    cout<<"El ordenamiento ascendente de los pacientes por consumo es: "<<endl;
    ordenaporcalorias(s);
    seleccion(s);
}

if (sel == 2){
    cout<<"El ordenamiento por alfabeto es: "<<endl;
    ordenaporalfabeto(s);
    seleccion(s);
}
if (sel == 3){
    cout<<"Muchas gracias por usar Calorex! Vuelva pronto!"<<endl;
    cout<<"Pulsa cualquier tecla para cerrar la plataforma"<<endl;
}

}

int main()
{
    ifstream archivo(NOMBRE_EXCEL);
    string linea;
    char coma = ',';
    getline(archivo, linea);
    vector<vector<string>> vector_pacientes;

    while(getline(archivo, linea)){
        vector<string> datos_paciente;
        stringstream stream(linea);
        string paciente, sexo, peso, estatura, edad, ejercicio, calorias;
        int caloriasnum;

        getline(stream, paciente, coma);
        getline(stream, sexo, coma);
        getline(stream, peso, coma);
        getline(stream, estatura, coma);
        getline(stream, edad, coma);
        getline(stream, ejercicio, coma);
        datos_paciente={paciente, sexo, peso, estatura, edad, ejercicio};
        caloriasnum = consumocalorico(datos_paciente);
        calorias = to_string(caloriasnum);

        datos_paciente.push_back (calorias);
        vector_pacientes.push_back (datos_paciente);
    }
    cout<<"Bienvenid@ a la plataforma nutricional Calorex! Existen "<<vector_pacientes.size()<<" pacientes en la plataforma los cuales son: "<<endl;
    imprimir(vector_pacientes);
    seleccion(vector_pacientes);

    archivo.close();
    getch();
}
