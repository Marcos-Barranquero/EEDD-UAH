//
// Created by marco on 08/12/2017.
//

#include "ArbolBinario.h"

// Constructor (Ya mete el cliente por defecto):
ArbolBinario::ArbolBinario() {
    // Genero el cliente con DNI por defecto:
    Cliente cl_por_defecto =Cliente(true, 0);
    cl_por_defecto.setDni("55555555K");
    // Creo raiz:
    raiz = new NodoArbol(cl_por_defecto);
}

// Método de acceso que llama al otro método insertar
void ArbolBinario::insertar(Cliente cliente, pnodoarbol nodo) {
    // Paso a enteros los DNI's. Descarto la letra final:
    int dni_a_insertar = stoi(cliente.getDni().substr(0,8));
    int dni_del_nodo = stoi(nodo->cliente.getDni().substr(0,8));

    // Si el nodo es una hoja (Hijos vacíos):
    if(nodo->hijo_izquierdo == NULL && nodo->hijo_derecho == NULL)
    {
        // Si el DNI del cliente a insertar es menor que el del nodo:
        if(dni_a_insertar < dni_del_nodo) {
            nodo->hijo_izquierdo = new NodoArbol(cliente);
        }
        // Si el DNI del cliente a insertar es MAYOR que el del nodo:
        if(dni_a_insertar > dni_del_nodo){
            nodo->hijo_derecho = new NodoArbol(cliente);
        }
    }
        // Si no es una hoja:
    else
    {
        // Si el DNI del cliente a insertar es menor que el del nodo:
        if(dni_a_insertar < dni_del_nodo)
        {
            if(nodo->hijo_izquierdo == NULL)
                nodo->hijo_izquierdo = new NodoArbol(cliente); // Si no hay nodo hijo, lo creo.
            if(nodo->hijo_izquierdo != NULL)
                insertar(cliente, nodo->hijo_izquierdo); // Si hay nodo se inserta en él.
        }
            // Si el DNI del cliente a insertar es MAYOR que el del nodo:
        else if(dni_a_insertar > dni_del_nodo)
        {
            if(nodo->hijo_derecho == NULL)
                nodo->hijo_derecho = new NodoArbol(cliente); // Si no hay nodo hijo, lo creo.
            if(nodo->hijo_derecho != NULL)
                insertar(cliente, nodo->hijo_derecho); // Si hay nodo se inserta en él.

        }
    }

}

// Muestra el árbol en inorden llamándose recursivamente
void ArbolBinario::mostrarArbolInorden(pnodoarbol nodo) {
    if(nodo == NULL) cout << "";
    else
    {
        mostrarArbolInorden(nodo->hijo_izquierdo);
        cout << nodo->cliente.mostrarDatos() << endl;
        mostrarArbolInorden(nodo->hijo_derecho);
    }
}
// Muestra el árbol en posorden llamándose recursivamente
void ArbolBinario::mostrarArbolPosorden(pnodoarbol nodo) {
    if(nodo == NULL) cout << "";
    else
    {
        mostrarArbolPosorden(nodo->hijo_izquierdo);
        mostrarArbolPosorden(nodo->hijo_derecho);
        cout << nodo->cliente.mostrarDatos() << endl;
    }

}
// Muestra el árbol en preorden llamándose recursivamente
void ArbolBinario::mostrarArbolPreorden(pnodoarbol nodo) {
    if(nodo == NULL) cout << "";
    else
    {
        cout << nodo->cliente.mostrarDatos() << endl;
        mostrarArbolPreorden(nodo->hijo_izquierdo);
        mostrarArbolPreorden(nodo->hijo_derecho);
    }

}

// Método de acceso al método de mostrar arbol posorden
void ArbolBinario::mostrarArbolPosorden() {
    mostrarArbolPosorden(raiz);


}
// Método de acceso al método de mostrar arbol inorden
void ArbolBinario::mostrarArbolInorden() {
    mostrarArbolInorden(raiz);

}
// Método de acceso al método de mostrar arbol preorden
void ArbolBinario::mostrarArbolPreorden() {
    mostrarArbolPreorden(raiz);

}
// Inserta un cliente en el nodo pasado. Si no puede, buscará recursivamente dónde insertarlo
void ArbolBinario::insertar(Cliente cliente) {
    insertar(cliente, raiz);

}
// Dado un dni, busca en el nodo al cliente, o en sus hijos.
Cliente ArbolBinario::buscarCliente(string dni, pnodoarbol nodo) {

    // Convierto a enteros los DNI's para poder comparar. (Descarto la letra final).

    int dni_buscado = stoi(dni.substr(0,8));
    int dni_del_nodo = stoi(nodo->cliente.getDni().substr(0,8));

    // Si acierto, devuelve el cliente.
    if(dni_buscado == dni_del_nodo) return nodo->cliente;

        // Si no, si hay hijo derecho y el dni es mayor que el del nodo, busco ahí:
    else if(dni_buscado > dni_del_nodo && nodo->hijo_derecho != NULL)
        return buscarCliente(dni, nodo->hijo_derecho);

        // Si no, si hay hijo izquierdo y el dni es menor que el del nodo, busco ahí:
    else if(dni_buscado < dni_del_nodo && nodo->hijo_izquierdo != NULL)
        return buscarCliente(dni, nodo->hijo_izquierdo);

    // Finalmente, si no se encuentra el cliente, devuelve un cliente por defecto:
    Cliente no_encontrado = Cliente(true,-1);
    no_encontrado.setDni("ERROR. CLIENTE NO ENCONTRADO.");
    return no_encontrado;

}

// Imprime el árbol por pantalla
void ArbolBinario::imprimeArbol(pnodoarbol arbol, int cont){
    if (arbol == NULL) return;
    else
    {
        imprimeArbol(arbol->hijo_derecho, cont+1);
        for (int i = 0; i < cont; i++) {
            cout << "|" << "          ";
        }
    }
    cout << arbol->cliente.getDni() + "--|" << endl;
    imprimeArbol(arbol->hijo_izquierdo, cont + 1);
}

// Método de acceso al método de buscarCliente
Cliente ArbolBinario::buscarCliente(string dni) {
    return buscarCliente(dni, raiz);
}

// Método de acceso al método de imprimir árbol
void ArbolBinario::imprimeArbol() {
    imprimeArbol(raiz, 0);

}
