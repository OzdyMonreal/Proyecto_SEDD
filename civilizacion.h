#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>

using namespace std;

class Civilizacion {
   string nombre;
   int ubicacionX;
   int ubicacionY;
   float puntuacion;

public:
   Civilizacion();
   Civilizacion(const string &nombre, int ubicacionX, int ubicacionY, float puntuacion);

   void setNombre(const string &nombre);
   string getNombre();
   void setUbicacionX(int ubicacionX);
   int getUbicacionX();
   void setUbicacionY(int ubicacionY);
   int getUbicacionY();
   void setPuntuacion(float puntuacion);
   float getPuntuacion();

   friend ostream& operator<<(ostream &out, const Civilizacion &c) {
    cout << left;
    out << setw(25) << c.nombre;
    out << setw(25) << c.ubicacionX;
    out << setw(25) << c.ubicacionY;
    out << setw(6) << c.puntuacion;
    out << endl;

    return out;
   }

  
   friend istream& operator>>(istream &in, Civilizacion &c) {
    cout << "Nombre: ";
    getline(cin, c.nombre); cin.sync();

    cout << "Ubicacion X: ";
    cin >> c.ubicacionX; cin.sync();

    cout << "Ubicacion Y: ";
    cin >> c.ubicacionY; cin.sync();

    cout << "Puntuacion: ";
    cin >> c.puntuacion; cin.sync();
    cout << endl;

    return in;
   }

   bool operator==(const Civilizacion& c)
   {
      return nombre == c.nombre;
   }
   bool operator==(const Civilizacion& c) const
   {
      return nombre == c.nombre;
   }

   bool operator<(const Civilizacion& c)
   {
      return nombre < c.nombre;
   }
   bool operator<(const Civilizacion& c) const
   {
      return nombre < c.nombre;
   }
   
};


#endif