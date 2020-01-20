#ifndef PL2_NODOARBOL_H
#define PL2_NODOARBOL_H

#include "Cliente.h"

class NodoArbol {
public:
    NodoArbol(Cliente cliente, NodoArbol *hijo_izquierdo = NULL, NodoArbol *hijo_derecho = NULL); // Constructor.


    Cliente cliente; // Cliente dentro del nodo.

    NodoArbol *hijo_izquierdo; // Puntero al hijo izquierdo.
    NodoArbol *hijo_derecho; // Puntero al hijo izquierdo.
    friend class ArbolBinario;
private:

};

typedef NodoArbol *pnodoarbol;

#endif // PL2_NODOARBOL_H
