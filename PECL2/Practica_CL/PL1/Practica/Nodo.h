//
// Created by Marcos on 24/10/2017.
//

#ifndef PL1_NODO_H
#define PL1_NODO_H

#include "Cliente.h"

using namespace std;


class Nodo
{
public:
    Nodo(Cliente cliente, Nodo *siguiente = NULL);
    // Constructor: recibe el cliente que contendrá el nodo, y un puntero al siguiente (Opcional).

    ~Nodo(); // Destructor.

private:
    Cliente cliente; // Contiene al cliente del nodo.
    Nodo *siguiente; // Apunta al siguiente nodo en la cola.

    friend class ColaCliente; // Puede acceder a los elementos privados de la clase ColaCliente.
    friend class Lista;

};

typedef Nodo *pnodo;


#endif //PL1_NODO_H
