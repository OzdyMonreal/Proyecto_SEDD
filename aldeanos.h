#ifndef ALDEANOS_H
#define ALDEANOS_H

#include <iostream>
#include <iomanip>

using namespace std;

class Aldeano
{
public:
   Aldeano() {}
   Aldeano(const string &nombre, size_t edad, const string &genero, float salud): nombre(nombre), edad(edad), genero(genero), salud(salud) {}

   void setNombre(const string &nombre);
   string getNombre() const;

   void setEdad(size_t edad);
   size_t getEdad() const;

   void setGenero(const string &genero);
   string getGenero() const;

   void setSalud(float salud);
   float getSalud() const;
   

   friend ostream& operator<<(ostream &out, const Aldeano &a)
   {
      out << left;
      out << setw(25) << a.nombre;
      out << setw(25) << a.edad;
      out << setw(25) << a.genero;
      out << setw(15) << a.salud;

      return out;
   }

   bool operator<(const Aldeano &a) const
   {
      return nombre < a.getNombre();
   }

   bool operator==(const Aldeano& a)
   {
      return nombre == a.nombre;
   }
   bool operator==(const Aldeano& a) const
   {
      return nombre == a.nombre;
   }

private:
   string nombre;
   size_t edad;
   string genero;
   float salud;
};

#endif