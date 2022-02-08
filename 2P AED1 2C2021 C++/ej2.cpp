#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

// DEFINICIONES DE TIPO
typedef pair<int, int> posicion;
typedef int altura;
typedef int poblacion;
typedef pair<altura, poblacion> zona;
typedef vector<vector<zona > > mapa;

int crecimientoPoblacional(mapa m1, mapa m2, posicion p){
    return m2[p.first][p.second].second - m1[p.first][p.second].second;
}

bool menorCrecimientoPoblacional(mapa m1, mapa m2, posicion p){
    bool res = true;
    for (int i = 0; i < m1.size(); i++){
        for (int j = 0; j < m1[0].size(); j++){
            posicion q = make_pair(i,j);
            
            if (crecimientoPoblacional(m1,m2,p) > crecimientoPoblacional(m1,m2,q)){
                res = false;
            }
            
        }
    }

    return res;
}

void swapPosicion(vector<posicion> &s, int i, int j){
    posicion aux = s[i];
    s[i] = s[j];
    s[j] = aux;

}

void ordenaPorCantCarpinchos(mapa m2, vector<posicion> &s){
    for (int i = 0; i < s.size(); i++){
        for (int j = i; j < s.size(); j++){
            if (m2[s[i].first][s[i].second].second > m2[s[j].first][s[j].second].second){
                swapPosicion(s,i,j);
            }
        }
    }
    
}

vector<posicion> bajaNatalidad(mapa m1, mapa m2) {
    int filas = m1.size();
    int columnas = m1[0].size();
    vector<posicion> res;

    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            posicion posActual = make_pair(i,j);
            if (menorCrecimientoPoblacional(m1,m2,posActual)){
                res.push_back(posActual);
            }
        }
    }

    ordenaPorCantCarpinchos(m2, res);
    return res;
    
}



int main() {
    /* No hace falta modificar el main */

    // El mapa 1
    int f;
    cin >> f;
    int c;
    cin >> c;
    mapa m;
    char aux;
    int alt;
    int pob;
    for (int i = 0; i < f; i++) {
        vector<zona> fila;
        for (int j = 0; j < c; j++) {
            cin >> aux;
            cin >> alt;
            cin >> aux;
            cin >> pob;
            cin >> aux;
            fila.push_back(make_pair(alt, pob));
        }

        m.push_back(fila);
    }

    // El mapa 2
    int f2;
    cin >> f2;
    int c2;
    cin >> c2;
    mapa m2;
    char aux2;
    int alt2;
    int pob2;
    for (int i = 0; i < f2; i++) {
        vector<zona> fila2;
        for (int j = 0; j < c2; j++) {
            cin >> aux2;
            cin >> alt2;
            cin >> aux2;
            cin >> pob2;
            cin >> aux2;
            fila2.push_back(make_pair(alt2, pob2));
        }

        m2.push_back(fila2);
    }

    // Invoco la función
    vector<posicion> pos = bajaNatalidad(m, m2);

    // Ordeno el vector
   // Deja de ser necesario porque ahora va ordenado de acuerdo a especificación std::sort(pos.begin(), pos.end());

    // Imprimo la salida
    for (int i = 0; i < pos.size(); i++) {
        cout << "(" << pos[i].first << "," << pos[i].second << ") ";
    }

    return 0;
}
