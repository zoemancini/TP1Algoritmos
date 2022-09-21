#include <iostream>
#include <fstream>
using namespace std;

const int cantidadproductos {5};

void listasuperan13000(string clientes[], string productos[], float pesoacumulado[][cantidadproductos], 
 int filasclientes) { //funcion para el punto 1
    cout << "Los productos que superan los 13000kg acumulados transportados, separados por cliente, son:" << endl;
    for (int i {0}; i < filasclientes; i++) {
        cout << clientes[i] << ": "; //muestra el nombre del cliente
        for (int j {0}; j < cantidadproductos; j++) {
            if (pesoacumulado[i][j] > 13000) { 
                cout << productos[j] << " "; //muestra los productos para los que el peso acumulado supera los 13000
            }
        }
        cout << endl;
    }
}

int clienteconmas13000(string clientes[], string productos[], float pesoacumulado[][cantidadproductos],
 int filasclientes) { //funcion para saber cual es el cliente con mas productos que superen 130000 para el punto 2
    int codigodelmayor {0};
    int mayorcantidadproductos {0};
    for (int i {0}; i < filasclientes; i++) {
        int contador {0};
        for (int j {0}; j < cantidadproductos; j++){
            if (pesoacumulado[i][j] > 13000) { 
                contador++;
            }
        }
        if (contador > mayorcantidadproductos) {
            mayorcantidadproductos = contador;
            codigodelmayor = i;
        }
    }
    return codigodelmayor;
}


void kmacumuladosmas13000 (string clientes[], string productos[], float kmacumulados[][cantidadproductos],
 int filasclientes, int clienteconmas13000, int orden[]) { //funcion para el punto 2
    cout << "El cliente con mas productos que superan los 13000kg acumulados es " << clientes[clienteconmas13000] 
    << "." << endl;
    cout << "Y la cantidad de kms acumulados por producto ordenados de forma ascendente es:" << endl;
    int n;
    int temp {0};
    do{
        n =0;
        for(int i {1} ;i < cantidadproductos; i++){
            if(kmacumulados[clienteconmas13000][i-1] > kmacumulados[clienteconmas13000][i]){
                temp = kmacumulados[clienteconmas13000][i-1];
                kmacumulados[clienteconmas13000][i-1] = kmacumulados[clienteconmas13000][i];
                kmacumulados[clienteconmas13000][i] = temp;
                n++;

                temp = orden[i-1];
                orden[i-1] = orden[i];
                orden[i] = temp;
            }
        }
    }
    while(n!=0);
    for(int i{0};i < cantidadproductos;i++){
        cout << productos[orden[i]] << ": "<< kmacumulados[clienteconmas13000][i] << " km"<<endl;
    }
}

void cantidadentregasmaskg(string productos[], int orden[], int cantidadentregas[]) { //funcion para el punto 3
    cout << "La cantidad de entregas realizadas para productos " << productos[orden[cantidadproductos-1]] << 
    " fueron : " << cantidadentregas[orden[cantidadproductos-1]] << endl;
}


int main() {
    //inicializacion de variables
    const int cantidadclientes {8};
    string clientes[cantidadclientes]; //vector con los nombres de los clientes
    string productos[cantidadproductos]; //vector con los nombres de los productos
    float pesoacumulado[cantidadclientes][cantidadproductos]{}; //vector con el peso acumulado por cliente y producto
    float kmacumulados[cantidadclientes][cantidadproductos]{}; //vector con el peso acumulado por cliente y producto
    int orden[cantidadproductos]{0,1,2,3,4};
    int cantidadentregas[cantidadproductos]{};

    ifstream archinombres;
    archinombres.open("NombresTP.txt");
    if (!archinombres) {  //control al abrir el archivo de nombres
        cout << "Error al abrir el archivo de clientes y productos." << endl;
        return 1;
    }
    for (int i {0}; i < cantidadclientes; i++) { //declaracion del vector clientes
        archinombres >> clientes[i];
    }
    for (int i {0}; i < cantidadproductos; i++) { //declaracion del vector productos
        archinombres >> productos[i];
    }
    archinombres.close();

    ifstream archidatos;
    archidatos.open("DatosTP.txt");
    if (!archidatos) {  //control al abrir el archivo de datos
        cout << "Error al abrir el archivo de datos registrados." << endl;
        return 1;
    }
    int codigocliente;
    int codigoproducto;
    float pesotransportado;
    float kmrecorridos;
    while (archidatos >> codigocliente >> codigoproducto >> pesotransportado >> kmrecorridos) {
        pesoacumulado[codigocliente][codigoproducto] += pesotransportado; 
        //declaracion del vector de peso acumulado por cliente y producto
        kmacumulados[codigocliente][codigoproducto] += kmrecorridos;
        //declaracion del vector de km acumulado por cliente y producto
        cantidadentregas[codigoproducto]++;
    }
    archidatos.close();



    listasuperan13000(clientes, productos, pesoacumulado, cantidadclientes); //Punto 1
    cout << endl;

    kmacumuladosmas13000(clientes, productos, kmacumulados, cantidadclientes,
     clienteconmas13000(clientes, productos, pesoacumulado, cantidadclientes), orden); //Punto 2
    
    cout << endl;

    cantidadentregasmaskg(productos, orden, cantidadentregas); //Punto 3
    return 0;
}