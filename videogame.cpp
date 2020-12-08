#include "videogame.h"
#include <fstream>
#include <algorithm>

VideoGame::VideoGame()
{

}

void VideoGame::agregarFinal(const Civilizacion &c)
{
   civilizaciones.push_back(c);
}

void VideoGame::agregarUsuario(const string &ns)
{
   nombreUsuario = ns;
}

void VideoGame::resumen() {
   if (nombreUsuario != "") {
      cout << "Usuario: " << nombreUsuario << endl;
   } else {
      cout << "Usuario: No existe usuario" << endl;
   }
   cout << "N. elementos: " << total() << endl;
   cout << left;
   cout << setw(25) << "Nombre";
   cout << setw(25) << "Ubicacion X";
   cout << setw(25) << "Ubicacion Y";
   cout << setw(15) << "Puntuacion";
   cout << endl;
   for (size_t i = 0; i < total(); i++) {
      Civilizacion c = civilizaciones[i];

      cout << c;
   }
}

void VideoGame::insertar(const Civilizacion &c, size_t pos)
{
   civilizaciones.insert(civilizaciones.begin() + pos, c);
}

size_t VideoGame::total()
{
   return civilizaciones.size();
}

void VideoGame::inicializar(const Civilizacion &c, size_t n)
{
   civilizaciones = vector<Civilizacion>(n, c);
}

void VideoGame::primera()
{
   cout << civilizaciones.front();
}

void VideoGame::ultima()
{
   cout << civilizaciones.back();
}

void VideoGame::eliminar(const Civilizacion &c)
{
   int index = buscarEl(c);
   if (index != -999) {
      civilizaciones.erase(civilizaciones.begin() + index);
   }
}

void VideoGame::ordenarNombre()
{
   sort(civilizaciones.begin(), civilizaciones.end());
}
void VideoGame::ordenarUbicacionX()
{
   sort(civilizaciones.begin(), civilizaciones.end(),
   [](Civilizacion c1, Civilizacion c2){return c1.getUbicacionX() > c2.getUbicacionX();});
}
void VideoGame::ordenarUbicacionY()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getUbicacionY() > c2.getUbicacionY();});
}
void VideoGame::ordenarPuntuacion()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() > c2.getPuntuacion();});
}

Civilizacion* VideoGame::buscar(const Civilizacion &c)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if (it == civilizaciones.end()) {
        return nullptr;
    }
    else {
        return &(*it);
    }
}

void VideoGame::modificarNombre(const Civilizacion &c)
{
   string nombre;

   Civilizacion* civ = buscar(c);

   cout << "Nombre nuevo: ";
   getline(cin, nombre);
   civ->setNombre(nombre);
}


void VideoGame::modificarUbicacionX(const Civilizacion &c)
{
   int ubicacionX;

   Civilizacion* civ = buscar(c);

   cout << "Ubicacion en X nueva: ";
   cin >> ubicacionX;
   civ->setUbicacionX(ubicacionX);
}

void VideoGame::modificarUbicacionY(const Civilizacion &c)
{
   int ubicacionY;

   Civilizacion* civ = buscar(c);

   cout << "Ubicacion en Y nueva: ";
   cin >> ubicacionY;
   civ->setUbicacionY(ubicacionY);
}

void VideoGame::modificarPuntuacion(const Civilizacion &c) 
{
   float puntuacion;
   Civilizacion* civ = buscar(c);
   
   cout << "Puntuacion nueva: ";
   cin >> puntuacion;
   civ->setPuntuacion(puntuacion);
}

int VideoGame::buscarEl(const Civilizacion &c)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
   int index = distance(civilizaciones.begin(), it);
    if (it == civilizaciones.end()) {
        return -999;
    }
    else {
        return index;
    }
}