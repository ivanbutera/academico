#include "generador.h"
#include "vectores.h"
#include <string>

using namespace std;

int main() {
    // funcion para generar automaticamente los archivos numericos
    // generarDatosLaboratorio(); // descomentar para crear automaticamente los archivos necesarios en la parte de entrada-salida. Una vez creados, se puede volver a comentar
    
    string nombreArchivo;
    cout << "Ingrese nombre de archivo: " << endl;
    cin >> nombreArchivo;
    
    cantApariciones(nombreArchivo);
    
    return 0;
    
}
