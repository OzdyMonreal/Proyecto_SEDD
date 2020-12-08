#include "civilizacion.h"
#include "aldeanos.h"
#include <algorithm>
#include <fstream>

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


void Civilizacion::agregarAldeanoFinal(const Aldeano &a)
{
    aldeanos.push_back(a);
}

void Civilizacion::agregarAldeanoInicio(const Aldeano &a)
{
    aldeanos.push_front(a);
}

void Civilizacion::mostrar()
{
    cout << left;
    cout << setw(25) << "Nombre";
    cout << setw(25) << "Edad";
    cout << setw(25) << "Genero";
    cout << setw(15) << "Salud";
    cout << endl;
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++) {
        cout << *it << endl;
    }
}

void Civilizacion::eliminarAldeanoNombre(const string &nombre)
{
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++) {
        Aldeano &j = *it;

        if (nombre == j.getNombre()) {
            aldeanos.erase(it);
            break;
        }
    }
}

void Civilizacion::eliminarAldeanoSalud(size_t salud)
{
    aldeanos.remove_if([salud](const Aldeano &a){ return a.getSalud() < salud;});
}

bool comparador(const Aldeano &a) 
{
    return a.getEdad() > 60;
}

void Civilizacion::eliminarAldeanoEdad()
{
   aldeanos.remove_if(comparador);
}


void Civilizacion::clasificarNombre()
{
    aldeanos.sort();
}

bool comparadorEdad(const Aldeano &a1, const Aldeano &a2)
{
    return a1.getEdad() > a2.getEdad();
}

void Civilizacion::clasificarEdad()
{
    aldeanos.sort(comparadorEdad);
}

bool comparadorSalud(const Aldeano &a1, const Aldeano &a2)
{
    return a1.getSalud() > a2.getSalud();
}

void Civilizacion::clasificarSalud()
{
    aldeanos.sort(comparadorSalud);
}

Aldeano* Civilizacion::buscarAldeano(const Aldeano &a)
{
  auto it = find(aldeanos.begin(), aldeanos.end(), a);

  if (it == aldeanos.end()) {
    return nullptr;
  }
  else {
    return &(*it);
  }

}

void Civilizacion::modificarNombreAldeano(const Aldeano &a)
{
   string nombre;

    Aldeano* aldeano = buscarAldeano(a);


   cout << "Nombre nuevo: ";
   getline(cin, nombre); cin.sync();
   aldeano->setNombre(nombre);
}


void Civilizacion::modificarEdadAldeano(const Aldeano &a)
{
   size_t edad;

    Aldeano* aldeano = buscarAldeano(a);

   cout << "Edad nueva: ";
   cin >> edad; cin.sync();
   aldeano->setEdad(edad);
}

void Civilizacion::modificarGeneroAldeano(const Aldeano &a)
{
   string genero;

    Aldeano* aldeano = buscarAldeano(a);

   cout << "Genero nuevo: ";
   getline(cin, genero); cin.sync();
   aldeano->setGenero(genero);
}

void Civilizacion::modificarSaludAldeano(const Aldeano &a)
{
   float salud;

    Aldeano* aldeano = buscarAldeano(a);

   cout << "Salud nueva: ";
   cin >> salud; cin.sync();
   aldeano->setSalud(salud);
}

void Civilizacion::respaldarAldeanos()
{
    ofstream archivo(getNombre() + ".txt", ios::out);
      for (auto it = aldeanos.begin(); it != aldeanos.end(); ++it) {
          Aldeano &aldeano = *it; 
          archivo << aldeano.getNombre() << endl;
          archivo << aldeano.getEdad()   << endl;
          archivo << aldeano.getGenero() << endl;
          archivo << aldeano.getSalud()  << endl;
      }
    archivo.close();
}

void Civilizacion::recuperarAldeanos() {
  ifstream archivo(getNombre() + ".txt");
  string temp;
  size_t edad;
  float salud;
  Aldeano* a = nullptr;
  if (archivo.is_open()) {
    while (!archivo.eof())
    {
      a = new Aldeano();
      getline(archivo, temp); cin.sync();
      a->setNombre(temp);

      getline(archivo, temp); cin.sync();
      edad = atoi((temp.c_str()));
      a->setEdad(edad);

      getline(archivo, temp); cin.sync();
      a->setGenero(temp);

      getline(archivo, temp); 
      salud = atof((temp.c_str()));
      a->setSalud(salud);

      agregarAldeanoFinal(*a);
    }
  }
  aldeanos.pop_back();
  archivo.close();
}