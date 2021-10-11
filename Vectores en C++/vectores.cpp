#include "vectores.h"
#include <string>
#include <fstream>

/* Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores(){
    cout << "El módulo vectores fue cargado correctamente" << endl;
} */


//Ejercicio 1
bool divide(vector<int> v, int a){
	int suma = 0;
	for (int i = 0; i < v.size(); i++){
	    if (v[i] % a == 0){
	        suma = suma + 1;
	    }
	} return suma == v.size();
}

//Ejercicio 2
int mayor(vector<int> v){
	int elMayor = v[0];
	for (int i = 0; i < v.size(); i++){
	    if (v[i] >= elMayor){
	       elMayor = v[i]; 
	    }
	}
	return elMayor;
}

//Ejercicio 3
vector<int> reverso(vector<int> v){
	vector<int> w;
	int elem;
	
	for (int i = (v.size() - 1); i >= 0; i--){
	    elem = v[i];
	    w.push_back(elem);
	}
	return w;
}

//Ejercicio 4
vector<int> rotar(vector<int> v, int k){
	vector<int> result;
	
	for (int i = k; i < v.size(); i++){
	    result.push_back(v[i]);
	}
	
	for (int i = 0; i < k; i++){
	    result.push_back(v[i]);
	}
	
	return result;
}

//Ejercicio 5
bool creciente(vector<int> v){
    int s = 1;
    int elAnterior = v[0];
    for (int i = 1; i < v.size(); i++){
        if (v[i] > elAnterior){
            s = s + 1;
            elAnterior = v[i];
        }
    }
    return s == v.size();
}

bool decreciente(vector<int> v){
    int s = 1;
    int elAnterior = v[0];
    
    for (int i = 1; i < v.size(); i++){
        if (v[i] <= elAnterior){
            s = s + 1;
            elAnterior = v[i];
        }
    }
    return s == v.size();
}

bool estaOrdenado(vector<int> v){
    return (creciente(v) || decreciente(v));
}
    

//Ejercicio 6
bool esPrimo(int n){
    int s = 0;
    for (int i = 2; i < n; i++){
        if (n % i == 0){
            s = s + 1;
        }
    }
    return s == 0;
}


vector<int> factoresPrimos(int n){
    vector<int> v;
    
	for (int i = 2; i < n; i++){
	    if (esPrimo(i) && n % i == 0){
	        v.push_back(i);
	    }
	}
	
	return v;
}

//Ejercicio 7
void mostrarVector(vector<int> v){
	cout << "[";
	for (int i = 0; i < v.size(); i++){
	    if (i < v.size() - 1){
	        cout << v[i] << ", ";
	   } else if (i == v.size() - 1) {
	       cout << v[i] << "]";
	   }
	}
}

//Ejercicio 8
vector<int> leerVector(string nombreArchivo){
    vector<int> v;
    int valor;
    ifstream fin;
    fin.open(nombreArchivo, ios::in);
    
    while (!fin.eof()){
        fin >> valor;
        v.push_back(valor);
    }
    
    fin.close();
    return v;
}

//Ejercicio 9
void guardarVector(vector<int> v, string nombreArchivo){
    ofstream fout;
    fout.open(nombreArchivo);
    for (int i = 0; i < v.size(); i++){
        fout << v[i] << " ";
    }
    fout.close();
}

//Ejercicio 10
int sumaHasta(vector<int> v, int k){
    int s1 = 0;
    for (int i = 0; i <= k; i++){
        s1 = s1 + v[i];
    }
    return s1;
}

int sumaDesde(vector<int> v, int k){
    int s2 = 0;
    for (int i = v.size() - 1; i > k; i--){
        s2 = s2 + v[i];
    }
    return s2;
}

int elementoMedio(vector<int> v){
    int i, s1, s2, elem;
    
    for(i = 0; i < v.size(); i++){
        s1 = sumaHasta(v,i);
        s2 = sumaDesde(v,i);
        
        if (s1 > s2){
            elem = v[i];
            i = v.size() + 1;
        }
    }
    cout << "El elemento medio es: " << elem << endl;
    return elem;
}

// Ejercicio 11
void cantApariciones(string nombreArchivo){

}

//Ejercicio 12
int cantidadAparicionesDePalabra(string nombreArchivo, string palabra){
    
}

//Ejercicio 13

















