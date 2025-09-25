#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
using namespace std;

struct Producto {
    char sku[10];       // 10 bytes
    char descripcion[20]; // 20 bytes
    float costoFijo;    // 4 bytes
}; // Tamaño total: 34 bytes
struct Reparacion {
    char cliente[15];
    char sku[10];
    int tipoProducto;
    float costoDirecto;
    float presupuestado;
};

void leerArchivoReparacion(Reparacion rep[]){
   ifstream archile("reparaciones.bin",ios::binary);
   Reparacion r;
   int i=0;
   while(!archile.eof()){
      archile.read((char *)&r,sizeof(Reparacion));
      rep[i]=r;
      i++;
   }
   archile.close();
}
void leerArchivoProducto(Producto pro[]){
   ifstream archile("productos.bin",ios::binary);
   Producto r;

   int i=0;
   while(!archile.eof()){
      archile.read((char *)&r,sizeof(Producto));
      pro[i]=r;
      i++;
   }
   archile.close();
}
int main() {


   return 0;
}
