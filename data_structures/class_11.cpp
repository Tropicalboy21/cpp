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
        primero = nuevo;
        primero->siguiente = NULL;
        ultimo = nuevo;
    } else {
        ultimo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        ultimo = nuevo;
    }
}

void despliegaNodo() {
    Nodo *actual = new Nodo();
    actual = primero;
    int i = 0;

    if(primero != NULL){
        cout << "Elementos almacenados en la cola con prioridades" << endl;
        while (actual != NULL)
        {
            cout << "Posicion en la cola: " << i << " Prioridad: " << actual->prioridad << ", Dato: " << actual->dato  << endl;
            actual = actual->siguiente;
            i++;
        }
    } else {
        cout << "la cola con prioridad esta vacia" << endl;
    }
    Pause();
}

void buscarNodo() {
    Nodo *actual = new Nodo();
    actual = primero;
    int i = 0;
    bool encontrado = false; 
    char datobuscado[EXT];
    int prioridadBuscada;

    if(primero != NULL){
        cout << "digite los elementos a buscar en la Cola con prioridades: " << endl;
        cout << "Dato: ";
        cin >> datobuscado;
        cout << "Prioridad: ";
        cin >> prioridadBuscada;

        while (encontrado != true)
        {
            if(strcmp(actual->dato,datobuscado) == 0 && actual->prioridad == prioridadBuscada){
                cout << "El dato buscado es igual " << actual->dato << " con prioridad " << actual->prioridad << endl;;
                encontrado = true;
                Pause();
            }
            actual = actual->siguiente;
            i++;
        }
        if(encontrado == false) {
            cout << "El dato buscado no es parte de la cola con prioridad" << endl;
        }
    } else {
        cout << "la cola con prioridad esta vacia" << endl;
    }
    Pause();
}

void modificarNodo() {
    Nodo *actual = new Nodo();
    actual = primero;
    bool encontrado = false;
    char datobuscado[EXT];
    int prioridadBuscada;
    int i = 0;

    if(primero != NULL){
        cout << "digite los elementos a buscar en la Cola con prioridades: " << endl;
        cout << "Dato: ";
        cin >> datobuscado;
        cout << "Prioridad: ";
        cin >> prioridadBuscada;

        while (actual != NULL)
        {
            if(strcmp(actual->dato,datobuscado) == 0 && actual->prioridad == prioridadBuscada){
                cout << "El dato buscado es igual " << actual->dato << " con prioridad " << actual->prioridad << endl;;
                cout << "Digite los elementos con los que se va a modificar el nodo: " << endl;
                cout << "Dato: ";
                cin >> actual->dato;
                cout << "Prioridad: ";
                cin >> actual->prioridad;
                cout << "\n------- Nodo modificado con exito -------" << endl;;

                encontrado = true;
            }
            actual = actual->siguiente;
            i++;
        }
        if(encontrado == false) {
            cout << "El dato buscado no es parte de la cola con prioridad" << endl;
        }
    } else {
        cout << "la cola con prioridad esta vacia" << endl;
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