//
// Created by marco on 08/12/2017.
//

#include "ColaCliente.h"

// Constructor de la cola.
ColaCliente::ColaCliente()
{
    primero = NULL;
    ultimo = NULL;
    size = 0;
}

//Inserta un cliente por el final.
void ColaCliente::insertar(Cliente cliente)
{
    pnodo nuevo;
    nuevo = new Nodo(cliente);

    // Si existe último va a apuntar al nuevo que entra:
    if (ultimo) { ultimo->siguiente = nuevo; }
    // El nuevo que ha entrado pasa a ser el ultimo:
    ultimo = nuevo;
    // Si antes estaba vacía, el primero es el último:
    if (!primero) { primero = nuevo; }
    size++;

}
// Saca al cliente de la cabeza.
Cliente ColaCliente::eliminar()
{
    pnodo nodo; // Nuevo nodo
    Cliente clienteOuput; // Almacenará el cliente a devolver tras eliminarlo
    nodo = primero;
    if (!nodo) { return Cliente(false, 0); } // Si no hay primero, cola vacía, devuelve NULL.
    primero = nodo->siguiente; // Si en efecto hay primero, primero pasará a apuntar al segundo.
    clienteOuput = nodo->cliente; // El cliente a devolver pasará a ser el cliente que almacenaba el nodo primero.
    delete nodo; // Elimino el nodo que contiene al primer cliente.
    if (!primero) { ultimo = NULL; } // Si tras sacarlo no hay primero, tampoco habrá último y la cola será vacía.
    size--;
    return clienteOuput;

}
// Muestra la cola.
void ColaCliente::mostrar()
{
    pnodo aux = primero;
    while (aux) {
        cout << aux->cliente.mostrarDatos() << endl;
        aux = aux->siguiente;
    }
    cout << endl;
}

// Destructor:
ColaCliente::~ColaCliente() {}
// Vacia toda la cola. (La deja sin clientes)
void ColaCliente::vaciar()
{
    while (primero) { eliminar(); }
    size = 0;
}
// T=> Esta vacia. F=> No esta vacia.
bool ColaCliente::estaVacia() {
    if (primero == NULL) {
        return true;
    } else {
        return false;
    }
}
// Devuelve el primero sin eliminarlo de la cola. Para hacer comprobaciones.
Cliente ColaCliente::getPrimero() {
    Cliente output = Cliente(false, 0);
    pnodo nodo;
    if (!estaVacia()) {
        nodo = primero;
        output = nodo->cliente;
        return output;
    } else {
        return output;
    }
}
// Devuelve el ultimo sin eliminarlo de la cola. Para hacer comprobaciones.
Cliente ColaCliente::getUltimo() {
    Cliente output = Cliente(false, 0);
    pnodo nodo;
    if (!estaVacia()) {
        nodo = ultimo;
        output = nodo->cliente;
        return output;
    } else {
        return output;
    }
}
// Devuelve el tamaño de la cola.
int ColaCliente::getSize() {
    return size;
}
