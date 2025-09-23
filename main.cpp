// inicio del codigo (18/09/25)

#include <iostream>
#include <fstream>

using namespace std;

// Definicion de estructuras (18/09/25)

struct Productos {

  string sku;
  string descripcion;
  float costo_fijo;

  Productos *siguiente = nullptr;

};

void insertarProductos (Productos *&lista) {


}

struct Reparaciones {

  string cliente;
  int tipo_de_producto;
  string sku;
  float costo_fijo;
  float presupuestado;

  Reparaciones *siguiente = nullptr;

};

void insertarReparaciones (Reparaciones *&lista) {


}

// Funciones de ordenamiento y busqueda lineal (18/09/25)

void busqueda_lineal() {

}

template <typename T>
void ordenamiento_ascendente(T vec[], int dim, int (*criterio)(T, T)) {
    int i, j;
    T temp;

    for (i = 1; i < dim; i++) {
        temp = vec[i];
        j = i - 1;

        while (j >= 0 && criterio(vec[j], temp) > 0) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = temp;
    }
}

int criterio_reparaciones(Reparaciones a, Reparaciones b) {
    if (a.cliente > b.cliente) 
      return 1;
    else if (a.cliente < b.cliente)
      return -1;

    if (a.tipo_de_producto > b.tipo_de_producto) 
      return 1;
    else if (a.tipo_de_producto < b.tipo_de_producto)
      return -1;

    if (a.sku > b.sku)
      return 1;
    else if (a.sku < b.sku)
      return -1;

    return 0;
}

// Lectura de archivo de productos (18/09/25)

void lecturaProductos() { 

  ifstream archivoProductos;
  string texto;

  archivoProductos.open("productos.bin");

  if (!archivoProductos) {
    cout << "No se pudo abrir correctamente el archivo de Productos" << endl;
    exit(1);
  }

 /* si quisiera escribir el archivo que leí: 
  
 getline (archivoProductos, texto);

 cout << texto << endl;

 */
  
 archivoProductos.close();
  
}

//Lectura de archivo de reparaciones (18/09/25)

void lecturaReparaciones() {

  ifstream archivoReparaciones;
  string texto;

  archivoReparaciones.open("reparaciones.bin");

  if(!archivoReparaciones) {
    cout << "No se pudo abrir correctamente el archivo de Reparaciones" << endl;
    exit(1);
  }
  
  /* si quisiera escribir el archivo que leí: 

  getline(archivoReparaciones, texto);

  cout << texto << endl;

  */

  archivoReparaciones.close();

}

// Función Descripción del Tipo de Producto (21/09/25)

void descripcionTipo() {

    Reparaciones t;

    switch (t.tipo_producto) {

        case 0:
            cout << "Electrónico";
            break;
        case 1:
            cout << "Mecánico";
            break;
        case 2:
            cout << "Mecatrónico";
            break;

        default: cout << "Desconocido";

        }
    }

int main() {

  lecturaProductos();
  lecturaReparaciones();

  descripcionTipo();

  // Carga de Clientes y Comienzo del Main (22/09/25)

  const string cliente1 = "Nyota Uhura";
  const string cliente2 = "Don Ramón";
  const string cliente3 = "Taller el Trio";

  const int dim {7};

  string datos[dim] = {"Cliente", "Tipo Producto", "SKU", "Producto", "Costo Fijo", "Costo Directo", "Presupuestado"};

  while (cin) {

      Reparaciones c;

      cout << "Ingrese cliente a consultar: ";
      cin >> c.cliente;

      while (c.cliente.length() > 15) {

          cout << "El largo del nombre no puede ser mas de 15 caracteres!" << endl;
          cout << "Ingrese nuevamente el cliente a consultar: ";
          cin >> c.cliente;
      }

  }
    
  

  return 0;
}
