#include <iostream>
#include <stdlib.h>
using namespace std;

struct matriz {
  int filas;
  int columnas;
  int **vec;
};

typedef struct matriz MATRIZ;

MATRIZ *crear (int m, int n){
    MATRIZ *nueva;
    nueva = (MATRIZ *) malloc (sizeof(MATRIZ));
    nueva -> filas = m;
    nueva -> columnas = n;
    nueva -> vec = (int**) malloc(m*sizeof(int*));
    for (int i = 0; i< m; i++){
        nueva->vec[i] = (int*) malloc(n*sizeof(int));
    }
    return nueva;
}

void liberar_memoria( MATRIZ *matriz) {
    for (int i = 0; i < matriz->filas; i++){
        free(matriz->vec[i]);
    }
    free(matriz);
}

float acceso_valor (MATRIZ *m_acceder, int i, int j){
    if (i<0 || i>= m_acceder->filas || j<0 || j>=m_acceder->columnas){
        printf("dato no ingresado, revisa los parametros");
        exit(1);
    }
    return  m_acceder->vec[i][j];
}
void asignar_valor (MATRIZ *m_asignar, int i, int j, int valor){
    if (i<0 || i>= m_asignar->filas || j<0 || j>=m_asignar->columnas){
        printf("dato no ingresado, revisa los parametros");
        exit(1);
    }
    m_asignar->vec[i][j] = valor;
}

void imprimir_matriz (MATRIZ *m_imprimir){
    for (int i = 0; i < m_imprimir->filas; i++){
        cout << endl << "[ ";
        for (int j = 0; j < m_imprimir->columnas; j++){
            printf ("(%.1d) ", m_imprimir->vec[i][j]);
        }
        cout << " ] \n";
    }
}



void colocarAntena (MATRIZ *superficie){
    asignar_valor(superficie,0, 3, 1);
    int i_aux;
    int j_aux;
    for (int i = 0; i < superficie->filas; i++){
        for (int j = 0; j < superficie->columnas; j++){
            if (superficie->vec[i][j] !=0){
               i_aux = i;
               j_aux = j;
            }
            else {
                if (j-j_aux ==5){
                    asignar_valor(superficie, i_aux, j, 1);
                }
            }
        }
        if (i-i_aux ==5){
            asignar_valor(superficie, i, j_aux, 1);
            colocarAntena(superficie);
        }

    }
}

int main()
{

    MATRIZ *territorio;
    
    territorio = crear (10,17);
    colocarAntena(territorio);
    imprimir_matriz(territorio);

    
    liberar_memoria(territorio);
    return 0;
}
