#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;


#pragma pack(push, 1)
struct Producto {
    char sku[10];       // 10 bytes
    char descripcion[20]; // 20 bytes
    float costoFijo;    // 4 bytes
}; // Tamaño total: 34 bytes
#pragma pack(pop)


#pragma pack(push, 1)
struct Reparacion {
   char cliente[15];
    int tipoProducto;
     char sku[10];
     float costoDirecto;
     float presupuestado;
};
#pragma pack(pop)
vector<Reparacion> leerArchivoReparacion(){
   ifstream archile("reparaciones.bin",ios::binary);
   Reparacion r;
   vector<Reparacion>rep;

   while(archile.read(reinterpret_cast<char *>(&r), sizeof(Reparacion))){
      archile.read((char *)&r,sizeof(Reparacion));
      rep.push_back(r);
   }
   archile.close();
   return rep;
}

vector<Producto> leerArchivoProducto(){
   ifstream archile("productos.bin",ios::binary);
   Producto r;
   vector<Producto>productos;
   int i=0;
   while(archile.read(reinterpret_cast<char *>(&r), sizeof(Producto))){
      archile.read((char *)&r,sizeof(Producto));
      productos.push_back(r);
      i++;
   }
   archile.close();
   return productos;
}

 void leerVectorReparacion(vector<Reparacion>reparaciones){
    for(Reparacion rep : reparaciones){
             cout<<"Nombre:"<<rep.cliente<<" TipoProd: "<<rep.tipoProducto<<" Sku: "<<rep.sku<<" Cost Dire "<<rep.costoDirecto<<" Presu: "<<rep.presupuestado;
             cout<<"\n";
          };
 }
 void leerVectorProducto(vector<Producto>productos){
    for(Producto pro : productos){
             cout<<"Nombre:"<<pro.sku;
             cout<<"\n";
          };
 }
int main() {
   vector<Reparacion> reparaciones=leerArchivoReparacion();
   vector<Producto>productos=leerArchivoProducto();
   leerVectorReparacion(reparaciones);
   return 0;
}
