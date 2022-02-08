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



bool esVecino(posicion q, posicion p){
    bool res = false;

    if (q.first == p.first - 1 && q.second == p.second){
        res = true;
    }
    if (q.first == p.first && q.second == p.second - 1){
        res = true;
    }
    if (q.first == p.first && q.second == p.second + 1){
        res = true;
    }
    if (q.first == p.first + 1 && q.second == p.second){
        res = true;
    }

    return res;
}

vector<posicion> getVecinos(mapa m, posicion p){
    vector<posicion> res;
    for (int i = 0; i < m.size(); i++){
        for (int j = 0; j < m[0].size(); j++){
            posicion q = make_pair(i,j);
            if (esVecino(q,p)){
                res.push_back(q);
            }
        }
    }
    
    return res;
}


bool esValle(mapa m, posicion p){
    vector<posicion> vecinos = getVecinos(m,p);
    int altura = m[p.first][p.second].first;
    int count = 0;
    for (int i = 0; i < vecinos.size(); i++){
        if (m[vecinos[i].first][vecinos[i].second].first >= altura){
            count++;
        }
    }

    return count == vecinos.size();
}


int main() {
    /* No hace falta modificar el main */

    // La posición
    int pos1;
    cin >> pos1;
    int pos2;
    cin >> pos2;
    posicion p = make_pair(pos1, pos2);

    // El mapa
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

    // Evaluo si la posición es valle
    bool res = esValle(m, p);

    // Imprimo la salida
    cout << (res?"True":"False") << endl;

    return 0;
}
