//
// Created by Marcos on 17/10/2017.
//

#include "Cliente.h"

// Constructor por defecto
Cliente::Cliente() {}

// Constructor que recibe si es registrado o no y la hora de compra
Cliente::Cliente(bool registrado, int tInicioCompra)
{
    this->registrado = registrado;


    generaDni();
    generaTiempo(tInicioCompra);
    generaId();

}

// Genera un número aleatorio entre un máximo y un mínimo ambos inclusivos
int Cliente::numeroAleatorio(int min, int max)
{
    int numero_aleatorio = min + rand() % (max + 1 - min);
    return numero_aleatorio;
}
// Genera un tiempo de proceso de compra aleatorio entre 0 y 10
void Cliente::generaTiempo(int tInicioCompra)
{
    this->tInicioCompra = tInicioCompra;
    this->tProcesamiento = numeroAleatorio(1, 10);
    this->tFinCompra = 0;
    this->tEsperaServidor = 0;
}
// Genera un Dni aleatorio
void Cliente::generaDni()
{
    const string letras_dni = "TRWAGMYFPDXBNJZSQVHLCKE"; // Posibles letras del Dni, ordenadas. (0-22)
    string num_dni_aux; //Guarda los numeros del dni en una string
    string dni_string; // Guarda la cadena del Dni (numero + letra)

    //Genero números aleatorios para el Dni en una string:
    for (int j = 0; j < 8; ++j) {
        num_dni_aux += to_string(numeroAleatorio(1, 9)); //Concateno un aleatorio del 0 al 9
    }

    // Lo transformo de string a int
    int numero_dni = atoi(num_dni_aux.c_str());

    // Calculo la letra
    char letra = letras_dni[numero_dni % 23];


    //Concateno letra y numero_dni:
    dni_string = to_string(numero_dni) + letra;

    //Guardo el dni como un string en el atributo Dni de Cliente:
    Dni = dni_string;
}
// Genera una Id de 4 letras aleatorias del abecedario
void Cliente::generaId()
{
    string abecedario = "ABCDERFGHIJKLMNOPQRSTUVWXYZ";
    Id="";
    for (int i = 0; i < 4; i++)  {
        Id+=abecedario[numeroAleatorio(0,abecedario.length()-1)];
    }
}

// Devuelve una representación escrita del Cliente.
string Cliente::mostrarDatos()
{
    string dni = string(Dni);
    string id = string(Id);
    string iniCompra = std::to_string(tInicioCompra);
    string duracion = to_string(tProcesamiento);
    string finCompra = to_string(tFinCompra);
    string espera = to_string(tEsperaServidor);
    return "Dni: " + dni + " - tIni: " + iniCompra + " - tProc: " + duracion + " - tEspera: " + espera
           + " - tFin: " + finCompra + " - ID: " + id;
}

// Devuelve T si es registrado, F si no.
bool Cliente::esRegistrado()
{
    return registrado;
}
// Devuelve el DNI
string Cliente::getDni() {
    return Dni;
}

// Devuelve la ID
string Cliente::getId() {
    return Id;
}
// Devuelve el tiempo de inicio
int Cliente::getTInicioCompra() {
    return tInicioCompra;
}
// Dev. tProc.
int Cliente::getTProcesamiento() {
    return tProcesamiento;
}
// Devuelve el tiempo de finalización
int Cliente::getTFinCompra() {
    return tFinCompra;
}
// Devuelve el tiempo de Espera
int Cliente::getTEsperaServidor() {
    return tEsperaServidor;
}

// Permite setear el DNI del cliente
void Cliente::setDni(string dni) {
    this->Dni = dni;
}

// Permite setear el tiempo de Fin de compra del cliente.
void Cliente::setTFinCompra(int reloj) {
    this->tFinCompra = reloj;
    this->tEsperaServidor = tFinCompra - (tInicioCompra + tProcesamiento);
}

