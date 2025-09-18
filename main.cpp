// inicio del codigo (18/09/25)

#include <iostream>
#include <fstream>

using namespace std;

// Definicion de estructuras (18/09/25)

struct Productos {

  string sku;
  string descripcion;
  float costo_fijo;

}

struct Reparaciones {

  string cliente;
  int tipo_de_producto;
  string sku;
  float costo_fijo;
  float presupuestado;

}

// Funciones de ordenamiento y busqueda lineal (18/09/25)

void busqueda_lineal() {

}

void ordenamiento_ascendente() {

}

// Lectura de archivo de productos (18/09/25)

void lecturaProductos() { 

  ifstream archivoProductos;
  string texto;

  archivoProductos.open("productos.bin");

  if (archivoProductos.fail()) {
    cout << "No se pudo abrir el archivo de producos" << endl;
    exit(1);
  }
  
  while (!archivoProductos.eof()) {
    getline(archivoProductos,texto);
    cout << texto << endl;
  }

 archivoProductos.close();
}

//Lectura de archivo de reparaciones (19/09/25)

void lecturaReparaciones() {

  ifstream archivoReparaciones;
  string texto;

  archivoReparaciones.open("reparaciones.bin");

  if archivoReparaciones.fail(){
    cout << "No se pudo abrir el archivo de reparaciones" << endl;
    exit(1);
  }

  while (!archivoReparaciones.eof()) {

    getline(archivoReparaciones,texto);
    cout << texto << endl;
  }

  archivoReparaciones.close();
}



int main() {

  cout << "Hola Mundo" << endl;

  return 0;
}
