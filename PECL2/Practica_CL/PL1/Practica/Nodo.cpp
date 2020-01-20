//
// Created by Marcos on 24/10/2017.
//

#include "Nodo.h"

// Constructor del nodo que contiene un cliente.
// cliente <- cliente que se mete dentro del nodo
// *siguiente <- puntero que apunta al siguiente. Inicialmente en NULL.
Nodo::Nodo(Cliente cliente, Nodo *siguiente)
{
    this->cliente = cliente;
    this->siguiente = siguiente;
}

Nodo::~Nodo()
// Destructor.
{}

