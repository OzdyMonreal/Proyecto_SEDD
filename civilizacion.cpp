#include "civilizacion.h"
#include <algorithm>

Civilizacion::Civilizacion()
{
   
}

Civilizacion::Civilizacion(const string &_nombre, int _ubicacionX, int _ubicacionY, float _puntuacion)
{
   this -> nombre = _nombre;
   this -> ubicacionX = _ubicacionX;
   this -> ubicacionY = _ubicacionY;
   this -> puntuacion = _puntuacion;
}

void Civilizacion::setNombre(const string &v)
{
  nombre = v;
}

string Civilizacion::getNombre()
{
  return nombre;
}

void Civilizacion::setUbicacionX(int v)
{
  ubicacionX = v;
}

int Civilizacion::getUbicacionX() {
  return ubicacionX;
}

void Civilizacion::setUbicacionY(int v) {
  ubicacionY = v;
}

int Civilizacion::getUbicacionY() {
  return ubicacionY;
}

void Civilizacion::setPuntuacion(float v) {
  puntuacion = v;
}

float Civilizacion::getPuntuacion() {
  return puntuacion;
}
