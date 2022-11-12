#include <vector>

using namespace std;
class Grafo
{
public:
    Grafo();
    Grafo(int nodos);
    vector<vector<int>> kruskal();

private:
    const int INF = numeric_limits<int>::max();
    int cn;                  //cantidad de nodos
    vector<vector<int>> ady; //matriz de adyacencia
};
//**** Finaliza Archivo grafo.h *****//

//**** Comienza Archivo grafo.cpp *****//
Grafo::Grafo()
{
}

Grafo::Grafo(int nodos)
{
    this->cn = nodos;
    this->ady = vector<vector<int>>(cn);

    for (int i = 0; i < cn; i++)
        ady[i] = vector<int>(cn, INF);
}
// Declaraciones en el archivo .h
int cn; //cantidad de nodos
vector< vector<int> > ady; //matriz de adyacencia
