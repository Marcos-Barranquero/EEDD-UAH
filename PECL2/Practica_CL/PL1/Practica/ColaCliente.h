//
// Created by marco on 08/12/2017.
//

#ifndef PL1_COLACLIENTE_H
#define PL1_COLACLIENTE_H


#include "Nodo.h"

class ColaCliente
{
public:
    ColaCliente();

    ~ColaCliente();

    // Modificadoras:
    void insertar(Cliente cliente); //Inserta un cliente por el final.
    Cliente eliminar(); // Saca al cliente de la cabeza.
    void vaciar(); // Vacia toda la cola. (La deja sin clientes)

    // Getters:

    bool estaVacia(); // T=> Esta vacia. F=> No esta vacia.
    void mostrar(); // Muestra la cola.
    int getSize(); // Devuelve el tamaño de la cola.

    Cliente getPrimero(); // Devuelve el primero sin eliminarlo de la cola. Para hacer comprobaciones.
    Cliente getUltimo(); // Devuelve el ultimo sin eliminarlo de la cola. Para hacer comprobaciones.

    void procesarClientes();

private:

    pnodo primero; // Puntero al primer nodo de la cola.
    pnodo ultimo; // Puntero al último nodo de la cola.
    int size; // Cantidad de clientes que hay en la cola.

};



#endif //PL1_COLACLIENTE_H
