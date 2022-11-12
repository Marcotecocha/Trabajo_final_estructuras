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
    int cn;                 
    vector<vector<int>> ady; 
};

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

int cn; 
vector< vector<int> > ady; 
