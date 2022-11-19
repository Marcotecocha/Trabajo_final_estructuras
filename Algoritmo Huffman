#include <iostream>
#include <stdlib.h>

using namespace std;

struct Parada {
    float distancia;
    string direccion;
    Parada *siguiente;
};

void ingresarParada (Parada *&lista, float distancia,string direccion){
    Parada *nueva = new Parada();
    nueva->distancia = distancia;
    nueva->direccion = direccion;
    Parada *aux1 = lista;
    Parada *aux2;
    if (lista == aux1){
        lista = nueva;
    }
    else {
        aux2->siguiente = nueva;
    }
    nueva->siguiente = aux1;
}

void mostrarcamino(Parada *&lista) {
    Parada *temporal = new Parada();
    temporal = lista;
     while (temporal != NULL){
        cout << temporal->distancia << " -> " << temporal->direccion << " -> ";
        temporal = temporal->siguiente;
    }
}

int main()
{
    Parada *lista = NULL;
    string calle;
    float km, rpta;
    
    do {
        cout << "Siguiente parada\n";
        cout << "distancia:"; cin >> km;
        cout << "parada: "; cin >> calle;
        ingresarParada(lista, km, calle);
        cout << "\n----\n";
        cin >> rpta;
    } while(rpta != 12);
    
    mostrarcamino(lista);
    
    return 0;
}
