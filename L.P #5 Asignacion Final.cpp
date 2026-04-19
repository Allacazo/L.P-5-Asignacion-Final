// L.P #5.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int Limite_Estudiantes = 20;
    const int Cantidad_Notas = 4;

    int Total_Estudiantes;
    string Nombres[Limite_Estudiantes];
    double Notas[Limite_Estudiantes * Cantidad_Notas];
    double Promedio_Por_Estudiante[Limite_Estudiantes];

    double Suma_Del_Grupo = 0;
    double Nota_Mas_Alta = 0;
    double Nota_Mas_Baja = 0;
    int Cantidad_Aprobados = 0;
    int Cantidad_Reprobados = 0;
    bool Es_La_Primera_Nota = true;

    cout << "Sistema de calificaciones\n\n";

    // Validar la cantidad de estudiantes
    do {
        cout << "Ingrese la cantidad de estudiantes (1 a 20): ";
        cin >> Total_Estudiantes;

        if (cin.fail() || Total_Estudiantes < 1 || Total_Estudiantes > Limite_Estudiantes) {
            cout << "Dato invalido. Debe ingresar un numero entre 1 y 20.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break;
        }
    } while (true);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n----- INGRESO DE CALIFICACIONES -----\n";

    for (int Numero_Estudiante = 0; Numero_Estudiante < Total_Estudiantes; Numero_Estudiante++) {
        double Suma_Notas_Del_Estudiante = 0;
        string Nombre_Del_Estudiante;

        cout << "\nEstudiante " << Numero_Estudiante + 1 << '\n';

        do {
            cout << "Ingrese el nombre del estudiante: ";
            getline(cin, Nombre_Del_Estudiante);

            if (Nombre_Del_Estudiante.empty()) {
                cout << "El nombre no puede estar vacio. Intente nuevamente.\n";
            }
            else {
                Nombres[Numero_Estudiante] = Nombre_Del_Estudiante;
                break;
            }
        } while (true);

        for (int Numero_Nota = 0; Numero_Nota < Cantidad_Notas; Numero_Nota++) {
            double Nota_Ingresada;

            do {
                cout << "Ingrese la calificacion " << Numero_Nota + 1 << " (0 a 100): ";
                cin >> Nota_Ingresada;

                if (cin.fail() || Nota_Ingresada < 0 || Nota_Ingresada > 100) {
                    cout << "Calificacion invalida. Intente nuevamente.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else {
                    break;
                }
            } while (true);

            int Posicion_En_Arreglo = Numero_Estudiante * Cantidad_Notas + Numero_Nota;
            Notas[Posicion_En_Arreglo] = Nota_Ingresada;

            Suma_Notas_Del_Estudiante += Nota_Ingresada;
            Suma_Del_Grupo += Nota_Ingresada;

            if (Es_La_Primera_Nota) {
                Nota_Mas_Alta = Nota_Ingresada;
                Nota_Mas_Baja = Nota_Ingresada;
                Es_La_Primera_Nota = false;
            }
            else {
                if (Nota_Ingresada > Nota_Mas_Alta) {
                    Nota_Mas_Alta = Nota_Ingresada;
                }

                if (Nota_Ingresada < Nota_Mas_Baja) {
                    Nota_Mas_Baja = Nota_Ingresada;
                }
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Promedio_Por_Estudiante[Numero_Estudiante] = Suma_Notas_Del_Estudiante / Cantidad_Notas;

        if (Promedio_Por_Estudiante[Numero_Estudiante] >= 70) {
            Cantidad_Aprobados++;
        }
        else {
            Cantidad_Reprobados++;
        }
    }

    double Promedio_General = Suma_Del_Grupo / (Total_Estudiantes * Cantidad_Notas);

    cout << fixed << setprecision(2);
    cout << "\n----- RESULTADOS FINALES -----\n";

    for (int Numero_Estudiante = 0; Numero_Estudiante < Total_Estudiantes; Numero_Estudiante++) {
        cout << "\nEstudiante " << Numero_Estudiante + 1 << ":\n";
        cout << "Nombre: " << Nombres[Numero_Estudiante] << '\n';

        for (int Numero_Nota = 0; Numero_Nota < Cantidad_Notas; Numero_Nota++) {
            int Posicion_En_Arreglo = Numero_Estudiante * Cantidad_Notas + Numero_Nota;
            cout << "Calificacion " << Numero_Nota + 1 << ": " << Notas[Posicion_En_Arreglo] << '\n';
        }

        cout << "Promedio del estudiante: " << Promedio_Por_Estudiante[Numero_Estudiante] << '\n';
    }

    cout << "\nPromedio general del grupo: " << Promedio_General << '\n';
    cout << "Calificacion mas alta: " << Nota_Mas_Alta << '\n';
    cout << "Calificacion mas baja: " << Nota_Mas_Baja << '\n';
    cout << "Cantidad de aprobados: " << Cantidad_Aprobados << '\n';
    cout << "Cantidad de reprobados: " << Cantidad_Reprobados << '\n';

    return 0;
}
