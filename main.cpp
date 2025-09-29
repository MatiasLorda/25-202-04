// inicio del codigo (18/09/25)

#include <iostream>
#include <fstream>
#include <vector>
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
  string descripcion_tipo_producto; 
  string sku;
  float costo_fijo;
  float presupuestado;

  Reparaciones *siguiente = nullptr;

};

void insertarReparaciones (Reparaciones *&lista) {


}

// Funciones de ordenamiento y busqueda lineal (25/09/25)

template <typename T>
int busqueda_lineal(T vec[], int dim, T clave, int (*criterio)(T, T)) {
    for (int i = 0; i < dim; i++) {
        int cmp = criterio(vec[i], clave);

        if (cmp == 0) {
            return i; // Encontrado
        } else if (cmp > 0) {
            return -1; // Como está ordenado, ya no puede estar más adelante
        }
    }
    return -1; // No encontrado
}

int criterio_busqueda_cliente(Reparacion a, Reparacion b) {
    if (a.cliente == b.cliente)
      return 0;
    return (a.cliente > b.cliente) ? 1 : -1;
}

template <typename T>
void ordenamiento_ascendente(T vec[], int dim, int (*criterio)(T, T)) {
    int i, j;
    T aux;

    for (i = 1; i < dim; i++) {
        aux = vec[i];
        j = i - 1;

        while (j >= 0 && criterio(vec[j], aux) > 0) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = aux;
    }
}


// Criterio Reparaciones (25/09/25)

int criterio_reparaciones(Reparaciones a, Reparaciones b) {
    // 1) Comparar por cliente
    if (a.cliente != b.cliente)
        return a.cliente > b.cliente ? 1 : -1;

    // 2) Si cliente es igual, comparar tipo_de_producto
    if (a.tipo_de_producto != b.tipo_de_producto)
        return a.tipo_de_producto > b.tipo_de_producto ? 1 : -1;

    // 3) Si también son iguales, comparar SKU
    if (a.sku != b.sku)
        return a.sku > b.sku ? 1 : -1;

    return 0; // Son iguales
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

    switch (t.tipo_de_producto) {

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
