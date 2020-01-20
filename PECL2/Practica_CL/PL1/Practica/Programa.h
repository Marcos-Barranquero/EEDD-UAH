//
// Created by Marcos on 24/10/2017.
//

#ifndef PL1_PROGRAMA_H
#define PL1_PROGRAMA_H

#include "ColaCliente.h"
#include <iomanip>
#include "windows.h"
#include "ArbolBinario.h"


class Programa
{
public:
    Programa();

    // Métodos aux:

    int numeroAleatorio(int min, int max); // Genera un num. aleatorio (inclusivo, inclusivo)

    // Getters:

    int nClientesVip(); // Devuelve el tamaño de la cola vip.
    int nClientesNoVip(); // Devuelve el tamaño de la cola no vip.
    void mostrarColaVip(); // Muestra la cola Vip
    void mostrarColaNoVip(); // Muestra la cola No Vip
    void mostrarVendidas(); // Muestra la cola de entradas vendidas.
    void mostrarArbPreorden(); // Muestra por pantalla el árbol en preorden.
    void mostrarArbPosorden(); // Muestra por pantalla el árbol en posorden.
    void mostrarArbInorden(); // Muestra por pantalla el árbol en inorden.
    Cliente buscarEnArbol(string dni); // Busca en el árbol binario un cliente dado su DNI.
    void imprimirArbol(); // Imprime el árbol binario por pantalla.

    // Modificadoras:
    void generarColaVIP(); // Rellena colaVip con 15 clientes VIP
    void generarColaNoVIP(); // Rellena colaNoVip con 15 clientes No VIP.
    void vaciarColaVip(); // Vacia la cola Vip
    void vaciarColaNoVip(); // Vacia la cola no Vip
    void procesarVip(); // Simula el procesamiento de la cola VIP.
    void procesarNoVip(); // Simula el procesamiento de la cola No vip.
    void generarArbol(); // Genera el árbol binario.
    void reiniciar(); // Reinicia el programa.



private:
    ColaCliente colaVip; // Cola de clientes VIP.
    ColaCliente colaNoVip; // Cola de clientes No VIP.
    ColaCliente SV1; // Servidor vip 1.
    ColaCliente SNV1, SNV2, SNV3, SNV4; // Servidores no vip 1, 2, 3 y 4.
    Lista entradasVendidas; // Cola de clientes procesados ordenados por Id.
    ArbolBinario ab;

    // Métodos privados:
    int elegirServidor();

};


#endif //PL1_PROGRAMA_H