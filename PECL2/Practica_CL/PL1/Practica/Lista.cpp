//
// Created by dcc on 21/11/2017.
//

#include "Lista.h"
// Constructor de la lista.
Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
    size = 0;
}
// Saca al cliente primer cliente.
Cliente Lista::eliminar()
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
// Vacia toda la lista. (La deja sin clientes)
void Lista::vaciar()
{
    while (primero) { eliminar(); }
    size = 0;
}
// Muestra la cola.
void Lista::mostrar()
{
    pnodo aux = primero;
    while (aux) {
        cout << aux->cliente.mostrarDatos() << endl;
        aux = aux->siguiente;
    }
    cout << endl;
}

// Inserta a un cliente en orden, según su ID.
void Lista::insertarPorId(Cliente cliente) {
    if(estaVacia()){insertar(cliente);} // Si la cola está vacía inserta normalmente.
    else if (primero->cliente.getId() > cliente.getId())
    {primero=new Nodo(cliente,primero);}
    else if(ultimo->cliente.getId()<cliente.getId())
    {
        //Si la id del ultimo es menor que la del cliente a insertar, lo inserta por el final:
        insertar(cliente);
    }
    else{
        pnodo aux; // Nodo auxiliar que recorrerá la cola
        aux = primero; // Empezando por el primero
        while (aux->siguiente->cliente.getId() < cliente.getId())
        {
            aux=aux->siguiente; // Irá avanzando
        } // Hasta que encuentre un nodo->siguiente.id > que la id del cliente a insertar.
        //cout << "Aux: " + aux->cliente.mostrarDatos() << endl;
        //cout << "Aux.siguiente: " + aux->siguiente->cliente.mostrarDatos() << endl;
        aux->siguiente = new Nodo(cliente, aux->siguiente); // Se añade entre medias del elemento
        // Con ID menor y mayor. (menor < cliente < Mayor)
    }
    size++;

}
//Inserta un cliente por el final.
void Lista::insertar(Cliente cliente)
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


// T=> Esta vacia. F=> No esta vacia.
bool Lista::estaVacia() {
    if (primero == NULL) {
        return true;
    } else {
        return false;
    }
}
// Devuelve el primero sin eliminarlo de la cola. Para hacer comprobaciones.
Cliente Lista::getPrimero() {
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
Cliente Lista::getUltimo() {
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
int Lista::getSize() {
    return size;
}