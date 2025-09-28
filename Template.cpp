#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

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

//auto es para decirle a la funcion que utilize los return del comparador,aprendido con geminis.esta hecho de esta manera para implementar templates con los vector<>
//tambien utilazom bibliografia para comprender como hacer la funcion ya que esta entra en cada condicion si es necesario y se la da a la funcion sort para que determine como ordenar el array dinamico
//antes la funcion que ordenaba era super grande y ahora es una sola linea,por lo cual crear un comparador con templates fue esencial para acortarlo, si utilizacemos un 
//.h que guarde la funcion comparador seria incluso mas legible porque solo seria una linea el ordenamiento
template<typename t> auto comparador(){
   return[](const t& a, const t& b) -> bool {
                string clientea=string(a.cliente);   //los paso a string porque char no me los compara bien
                string clienteb=string(b.cliente);
                string skua=string(a.sku);
                string skub=string(b.sku);
   /*
                if (clientea != clienteb) {
                    return a.cliente > b.cliente;
                }

   */
                if(clientea!=clienteb){
                   return clientea<clienteb;
                }
                if (a.tipoProducto != b.tipoProducto) {
                    return a.tipoProducto < b.tipoProducto;
                }


                return skua < skub;
   };

}


 void ordenarVector(vector<Reparacion>& rep) {
       sort(rep.begin(), rep.end(),comparador<Reparacion>());
 }

int main() {
   vector<Reparacion> reparaciones=leerArchivoReparacion();
   vector<Producto>productos=leerArchivoProducto();
   ordenarVector(reparaciones);
   leerVectorReparacion(reparaciones);

   return 0;
}
