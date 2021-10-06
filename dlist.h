#ifndef dlist_h
#define dlist_h
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* atras;
};

template <class T>
class DList{
  private:
  Nodo *inicio = nullptr;
  Nodo *actual = nullptr;
  Nodo *ultimo = nullptr;
  int size;

  public:
  string toStringForward() const;
  string toStringBackward() const;
  void insertion(int);
  int search (int);
  int getlarge();
  void update(int, int);
  void deleteAt(int);
  void removeFirst();
};

template <class T>
std::string DList<T>::toStringForward() const {
	std::stringstream aux;
  Nodo *p;
	p = inicio;
	while (p != 0) {
		aux << p->dato;
		if (p->siguiente != 0) {
			aux << ", ";
		}
		p = p->siguiente;
	}
	return aux.str();
}

template <class T>
std::string DList<T>::toStringBackward() const {
  std::stringstream aux;
  Nodo *p;
	p = ultimo;
	while (p != 0) {
		aux << p->dato;
		if (p->atras != 0) {
			aux << ", ";
		}
		p = p->atras;
	}
	return aux.str();
}

template <class T>

void DList<T>::insertion(int elemento){

    Nodo *nuevo = new Nodo;
    nuevo->dato=elemento;
    nuevo->siguiente=nullptr;
    nuevo->atras=nullptr;

    if (inicio == nullptr){
        inicio = nuevo;
        inicio->siguiente = NULL;
		    inicio->atras = NULL;
		    ultimo = inicio;
    }
    else{
       	ultimo->siguiente = nuevo;
		    nuevo->siguiente = NULL;
		    nuevo->atras = ultimo;
		    ultimo = nuevo;
    }
    size++;
}

template <class T>
int DList<T>::search(int buscar){
    Nodo *aux=new Nodo();
    aux = inicio;
    int pos = 0;

    while(pos != buscar){
      aux = aux->siguiente;
      pos++;
    }
    return aux->dato;
}

template <class T>
void DList<T>::update(int posicion, int elemento){
int pos=0;
Nodo *actual=new Nodo();
    actual=inicio;
   while(actual->siguiente!=NULL) {
      if(pos==posicion) {
         actual->dato = elemento;
      }

      actual = actual->siguiente;
      pos++;
   }

  if(posicion==pos){
    actual->dato = elemento;
  }
}

template <class T>
void DList<T>::removeFirst(){
	T val;
  Nodo *p;

	p = inicio;
	val = p->dato;

	if (inicio == ultimo) {
		inicio = 0;
		ultimo = 0;
	} else {
		inicio = p->siguiente;
		p->siguiente->atras = 0;
	}
	delete p;
	size--;
}

template <class T>
void DList<T>::deleteAt(int n){
int pos=0;
T val;
Nodo *p=new Nodo();
if((n<0) || (n>= size)){
  cout<<"No se puede";
}

else if(n==0){
removeFirst();
}
else{
  p = inicio;
  while(pos != n){
    p = p->siguiente;
    pos++;
  }
  if(p->siguiente != 0){
    p->siguiente->atras= p->atras;
  }
val=p->dato;
p->atras->siguiente = p->siguiente;
size--;
delete p;
}

size--;
}

template <class T>
int DList<T>::getlarge(){
return size;
}

#endif



