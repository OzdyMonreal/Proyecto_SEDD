#include "civilizacion.h"

Aldeano capturar()
{
    Aldeano a;
    string nombre;
    string genero;
    size_t edad;
    size_t salud;

    cout << "Nombre: ";
    getline(cin, nombre); cin.sync();
    a.setNombre(nombre);

    cout << "Edad: ";
    cin >> edad; cin.sync();
    a.setEdad(edad);
    
    cout << "Genero: ";
    getline(cin, genero); cin.sync();
    a.setGenero(genero);

    cout << "Salud: ";
    cin >> salud; cin.sync();
    a.setSalud(salud);

    return a;
}

void menu(Civilizacion &c)
{
    string op;
    string cadena;
    Aldeano al;

    while (true)
    {
        cin.sync();
        cout << endl << endl;
        cout << "1) Agregar Aldeano" << endl;
        cout << "2) Eliminar Aldeano" << endl;
        cout << "3) Clasificar Aldeanos" << endl;
        cout << "4) Buscar Aldeano" << endl;
        cout << "5) Modificar Aldeano" << endl;
        cout << "6) Mostrar Aldeanos" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1") {
           float puntuacion;
           cout << endl << "1) Agregar al Inicio" << endl;
           cout << "2) Agregar al Final" << endl;
           getline(cin, op); 

           if (op == "1") {
              cout << endl;
              c.agregarAldeanoInicio(capturar());
              puntuacion = c.getPuntuacion();
              c.setPuntuacion(puntuacion + 100);
              cout << endl << "Se ha agregado correctamente...";
           } else if (op == "2") {
              cout << endl;
              c.agregarAldeanoFinal(capturar());
              puntuacion = c.getPuntuacion();
              c.setPuntuacion(puntuacion + 100);
              cout << endl << "Se ha agregado correctamente...";
           } else {
              cout << "Opcion no valida";
           }
        }
        
        else if (op == "2") {
            cout << endl << "1) Eliminar por Nombre" << endl;
            cout << "2) Eliminar por Salud" << endl;
            cout << "3) Eliminar por Edad" << endl;
            getline(cin, op);

            if (op == "1") {
                cout << "Nombre: ";
                getline(cin, cadena);
                cin.sync();

                c.eliminarAldeanoNombre(cadena);
                cout << endl << "Se ha eliminado correctamente...";
            } else if (op == "2") {
                size_t salud;

                cout << "Ingresa la Salud minima: ";
                cin >> salud;
                cin.sync();

                c.eliminarAldeanoSalud(salud);
                cout << endl << "Se ha eliminado correctamente...";
            } else if (op == "3") {
                c.eliminarAldeanoEdad();
                cout << endl << "Se ha eliminado correctamente...";
            }
        }
        else if (op == "3") {
            cout << endl << "1) Clasificar por Nombre" << endl;
            cout << "2) Clasificar por Edad" << endl;
            cout << "3) Clasificar por Salud" << endl;
            getline(cin, op);

            if (op == "1") {
                c.clasificarNombre();
                cout << endl << "Se ha clasificado correctamente...";
            } else if (op == "2") {
                c.clasificarEdad();
                cout << endl << "Se ha clasificado correctamente...";
            } else if (op == "3") {
                c.clasificarSalud();
                cout << endl << "Se ha clasificado correctamente...";
            }
        }
        else if (op == "4") {
            cout << "Ingrese el nombre: ";
            getline(cin, cadena);
            al.setNombre(cadena);
            cin.sync();

            Aldeano *ptr = c.buscarAldeano(al);

            if (ptr == nullptr) {
            cout << "Aldeano no encontrado..." << endl;
            }
            else {
                cout << *ptr << endl;
            }
        }
        else if (op == "5") {
            cout << "Ingrese el nombre: ";
            getline(cin, cadena);
            al.setNombre(cadena);
            cin.sync();

            Aldeano *ptr = c.buscarAldeano(al);

            if (ptr == nullptr) {
            cout << "Aldeano no encontrado..." << endl;
            }
            else {
                cout << endl << *ptr << endl;
                cout << endl << "1) Modificar el Nombre" << endl;
                cout << "2) Modificar la Edad" << endl;
                cout << "3) Modificar el Genero" << endl;
                cout << "4) Modificar la Salud" << endl;
                getline(cin, op); cin.sync();

                if (op == "1") {
                    cout << endl;
                    c.modificarNombreAldeano(al);
                    cout << endl << "Se ha modificado correctamente...";
                }
                else if (op == "2") {
                    cout << endl;
                    c.modificarEdadAldeano(al);
                    cout << endl << "Se ha modificado correctamente...";
                }
                else if (op == "3") {
                    cout << endl;
                    c.modificarGeneroAldeano(al);
                    cout << endl << "Se ha modificado correctamente...";
                }
                else if (op == "4") {
                    cout << endl;
                    c.modificarSaludAldeano(al);
                    cout << endl << "Se ha modificado correctamente...";
                }
                else {
                    cout << "Ingrese una opcion valida...";
                }

            }
        }
        else if (op == "6") {
            cout << endl;
            c.mostrar();
        }
        else if (op == "0") {
            cout << endl << "Saliendo del menu..." << endl;
            break;
        }
    }
}