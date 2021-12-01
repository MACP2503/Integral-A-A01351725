#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <random>
#include <math.h>
#include <algorithm>
#include "dlist.h"
#include "heap.h"
#define NOMBRE_EXCEL "Tabla_Harris-Benedict.csv"
#define HORAS "horas.txt"
#define DIAS "dias.txt"

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

void imprimirlista(){
    cout<<"Los horarios de citas agendadas son: "<<endl<<endl;
    string line;
    vector<string> di, ho;
    char coma = ',';
    ifstream file (HORAS);
    ifstream file2 (DIAS);
    int i = 0;

    while(!file.eof()){
    getline(file,line,coma);
    ho.push_back(line);
    }
    file.close();

    while (!file2.eof()){
    getline(file2,line,coma);
    di.push_back(line);
    }
    file2.close();

    while(i<=di.size()){
    if(i<di.size()){
      cout<<"Cita "<<i+1<<": ";
    }
    else{
        break;
    }
    double h, d = 0;
    int h1, d1 = 0;
    h=stoi(ho[i]);
    d=stoi(di[i]);
    h1 = (trunc(h)/100);
    d1 = (trunc(d)/100);
    h = h/100;
    h= (h-h1)*100;
    d = d/100;
    d= (d-d1)*100;

    cout<<"Hora: "<<h1<<":"<<h;
    if(h==0){
        cout<<0<<endl;
    }
    else{
        cout<<endl;
    }

    cout<<"Dia "<<d1<<" del mes numero "<<d<<endl<<endl;
    i++;
}

}

void lista(){
    string line;
    char coma = ',';
    ifstream file (HORAS);
    ifstream file2 (DIAS);
    DList<int> hora, dia;

    while(!file.eof()){
    getline(file,line,coma);
    hora.insertion(stoi(line));
    }
    file.close();

    while (!file2.eof()){
    getline(file2,line,coma);
    dia.insertion(stoi(line));
    }
    file2.close();

    int decision = 1;
    while(decision!=0){
    int dec;
    imprimirlista();
    cout<<"Que desea hacer?"<<endl;
    cout<<"1. Agregar Cita"<<endl;
    cout<<"2. Modificar Cita"<<endl;
    cout<<"3. Eliminar Cita"<<endl;
    cout<<"4. Salir del menu de citas"<<endl;
    cin>>dec;
    while((dec<=0)||(dec>4)){
    cout<<"Digite un numero valido: "<<endl;
    cout<<"Que desea hacer?"<<endl;
    cout<<"1. Agregar Cita"<<endl;
    cout<<"2. Modificar Cita"<<endl;
    cout<<"3. Eliminar Cita"<<endl;
    cout<<"4. Salir del menu de citas"<<endl;
    cin>>dec;
    }
    if(dec==4){
        cout<<endl;
        break;
    }
    else if(dec==1){
        int horaingresada, minutosingresados, horamin;
        cout<<"Digita la hora en un numero del 1 al 24: ";
        cin>>horaingresada;
        while((horaingresada<=0)||(horaingresada>24)){
            cout<<"Digita la hora en un numero del 1 al 24: ";
            cin>>horaingresada;
        }
        cout<<"Digita los minutos dentro de la hora en un numero del 0 al 59: ";
        cin>>minutosingresados;
        while((minutosingresados<0)||(minutosingresados>59)){
        cout<<"Digita los minutos dentro de la hora en un numero del 0 al 59: ";
        cin>>minutosingresados;
        }
        horamin=(horaingresada*100)+minutosingresados;
        hora.insertion(horamin);

        int diaingresado, mesingresado, diames;
        cout<<"Digita el dia en un numero del 1 al 31: ";
        cin>>diaingresado;
        while((diaingresado<=0)||(diaingresado>31)){
            cout<<"Digita la hora en un numero del 1 al 31: ";
            cin>>diaingresado;
        }
        cout<<"Digita el mes en un numero del 1 al 12: ";
        cin>>mesingresado;
        while((mesingresado<=0)||(mesingresado>12)){
        cout<<"Digita el mes en un numero del 1 al 12: ";
        cin>>mesingresado;
        }
        diames=(diaingresado*100)+mesingresado;
        dia.insertion(diames);
    }
    else if(dec==2){
        int nocita;
        cout<<"Que numero de cita desea modificar: "<<endl;
        cin>>nocita;
        nocita=nocita-1;

        int horaingresada, minutosingresados, horamin;
        cout<<"Digita la hora en un numero del 1 al 24: ";
        cin>>horaingresada;
        while((horaingresada<=0)||(horaingresada>24)){
            cout<<"Digita la hora en un numero del 1 al 24: ";
            cin>>horaingresada;
        }
        cout<<"Digita los minutos dentro de la hora en un numero del 0 al 59: ";
        cin>>minutosingresados;
        while((minutosingresados<0)||(minutosingresados>59)){
        cout<<"Digita los minutos dentro de la hora en un numero del 0 al 59: ";
        cin>>minutosingresados;
        }
        horamin=(horaingresada*100)+minutosingresados;
        hora.update(nocita, horamin);

        int diaingresado, mesingresado, diames;
        cout<<"Digita el dia en un numero del 1 al 31: ";
        cin>>diaingresado;
        while((diaingresado<=0)||(diaingresado>31)){
            cout<<"Digita la hora en un numero del 1 al 31: ";
            cin>>diaingresado;
        }
        cout<<"Digita el mes en un numero del 1 al 12: ";
        cin>>mesingresado;
        while((mesingresado<=0)||(mesingresado>12)){
        cout<<"Digita el mes en un numero del 1 al 12: ";
        cin>>mesingresado;
        }
        diames=(diaingresado*100)+mesingresado;
        dia.update(nocita, diames);
    }
    else if(dec==3){
        int nocita;
        cout<<"Que numero de cita desea eliminar: "<<endl;
        cin>>nocita;
        nocita=nocita-1;
        dia.deleteAt(nocita);
        hora.deleteAt(nocita);
    }

    ofstream file5(HORAS);
    file5<<hora.toStringForward();
    file5.close();

    ofstream file4(DIAS);
    file4<<dia.toStringForward();
    file4.close();
    }
}
void presupuesto(){
int pacientes;
cout<<"Cuántos pacientes espera manejar en la semana: ";
cin>>pacientes;

Heap<int> heap(pacientes);
int i=0;
int costot = 0;
int min = 0;
int max = 0; 
int costo = 0;
float presu;
cout<<"¿Cuál es el rango de cobro por consulta?"<<endl;
cout<<"Valor Mínimo: "<<endl;
cin>>min;
cout<<"Valor Máximo: "<<endl;
cin>>max;
while(i<pacientes){
  costo = rand()%(max-min + 1) + min;
  heap.push(costo);
  costot=costot+costo;
  i++;
}
if(pacientes<=0){
  cout<<"No existen citas agendadas."<<endl;
}
else{
  cout<<"Pacientes del 1 al "<<i<<": ";
  string impr;
  impr=heap.toString();
  cout<<impr<<endl;
}
cout<<"Ganancias totales: "<<costot<<endl;
}

