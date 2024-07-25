#include <iostream>
#define EXT 20
using namespace std;

struct Nodo {
    char dato[EXT];
    int prioridad;
    Nodo *siguiente;
}

*primero, *ultimo;
int opcion;

void Pause() {
    std::cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    system("clear");
}

void insertarNodo() {
    Nodo *nuevo = new Nodo();
    cout << "\nIngrese los elementos del nuevo nodo: " << endl;
    cout << "Dato: ";
    cin >> nuevo->dato;
    cout << "Prioridad: "; 
    cin >> nuevo->prioridad;
    cout << "El elemento fue ingresado con exito" << endl;

    if(primero == NULL){
        primero = ultimo = nuevo;
        primero->siguiente = NULL;
    } else {
        if (primero->prioridad > nuevo->prioridad){
            nuevo->siguiente = primero;
            primero = nuevo;
        } else {
            Nodo *actual = primero;

            while(actual->siguiente != NULL && actual->siguiente->prioridad <= nuevo->prioridad) {
                actual = actual->siguiente;
            }

            nuevo->siguiente = actual->siguiente;
            actual->siguiente = nuevo;

            if(nuevo->siguiente == NULL){
                ultimo = nuevo;
            }
        }
    }
}


void despliegaNodo() {
    if(primero != NULL){
        Nodo *actual = primero;
        int i = 0;
        while (actual != NULL)
        {
            cout << "Posicion en la cola " << i << " Prioridad: " << actual->prioridad << " , Dato: " << actual->dato << endl;
            actual = actual->siguiente;
            i++;
        }
    } else {
        cout << "La cola con prioridad esta vacia" << endl;
    }
    Pause();
}

void buscarNodo() {
    
}

void modificarNodo() {
    
}

void procesarOpcion(int opcion) {
    system("clear");
    switch (opcion)
    {
    case 1:
        insertarNodo();
        break;
    case 2:
        despliegaNodo();
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
    system("clear");
    do
    {
        cout << "\t.:                  Menu                 :." << endl;
        cout << "\t1. Insertar datos a la Cola con prioridad" << endl;
        cout << "\t2. Mostrar datos en la Cola con prioridad" << endl;
        cout << "\t3. Buscar datos en la Cola con prioridad" << endl;
        cout << "\t4. Modificar dato en la Cola con prioridad" << endl;
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