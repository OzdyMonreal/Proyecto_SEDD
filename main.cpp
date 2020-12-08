#include "videogame.h"
#include <iostream>
#include <windows.h>
#include <unistd.h>

using namespace std;

int main() {
  VideoGame juego;
  Civilizacion civil;
  size_t n;
  string op, cadena;

  while (true)
  {
      
      cin.sync();
      Sleep(150);
      cout << endl;
      cout << "1) Nombre de Usuario" << endl;
      cout << "2) Agregar Civilizacion" << endl;
      cout << "3) Insertar Civilizacion" << endl;
      cout << "4) Crear Civilizaciones" << endl;
      cout << "5) Primera Civilizacion" << endl;
      cout << "6) Ultima Civilizacion" << endl;
      cout << "7) Ordenar" << endl;
      cout << "8) Eliminar Civilizacion" << endl;
      cout << "9) Buscar" << endl;
      cout << "10) Modificar" << endl;
      cout << "11) Resumen" << endl;
      cout << "12) Salir" << endl;
      getline(cin, op);
      cout << endl;

    if (op == "1") {
      cout << "Ingresa el nombre del usuario: ";

      getline(cin, cadena);
      cin.sync();
      juego.agregarUsuario(cadena);
      cout << "Se ha agregado exitosamente..." << endl;
    }
    else if (op == "2") {
      cin >> civil;

      juego.agregarFinal(civil);
      cout << "Se ha agregado exitosamente..." << endl;
      cin.sync();
    }
    
    else if (op == "3") {
      if (juego.total() > 0) {
        cin >> civil;

        cout << "Posicion donde se insertara: ";
        cin.sync();
        cin >> n;

        if (n >= juego.total()) {
          cout << "Posicion no valida" << endl;
        }
        else {
          juego.insertar(civil, n);
          cout << "Se ha insertado exitosamente..." << endl;
        }
      }
      else {
        cout << "No es posible. No hay civilizaciones registradas..." << endl;
      }
    }

    else if (op == "4") {
      cin >> civil;

      cout << "Civilizaciones a crear: ";
      cin >> n;
      cin.sync();

      if (n == 0) {
        cout << "No se pueden crear 0 civilizaciones..." << endl;
      } else {
       juego.inicializar(civil, n);
       cout << "Se crearon correctamente..." << endl;
      }
    }

    else if (op == "5") {
      if (juego.total() > 0) {
        cout << "Primera civilizacion registrada..." << endl;
        juego.primera();
      }
      else {
        cout << "No es posible. No hay civilizaciones registradas..." << endl;
      }
    }

    else if (op == "6") {
      if (juego.total() > 0) {
        cout << "Ultima civilizacion registrada..." << endl;
        juego.ultima();
      }
      else {
        cout << "No es posible. No hay civilizaciones registradas..." << endl;
      }
    }

    else if (op == "7") {
      if (juego.total() > 0) {
        while (true) {
          cout << "1) Ordenar por Nombre" << endl;
          cout << "2) Ordenar por Ubicacion X" << endl;
          cout << "3) Ordenar por Ubicacion Y" << endl;
          cout << "4) Ordenar por Puntuacion" << endl;
          cout << "5) Salir" << endl;
          cin.sync();
          getline(cin, cadena);

          if (cadena == "1") {
            juego.ordenarNombre();
            cout << "Se ha ordenado exitosamente..." << endl;
            break;
          }
          else if (cadena == "2") {
            juego.ordenarUbicacionX();
            cout << "Se ha ordenado exitosamente..." << endl;
            break;
          }
          else if (cadena == "3") {
            juego.ordenarUbicacionY();
            cout << "Se ha ordenado exitosamente..." << endl;
            break;
          }
          else if (cadena == "4") {
            juego.ordenarPuntuacion();
            cout << "Se ha ordenado exitosamente..." << endl;
            break;
          }
          else if (cadena == "5") {
            break;
          }
          else {
            cout << "Elige una opcion valida..." << endl;
          }
        }
      }
      else {
        cout << "No es posible. No hay civilizaciones registradas..." << endl;
      }
    }

    else if (op == "8") {
      if (juego.total() > 0){
        cout << "Ingrese el nombre: ";
        getline(cin, cadena);
        civil.setNombre(cadena);
        cin.sync();

        Civilizacion *ptr = juego.buscar(civil);

        if (ptr == nullptr) {
          cout << "Civilizacion no encontrada" << endl;
        }
        else {
          cout << endl << *ptr << endl;
          cout << "Desea eliminarla? (S/N): ";
          getline(cin, cadena);
          cin.sync();

          if (cadena == "S" || cadena == "s") {
            juego.eliminar(civil);
            cout << "Se ha eliminado la civilizacion correctamente..." << endl;
          }
          else {
            cout << "NO se ha eliminado la civilizacion..." << endl;
          }
        }
      }
      else {
        cout << "No es posible. No hay civilizaciones registradas..." << endl;
      }
    }

    else if (op == "9") {
      if (juego.total() > 0) {
        cout << "Ingrese el nombre: ";
        getline(cin, cadena);
        civil.setNombre(cadena);
        cin.sync();

        Civilizacion *ptr = juego.buscar(civil);

        if (ptr == nullptr) {
          cout << "Civilizacion no encontrada..." << endl;
        }
        else {
          cout << endl << *ptr;
        }
      }
      else {
        cout << "No es posible. No hay civilizaciones registradas..." << endl;
      }
    }

    else if (op == "10") {
      if (juego.total() > 0) {
        cout << "Ingrese el nombre: ";
        getline(cin, cadena);
        civil.setNombre(cadena);
        cin.sync();

        Civilizacion *ptr = juego.buscar(civil);

        if (ptr == nullptr) {
          cout << "Civilizacion no encontrada" << endl;
        }
        else {
          cout << endl << *ptr << endl;

          while (true) {
            cout << "Modificar atributos" << endl;
            cout << "1) Nombre" << endl;
            cout << "2) Ubicacion X" << endl;
            cout << "3) Ubicacion Y" << endl;
            cout << "4) Puntuacion" << endl;
            cin.sync();
            getline(cin, cadena);

            if (cadena == "1") {
              juego.modificarNombre(civil);
              cout << "Se ha modificado correctamente..." << endl;
              break;
            }
            else if (cadena == "2") {
              juego.modificarUbicacionX(civil);
              cout << "Se ha modificado correctamente..." << endl;
              break;
            }
            else if (cadena == "3") {
              juego.modificarUbicacionY(civil);
              cout << "Se ha modificado correctamente..." << endl;
              break;
            }
            else if (cadena == "4") {
              juego.modificarPuntuacion(civil);
              cout << "Se ha modificado correctamente..." << endl;
              break;
            }
          }
        }
      }
      else {
        cout << "No es posible. No hay civilizaciones registradas..." << endl;
      }
    }

    else if (op == "11") {
       juego.resumen();
    }
    else if (op == "12") {
      break;
    }
  }
  return 0;
}