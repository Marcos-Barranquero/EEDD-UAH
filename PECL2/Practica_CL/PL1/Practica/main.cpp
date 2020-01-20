#include <iostream>
#include <time.h>
#include "Programa.h"

void mensaje(string mensaje) {
    cout << mensaje << endl;
}

void pausa()
{
    system("pause");
    system("cls");
}

void menu() {
    Programa gestorClientes = Programa();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char opcion = 'X';

    while (opcion != 'S') {
        SetConsoleTextAttribute(hConsole, 74);
        cout << "\n\t-------------------------------------------------" << endl;
        cout << "\t-                   MENU                        -" << endl;
        cout << "\t-------------------------------------------------" << endl;
        SetConsoleTextAttribute(hConsole, 47);

        cout << "\tNumero de clientes VIP: " << setw(2) << gestorClientes.nClientesVip();
        cout << " Numero de clientes no VIP: " << setw(2) << gestorClientes.nClientesNoVip() << endl;
        SetConsoleTextAttribute(hConsole, 7);

        cout << "\tA) Generar solicitudes de entradas de los clientes VIP." << endl;
        cout << "\tB) Mostrar la cola de solicitudes de espera de clientes VIP." << endl;
        cout << "\tC) Borrar la cola de solicitudes en espera de clientes VIP." << endl;
        cout << "\tD) Generar solicitudes de entradas de los clientes no VIP." << endl;
        cout << "\tE) Mostrar la cola de solicitudes de espera de clientes no VIP." << endl;
        cout << "\tF) Borrar la cola de solicitudes en espera de clientes no VIP." << endl;
        cout << "\tG) Simular el proceso de compra de entradas de los clientes VIP." << endl;
        cout << "\tH) Simular el proceso de compra de entradas de los clientes no VIP." << endl;
        cout << "\tI) Mostrar la lista de entradas vendidas." << endl;
        cout << "\tJ) Reiniciar el programa." << endl;
        cout << "\tK) Crear un arbol binario de busqueda ordenado por DNI." << endl;
        cout << "\tL) Buscar un cliente en el arbol binario proporcionando DNI." << endl;
        cout << "\tM) Mostrar ABB en preorden." << endl;
        cout << "\tN) Mostrar ABB en postorden." << endl;
        cout << "\tO) Mostrar ABB en inorden." << endl;
        cout << "\tP) Dibujar arbol binario." << endl;
        cout << "\n\n\tS) Salir del programa." << endl;


        cout << "Introduce opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 'A':
                mensaje("Generando cola VIP.");
                gestorClientes.generarColaVIP();
                pausa();
                break;
            case 'B':
                system("cls");
                mensaje("Mostrando cola VIP.");
                gestorClientes.mostrarColaVip();
                pausa();
                break;
            case 'C':
                mensaje("Vaciando cola VIP.");
                gestorClientes.vaciarColaVip();
                pausa();
                break;
            case 'D':
                mensaje("Generando cola no VIP.");
                gestorClientes.generarColaNoVIP();
                pausa();
                break;
            case 'E':
                system("cls");
                mensaje("Mostrando cola no VIP.");
                gestorClientes.mostrarColaNoVip();
                pausa();
                break;
            case 'F':
                mensaje("Vaciando cola no VIP.");
                gestorClientes.vaciarColaNoVip();
                pausa();
                break;
            case 'G':
                gestorClientes.procesarVip();
                mensaje("Fin de procesar clientes VIP.");
                pausa();
                break;
            case 'H':
                gestorClientes.procesarNoVip();
                mensaje("Fin de procesar clientes no VIP.");
                pausa();
                break;
            case 'I':
                mensaje("Mostrando entradas vendidas ordenadas por ID.");
                gestorClientes.mostrarVendidas();
                pausa();
                break;
            case 'J':
                gestorClientes.reiniciar();
                mensaje("Reiniciando programa.");
                pausa();
                break;
            case 'K':
                gestorClientes.generarArbol();
                mensaje("Creando arbol binario ordenado por DNI...");
                pausa();
                break;

            case 'L':
            {
                string dni_a_buscar;
                cout << "Introduce DNI: ";
                cin >> dni_a_buscar;
                Cliente buscado = gestorClientes.buscarEnArbol(dni_a_buscar);
                if(buscado.getDni() == "ERROR. CLIENTE NO ENCONTRADO.")
                {
                    cout << "Error. Cliente no encontrado." << endl;
                }
                else
                {
                cout << buscado.mostrarDatos() << endl;
                }
                pausa();
                break;
            }

            case 'M':
                mensaje("Mostrando arbol en preorden: ");
                gestorClientes.mostrarArbPreorden();
                pausa();
                break;
            case 'N':
                mensaje("Mostrando arbol en postorden: ");
                gestorClientes.mostrarArbPosorden();
                pausa();
                break;
            case 'O':
                mensaje("Mostrando arbol en inorden: ");
                gestorClientes.mostrarArbInorden();
                pausa();
                break;

            case 'P':
                mensaje("Dibujando arbol binario: ");
                gestorClientes.imprimirArbol();
                pausa();
                break;
            case 'S':
                break;
            default:
                mensaje("Opcion incorrecta...");
                pausa();
                break;
        }
    }
    system("cls");

}

int main() {


    srand(time(NULL));

    menu();

}

