#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
}

*primero ,*ultimo;
int opcion = 0;

void Pause() {
    std::cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    system("clear");
}

void insertarNodo() {
    Nodo *actual = new Nodo();
    cout << "Ingrese el dato del nuevo nodo de la lista: ";
    cin >> actual->dato;

    if(primero == NULL){
        primero = actual;
        primero->siguiente = NULL;
        ultimo = primero; 
    } else {
        ultimo->siguiente = actual;
        actual->siguiente = NULL;
        ultimo = actual;
    }
    Pause();
}

void desplegarNodo() {
    Nodo *actual = new Nodo();
    actual = primero;
    int i = 0;

    if( primero != NULL){
        cout << "Datos almacenados en la lista dinamica enlazada" << endl;
        while(actual != NULL){
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
            i++;
        }
    } else {
        cout << "Lo sentimos la lista esta vacia" << endl;
    }
    Pause();
}

void buscarNodo() {
    Nodo *actual = new Nodo();
    actual = primero;
    int datoBuscado;
    int i = 0;
    bool encontrado = false;

    if(primero != NULL){
        cout << "Ingrese el dato que desea buscar en lista: ";
        cin >> datoBuscado;

        while(actual != NULL){
            if(datoBuscado == actual->dato){
                cout << "El dato "<< actual->dato << " se encuentra en la posicion " << i << endl;
                encontrado = true;
                Pause();
                return;
            }
            actual = actual->siguiente;
            i++;
        }
        if (encontrado == false){
            cout << "Lo sentimos el dato no es parte de la lista" << endl;
        }

    } else {
        cout << "Lo sentimos la lista esta vacia" << endl;
    }
    Pause();
    
}

void modificarNodo() {
    Nodo *actual = new Nodo();
    actual = primero;
    int datoBuscado;
    int nuevoValor;
    int i = 0;
    bool encontrado = false;

    if(primero != NULL){
        cout << "Ingrese el dato que desea modificar en lista: ";
        cin >> datoBuscado;

        while(actual != NULL){
            if(datoBuscado == actual->dato){
                cout << "El dato "<< actual->dato << " fue encontrado en la posicion " << i << endl;
                encontrado = true;
                cout << "Ingrese el nuevo valor: ";
                cin >> nuevoValor;
                actual->dato = nuevoValor;
                cout << "\nEl Dato fue modificado con exito" << endl;
                Pause();
                return;
            }
            actual = actual->siguiente;
            i++;
        }
        if (encontrado == false){
            cout << "Lo sentimos el dato no es parte de la lista" << endl;
        }

    } else {
        cout << "Lo sentimos la lista esta vacia" << endl;
    }
    Pause();
}

void procesarOpcion(int opcion) {
    system("clear");
    switch (opcion)
    {
    case 1:
        insertarNodo();
        break;
    case 2:
        desplegarNodo();
        break;
    case 3:
        buscarNodo();
        break;
    case 4:
        modificarNodo();
        break;
    case 5:
        cout << "Gracias, hasta pronto" << endl;
        exit(EXIT_SUCCESS);
        break;
    default:
        cout << "Opcion Invalida";
        opcion = 1;
        Pause();
        break;
    }
}

void Menu() {
    do
    {
        cout << "\t.:                  Menu                 :." << endl;
        cout << "\t1. Insertar datos en la lista" << endl;
        cout << "\t2. Mostrar datos en la lista" << endl;
        cout << "\t3. Buscar datos en lista" << endl;
        cout << "\t4. Modificar dato en la lista" << endl;
        cout << "\t5. Salir" << endl;
        cout << "\tPorfavor ingrese una opcion: ";
        cin >> opcion;

        procesarOpcion(opcion);
    } while (opcion != 5);
}

int main() {
    Menu();
    return 0;
}