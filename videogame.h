#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <algorithm>
#include <vector>

class VideoGame
{
   vector<Civilizacion> civilizaciones;
   string nombreUsuario;

public:
   VideoGame();
   void agregarUsuario(const string &ns);
   void agregarFinal(const Civilizacion &c);
   void resumen();
   size_t total();
   void insertar(const Civilizacion &c, size_t pos);
   void primera();
   void ultima();
   void inicializar(const Civilizacion &c, size_t n);
   void eliminar(const Civilizacion &c);
   int buscarEl(const Civilizacion &c);
   void ordenarNombre(); 
   void ordenarUbicacionX();
   void ordenarUbicacionY();
   void ordenarPuntuacion();
   Civilizacion* buscar(const Civilizacion &c);
   void modificarNombre(const Civilizacion &c);
   void modificarUbicacionX(const Civilizacion &c);
   void modificarUbicacionY(const Civilizacion &c);
   void modificarPuntuacion(const Civilizacion &c);

   friend VideoGame& operator<<(VideoGame &v, const Civilizacion &c) {
    v.agregarFinal(c);

    return v;
  }
};

#endif