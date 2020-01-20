//
// Created by Marcos on 24/10/2017.
//

#include "Programa.h"

Programa::Programa() {}
// Rellena colaNoVip con 15 clientes No VIP.
void Programa::generarColaNoVIP() {
    if (colaNoVip.estaVacia()) {
        int tInicio = 0;
        for (int i = 0; i < 25; ++i) {
            tInicio += numeroAleatorio(0, 5);
            Cliente clienteInsertado = Cliente(true, tInicio + 120);
            colaNoVip.insertar(Cliente(true, tInicio + 120));
        }
    }
}
// Rellena colaVip con 15 clientes VIP
void Programa::generarColaVIP() {
    if (colaVip.estaVacia()) {
        int tInicio = 0;
        for (int i = 0; i < 15; ++i) {
            tInicio += numeroAleatorio(0, 5); // Usado para setear el tInicio.
            colaVip.insertar(Cliente(true, tInicio));
        }
    }

}
// Vacia la cola Vip
void Programa::vaciarColaVip() {
    colaVip.vaciar();
}
// Vacia la cola no Vip
void Programa::vaciarColaNoVip() {
    colaNoVip.vaciar();
}
// Muestra la cola Vip
void Programa::mostrarColaVip() {
    colaVip.mostrar();
}
// Muestra la cola No Vip
void Programa::mostrarColaNoVip() {
    colaNoVip.mostrar();
}

// Genera un número aleatorio entre un máximo y un mínimo (inclusivos)
int Programa::numeroAleatorio(int min, int max)
{
    int numero_aleatorio = min + rand() % (max + 1 - min);
    return numero_aleatorio;
}
// Devuelve el tamaño de la cola vip.
int Programa::nClientesVip() {
    return colaVip.getSize();
}
// Devuelve el tamaño de la cola no vip.
int Programa::nClientesNoVip() {
    return colaNoVip.getSize();
}
// Simula el procesamiento de la cola VIP.
void Programa::procesarVip() {
    //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int reloj = 0; // Reloj que irá contando la hora.
    int contador_espera = 99999; // Contador usado para sacar clientes del sv1 a lista.



    while (!colaVip.estaVacia() || !SV1.estaVacia()) {


        // Si el tIni del primero de la colavip es el reloj:
        while (colaVip.getPrimero().getTInicioCompra() == reloj) {
            Cliente cl = colaVip.eliminar();
            // Si no hay clientes procesándose, pongo el contador al procesamiento de este.
            if (SV1.estaVacia()) { contador_espera = cl.getTProcesamiento(); }
            SV1.insertar(cl);
        }

        // Si se ha terminado de procesar:
        if (contador_espera == 0) {
            Cliente cl = SV1.eliminar();
            if (!SV1.estaVacia()) contador_espera = SV1.getPrimero().getTProcesamiento();
            cl.setTFinCompra(reloj);
            entradasVendidas.insertarPorId(cl);
        }

        //Muestra hora:
        cout << "\t--------------" << endl;
        cout << "\t| hora: "  << reloj << "  |" << endl;
        cout << "\t--------------" << endl;

        //Muestra cola VIP:
        cout << "Clientes en VIP: " << endl;
        colaVip.mostrar();

        //Muestra clientes en servidores:
        cout << "Procesando clientes vip en servidor 1: " << endl;
        SV1.mostrar();

        // Muestra lista de entradas vendidas:
        cout << "Lista entradas vendidas: " << endl;
        entradasVendidas.mostrar();

        // Pausa de 1 seg:
        Sleep(1000);

        // Avanza el reloj:
        reloj++;

        // Disminuye el contador de espera:
        contador_espera--;

        // Limpia la pantalla:
        system("cls");
    }

    cout << "Fin de clientes." << endl;
}

// Elige el servidor más vacío de los servidores no vip.
int Programa::elegirServidor()
{
    if (SNV1.getSize() <= SNV2.getSize() &&
        SNV1.getSize() <= SNV3.getSize() &&
        SNV1.getSize() <= SNV4.getSize()) return 1;
    else if (SNV2.getSize() <= SNV1.getSize() &&
             SNV2.getSize() <= SNV3.getSize() &&
             SNV2.getSize() <= SNV4.getSize()) return 2;
    else if (SNV3.getSize() <= SNV1.getSize() &&
             SNV3.getSize() <= SNV2.getSize() &&
             SNV3.getSize() <= SNV4.getSize()) return 3;
    else return 4;
}