void imprimir(vector<vector<string>> vector_final){
int i;
for(i=0;i<vector_final.size();i++){
    cout<<"----------------------------------------------------"<<endl;
    string a;
    cout<<"Nombre del paciente: "<<vector_final[i][0]<<endl;
    cout<<"Sexo: "<<vector_final[i][1]<<endl;
    cout<<"Peso en kilogramos: "<<vector_final[i][2]<<endl;
    cout<<"Estatura en cm: "<<vector_final[i][3]<<endl;
    cout<<"Edad: "<<vector_final[i][4]<<endl;
    cout<<"Cantidad de ejercicio realizado: ";
    a=vector_final[i][5][0];

    if (a=="1"){
    cout<<"Muy Poca o inexistente"<<endl;
    }

    else if (a=="2"){
    cout<<"Ligera"<<endl;
    }

    else if (a=="3"){
    cout<<"Moderada"<<endl;
    }

    else if (a=="4"){
    cout<<"Alta"<<endl;
    }

    else if (a=="5"){
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
cout<<"3: Agenda citas en la lista."<<endl;
cout<<"4: Presupuestos."<<endl;
cout<<"5: Salir."<<endl;
cout<<"Seleccione el numero de una opcion a ejecutar: "<<endl;
cin>>sel;
cout<<endl;

while((sel<=0)||(sel>5)){
cout<<"Seleccione un digito correcto."<<endl;
cout<<"1: Ordena los pacientes por consumo calorico ascendente."<<endl;
cout<<"2: Ordena los pacientes por orden alfabetico."<<endl;
cout<<"3: Agenda citas en la lista."<<endl;
cout<<"4: Presupuestos."<<endl;
cout<<"5: Salir."<<endl;
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
    lista();
    seleccion(s);
}

if (sel == 4){
    presupuesto();
    seleccion(s);
}

if (sel == 5){
    cout<<"Muchas gracias por usar Calorex! Vuelva pronto!"<<endl;
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
    archivo.close();
    seleccion(vector_pacientes);
}
