//
// Created by marco on 08/12/2017.
//

#include "NodoArbol.h"

// Constructor.
NodoArbol::NodoArbol(Cliente cliente, NodoArbol *hijo_izquierdo, NodoArbol *hijo_derecho)
{
    this->cliente=cliente;
    this->hijo_derecho=hijo_derecho;
    this->hijo_izquierdo=hijo_izquierdo;
}