// Simula el procesamiento de la cola No vip.
void Programa::procesarNoVip() {
    //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int reloj = 120;
    int contador_esperas1 = 9999;
    int contador_esperas2 = 9999;
    int contador_esperas3 = 9999;
    int contador_esperas4 = 9999;

    // Mientras haya clientes:
    while (!colaNoVip.estaVacia() || !SNV1.estaVacia() || !SNV1.estaVacia()
           || !SNV3.estaVacia() || !SNV4.estaVacia()) {


        while (colaNoVip.getPrimero().getTInicioCompra() == reloj) {
            Cliente cl = colaNoVip.eliminar();
            if (elegirServidor() == 1)
            {
                if (SNV1.estaVacia()) contador_esperas1 = cl.getTProcesamiento();
                SNV1.insertar(cl);
            } else if (elegirServidor() == 2) {
                if (SNV2.estaVacia()) contador_esperas2 = cl.getTProcesamiento();
                SNV2.insertar(cl);
            } else if (elegirServidor() == 3) {
                if (SNV3.estaVacia()) contador_esperas3 = cl.getTProcesamiento();
                SNV3.insertar(cl);
            } else {
                {
                    if (SNV4.estaVacia()) { contador_esperas4 = cl.getTProcesamiento(); }
                    SNV4.insertar(cl);
                }
            }
        }

        if (contador_esperas1 == 0) {
            Cliente cl = SNV1.eliminar();
            if (!SNV1.estaVacia()) contador_esperas1 = SNV1.getPrimero().getTProcesamiento();
            cl.setTFinCompra(reloj);
            entradasVendidas.insertarPorId(cl);}

        if (contador_esperas2 == 0) {
            Cliente cl = SNV2.eliminar();
            if (!SNV2.estaVacia()) contador_esperas2 = SNV2.getPrimero().getTProcesamiento();
            cl.setTFinCompra(reloj);
            entradasVendidas.insertarPorId(cl);}

        if (contador_esperas3 == 0) {
            Cliente cl = SNV3.eliminar();
            if (!SNV3.estaVacia()) contador_esperas3 = SNV3.getPrimero().getTProcesamiento();
            cl.setTFinCompra(reloj);
            entradasVendidas.insertarPorId(cl);}

        if (contador_esperas4 == 0) {
            Cliente cl = SNV4.eliminar();
            if (!SNV4.estaVacia()) contador_esperas4 = SNV4.getPrimero().getTProcesamiento();
            cl.setTFinCompra(reloj);
            entradasVendidas.insertarPorId(cl);}

        //Muestra hora:
        cout << "\t--------------" << endl;
        cout << "\t| hora: "  << reloj << "  |" << endl;
        cout << "\t--------------" << endl;

        //Muestra clientes no vip:
        cout << "Clientes en no VIP: " << endl;
        colaNoVip.mostrar();

        //Muestra clientes en servidores:
        cout << "Procesando clientes no vip en servidor 1: " << endl;
        SNV1.mostrar();
        cout << "Procesando clientes no vip en servidor 2: " << endl;
        SNV2.mostrar();
        cout << "Procesando clientes no vip en servidor 3: " << endl;
        SNV3.mostrar();
        cout << "Procesando clientes no vip en servidor 4: " << endl;
        SNV4.mostrar();

        //Muestra las entradas vendidas:
        cout << "Lista entradas vendidas: " << endl;
        mostrarVendidas();

        contador_esperas1--;
        contador_esperas2--;
        contador_esperas3--;
        contador_esperas4--;
        Sleep(1000);
        reloj++;
        system("cls");
    }

    cout << "Fin de clientes." << endl;

}
// Muestra la cola de entradas vendidas.
void Programa::mostrarVendidas() {
    entradasVendidas.mostrar();
}
// Reinicia el programa.
void Programa::reiniciar() {
    entradasVendidas.vaciar();
    colaNoVip.vaciar();
    colaVip.vaciar();
    SV1.vaciar();
    SNV1.vaciar();
    SNV2.vaciar();
    SNV3.vaciar();
    SNV4.vaciar();
    ab = ArbolBinario();
}
// Genera el árbol binario.
void Programa::generarArbol() {
    while(!entradasVendidas.estaVacia())
    {
        ab.insertar(entradasVendidas.eliminar());
    }
}
// Muestra por pantalla el árbol en preorden.
void Programa::mostrarArbPreorden() {
    ab.mostrarArbolPreorden();
}
// Muestra por pantalla el árbol en inorden.
void Programa::mostrarArbInorden()
{
    ab.mostrarArbolInorden();
}
// Muestra por pantalla el árbol en postorden.
void Programa::mostrarArbPosorden()
{
    ab.mostrarArbolPosorden();
}
// Busca en el árbol binario un cliente dado su DNI.
Cliente Programa::buscarEnArbol(string dni) {
    return ab.buscarCliente(dni);
}
// Imprime el árbol binario por pantalla.
void Programa::imprimirArbol() {
    ab.imprimeArbol();

}


