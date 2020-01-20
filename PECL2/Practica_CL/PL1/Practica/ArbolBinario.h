//
// Created by marco on 08/12/2017.
//

#include "Lista.h"
#include "NodoArbol.h"

#ifndef PL2_ARBOLBINARIO_H
#define PL2_ARBOLBINARIO_H

class ArbolBinario {
public:
    ArbolBinario();
    void insertar(Cliente cliente); // Método de acceso que llama al otro método insertar.
    void mostrarArbolPreorden(); // Método de acceso al método de mostrar arbol preorden.
    void mostrarArbolInorden(); // Método de acceso al método de mostrar arbol inorden.
    void mostrarArbolPosorden(); // Método de acceso al método de mostrar arbol posorden.
    Cliente buscarCliente(string dni); // Método de acceso al método de buscarCliente.
    void imprimeArbol(); // Método de acceso al método de imprimir árbol.


private:
    pnodoarbol raiz; // Raiz del nodo, con cliente con DNI por defecto.
    Cliente buscarCliente(string dni, pnodoarbol nodo); // Dado un dni, busca en el nodo al cliente, o en sus hijos.
    void mostrarArbolPosorden(pnodoarbol nodo); // Muestra el árbol en posorden llamándose recursivamente.
    void mostrarArbolInorden(pnodoarbol nodo); // Muestra el árbol en inorden llamándose recursivamente.
    void mostrarArbolPreorden(pnodoarbol nodo); // Muestra el árbol en preorden llamándose recursivamente.
    void imprimeArbol(NodoArbol *arbol,int cont); // Imprime el árbol por pantalla.
    void insertar(Cliente cliente, pnodoarbol nodo); // Inserta un cliente en el nodo pasado. Si no puede, buscará
    // recursivamente dónde insertarlo.

};


#endif //PL2_ARBOLBINARIO_H