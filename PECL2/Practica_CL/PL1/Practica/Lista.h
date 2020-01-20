//
// Created by dcc on 21/11/2017.
//

#ifndef PL2_LISTA_H
#define PL2_LISTA_H

#include "Nodo.h"


class Lista
{
public:
    Lista();
    void vaciar();
    void insertar(Cliente cliente); //Inserta un cliente por el final.
    void insertarPorId(Cliente cliente); // Inserta a un cliente en orden, según su ID.
    Cliente eliminar(); // Saca al cliente del principio.

    // Getters
    bool estaVacia(); // T=> Esta vacia. F=> No esta vacia.
    void mostrar(); // Muestra la lista.
    int getSize(); // Devuelve el tamaño de la lista.

private:
    pnodo primero; // Puntero al primer nodo de la lista.
    pnodo ultimo; // Puntero al último nodo de la lista.
    int size; // Cantidad de clientes que hay en la lista.
    Cliente getPrimero(); // Devuelve el primero sin eliminarlo de la cola. Para hacer comprobaciones.
    Cliente getUltimo(); // Devuelve el ultimo sin eliminarlo de la cola. Para hacer comprobaciones.

};


#endif //PL2_LISTA_H
