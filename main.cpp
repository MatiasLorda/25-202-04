// inicio del codigo (18/09/25)

#include <iostream>
#include <fstream>

using namespace std;


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


void busqueda_lineal() {

}

void ordenamiento_ascendente() {

}


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
