#include <iostream>
#include <fstream>
using namespace std;


const int cantidadproductos {5};

void listasuperan13000(string clientes[], string productos[], float pesoacumulado[][cantidadproductos],
 int filasclientes) {
    cout << "Los productos que superan los 13000kg acumulados transportados, separados por cliente, son:" << endl;
    for (int i = 0; i < filasclientes; i++) {  
        cout << clientes[i] << ": "; //muestra el nombre del cliente
        for (int j = 0; j < cantidadproductos; j++){
            if (pesoacumulado[i][j] > 13000) { 
                cout << productos[j] << " "; //muestra los productos para los que el peso acumulado supera los 13000
            }
        }
        cout << endl;
    }
}

int main() {
    const int cantidadclientes {8};
    string clientes[cantidadclientes]; //vector con los nombres de los clientes
    string productos[cantidadproductos]; //vector con los nombres de los productos

    ifstream archinombres;
    archinombres.open("NombresTP.txt");
    if (!archinombres) {  //control al abrir el archivo de nombres
        cout << "Error al abrir el archivo de clientes y productos." << endl;
        return 1;
    }
    for (int i = 0; i < cantidadclientes; i++) { //declaracion del vector clientes
        archinombres >> clientes[i];
    }
    for (int i = 0; i < cantidadproductos; i++) { //declaracion del vector productos
        archinombres >> productos[i];
    }
    archinombres.close();

    ifstream archidatos;
    archidatos.open("DatosTP.txt");
    if (!archidatos) {  //control al abrir el archivo de datos
        cout << "Error al abrir el archivo de datos registrados." << endl;
        return 1;
    }
    float pesoacumulado[cantidadclientes][cantidadproductos]{}; //vector con el peso acumulado por cliente y producto
    int codigocliente;
    int codigoproducto;
    float pesotransportado;
    float kmrecorridos;
    while (archidatos >> codigocliente >> codigoproducto >> pesotransportado >> kmrecorridos) {
        pesoacumulado[codigocliente][codigoproducto] += pesotransportado; 
        //declaracion del vector de peso acumulado por cliente y producto

    }
    archidatos.close();
    
    listasuperan13000(clientes, productos, pesoacumulado, cantidadclientes); //Punto 1
    return 0;
}