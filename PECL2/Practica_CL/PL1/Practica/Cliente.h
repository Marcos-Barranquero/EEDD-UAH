//
// Created by Marcos on 17/10/2017.
//

#ifndef PL1_CLIENTE_H
#define PL1_CLIENTE_H

#include <iostream>
#include <string>

using namespace std;

class Cliente
{
private:
    // Atributos privados:
    string Dni; // Dni del cliente
    string Id; // Identificador de la cola de entradas.

    bool registrado; // True = Registrado; False = No registrado;

    int tInicioCompra; // Hora en la que se inició el proceso de compra.
    int tProcesamiento; // Duración del procesamiento de la compra.
    int tFinCompra; // Hora en la que finalizó el proceso de compra.
    int tEsperaServidor; // Tiempo que estuvo esperando a ser atendido.

    // Métodos privados:

    int numeroAleatorio(int min, int max); // Genera un número aleatorio entre un máximo y un mínimo ambos inclusivos.
    void generaDni(); // Genera un Dni aleatorio
    void generaId(); // Genera una Id de 4 letras aleatorias del abecedario
    void generaTiempo(int tInicioCompra); // Genera un tiempo de proceso de compra aleatorio entre 0 y 10


public:
    // Métodos públicos:

    // Constructores:
    Cliente();
    Cliente(bool registrado, int horaInicio); // Constructor que recibe si es registrado o no y la hora de compra

    // Getters:
    bool esRegistrado(); // Devuelve T si es registrado, F si no.
    string mostrarDatos(); // Devuelve una representación escrita del Cliente.
    string getDni(); // Devuelve el DNI
    string getId(); // Devuelve la ID

    int getTInicioCompra(); // Devuelve tIni.
    int getTProcesamiento(); // Dev. tProc.
    int getTFinCompra(); // Dev tFin
    int getTEsperaServidor(); // Dev. tEspera

    // Setters:
    void setTFinCompra(int tFinCompra);
    void setDni(string dni);



};


#endif //PL1_CLIENTE_H
