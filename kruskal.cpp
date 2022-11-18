#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <string.h> // memset
using namespace std;
class Arista
{
int vertice1, vertice2, peso;
public:
Arista(int v1, int v2, int peso) {
vertice1 = v1;
vertice2 = v2;
this->peso = peso;
}
int obtenerVertice1() {
return vertice1;
}
int obtenerVertice2() {
return vertice2;
}
int obtenerPeso() {
return peso;
}
// sobrescribir operador "<"
bool operator < (const Arista& arista2) const
{
return (peso < arista2.peso);
}
};  

class Grafo
{
int V; // número de vértices
vector<Arista> aristas; // vector de aristas
public:
Grafo(int V)
{
this->V = V;
}
// funcion que adiciona una arista
void adicionarArista(int v1, int v2, int peso)
{
Arista arista(v1, v2, peso);
aristas.push_back(arista);
}
// funcion que busca o subconjunto de um elemento "i"
int buscar(int subset[], int i)
{
if(subset[i] == -1)
return i;
return buscar(subset, subset[i]);
}
// funcion para unir dos subconjuntos en un único subconjunto
void unir(int subset[], int v1, int v2)
{
int v1_set = buscar(subset, v1);
int v2_set = buscar(subset, v2);
subset[v1_set] = v2_set;
}

/// algoritmo de Kruskal
void kruskal()
{
vector<Arista> arvore;
int size_aristas = aristas.size();
// ordena as aristas pelo menor peso
sort(aristas.begin(), aristas.end());
// separa memória para crear "V" subconjuntos
int * subset = new int[V];
// inicializa todos los subconjuntos como conjuntos de un único elemento
memset(subset, -1, sizeof(int) * V);
for(int i = 0; i < size_aristas; i++)
{
int v1 = buscar(subset, aristas[i].obtenerVertice1());
int v2 = buscar(subset, aristas[i].obtenerVertice2());
if(v1 != v2)
{
// si son diferentes éd porque NO forma ciclo, inserta en vetor
arvore.push_back(aristas[i]);
unir(subset, v1, v2); // faz a union
}
}
int size_arbol = arvore.size();
// muestra las aristas selecionadas con sus respectivos pesos
for(int i = 0; i < size_arbol; i++)
{
char v1 = 'A' + arvore[i].obtenerVertice1();
char v2 = 'A' + arvore[i].obtenerVertice2();
cout << "(" << v1 << ", " << v2 << ") = " << arvore[i].obtenerPeso() << endl;
}
}
};

int main(int argc, char *argv[])
{
Grafo g(7); // grafo
// adiciona las aristas
g.adicionarArista(0, 1, 7);
g.adicionarArista(0, 3, 5);
g.adicionarArista(1, 2, 8);
g.adicionarArista(1, 3, 9);
g.adicionarArista(1, 4, 7);
g.adicionarArista(2, 4, 5);
g.adicionarArista(3, 4, 15);
g.adicionarArista(3, 5, 6);
g.adicionarArista(4, 5, 8);
g.adicionarArista(4, 6, 9);
g.adicionarArista(5, 6, 11);
g.kruskal(); //  algoritmo de Kruskal
return 0;
}
