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


int diferenciaAlturas(mapa m, mapa m0){
    int s, s0 = 0; //s es la suma de alturas de m, y s0 es la de m0
    for (int i = 0; i < m.size(); i++){
        for (int j = 0; j < m[0].size(); j++){
            s += m[i][j].first;
            s0 += m0[i][j].first;
        }
    }

    int diferencia = s-s0;
    return diferencia;
}

int division(int dividendo, int divisor){
	int cociente = 0;
	while (dividendo >= divisor){
		dividendo = dividendo - divisor;
		cociente++;
	}
	return cociente;
}

int promedioVecinos(mapa m, vector<posicion> vecinos){
    int suma = 0;
    for (int i = 0; i < vecinos.size(); i++){
        suma = suma + m[vecinos[i].first][vecinos[i].second].first;
        
    }

    int promedio = suma / vecinos.size();
    
    return promedio;
}


int rellenarValles(mapa &m) {
    mapa m0 = m;
    
    
    for (int i = 0; i < m.size(); i++){
        for (int j = 0; j < m[0].size(); j++){
            
            posicion p = make_pair(i,j);
            vector<posicion> vecinos = getVecinos(m0,p); 
            
            if (esValle(m0,p)){
                m[i][j].first = promedioVecinos(m0, vecinos);
            } 
            
        }
    }
    
    
    return diferenciaAlturas(m,m0);
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

    // Invoco la función
    int res = rellenarValles(m);

    // Imprimo la salida
    cout << res << endl;
    cout << m.size() << endl;
    cout << m[0].size() << endl;
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size();j++) {
            cout << "("<< m[i][j].first << "," << m[i][j].second << ") ";
        }
        cout << endl;
    }

    return 0;
}
