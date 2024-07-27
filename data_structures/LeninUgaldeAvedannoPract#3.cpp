#include <iostream>
#include <vector>
#include <algorithm> 
#define EXT 20
using namespace std;

struct Nodo {
    char dato[EXT];
    int prioridad;
    Nodo *siguiente;
}

*primero, *ultimo;
int opcion = 0;

void Pause(){
    cout << "\nPresione enter para continuar";
    cin.ignore();
    cin.get();
    system("cls");
}

Nodo* copiarCola(Nodo *original){
    if(original == NULL){
        return NULL;
    }

    Nodo *copia = new Nodo;
    strncpy(copia->dato, original->dato, EXT);
    copia->prioridad = original->prioridad;
    copia->siguiente = copiarCola(original->siguiente);
    return copia;
}

void limpiarCola(Nodo *&cola){
    while(cola != NULL){
        Nodo *temp = cola;
        cola = cola->siguiente;
        delete temp;
    }
}


void insertarNodo() {
    Nodo *nuevo = new Nodo();
    cout << "Ingrese los elementos del nuevo nodo:" << endl;
    cout << "Dato: ";
    cin >> nuevo->dato;
    cout<< "Prioridad: ";
    cin >> nuevo->prioridad;

    nuevo->siguiente = NULL;

    if(primero == NULL){
        primero = nuevo;
        ultimo = nuevo;
    } else {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
    Pause();
}

void despliegaNodo(Nodo *cola, string& mensaje) {
    if(cola == NULL) {
        cout << "\nLo sentimos, la pila esta vacia." << endl;
        Pause();
        return;
    }
    int i = 0;
    cout << mensaje << "\n" << endl;

    while(cola != NULL) {
        cout << "Posicion en la cola: " << i << ", Prioridad: " << cola->prioridad << ", Dato: " << cola->dato  << endl;
        cola = cola->siguiente;
        i++;
    }
    Pause();
}

void buscarNodo() {
    Nodo *actual = new Nodo();
    actual = primero;
    int i = 0;
    bool encontrado = false;
    char datoBuscado[EXT];
    int prioridadBuscada;

    if(primero != NULL) {
        cout << "Ingrese los elementos que desea buscar en la cola con prioridad: " << endl;
        cout << "Dato: ";
        cin >> datoBuscado;
        cout<< "Prioridad: ";
        cin >> prioridadBuscada;

        while (actual != NULL) {
            if(strcmp(actual->dato, datoBuscado) == 0 && actual->prioridad == prioridadBuscada) {
                cout << "El dato buscado se encuentra en la posicion " << i << " , con el valor " << actual->dato << " , con prioridad " << actual->prioridad << " en la cola" << endl; 
                encontrado = true;
            }
            actual = actual->siguiente;
            i++;
        }
        if(encontrado == false) {
            cout << "\nLo sentimos el dato no es parte de la cola" << endl;
        }
    } else {
        cout << "\nLo sentimos, la cola esta vacia" << endl;
    }
    Pause();
}

void modificarNodo() {
    Nodo *actual = new Nodo();
    actual = primero;
    int i = 0;
    bool encontrado = false;
    char datoBuscado[EXT];
    int prioridadBuscada;

    if(primero != NULL){
        cout << "Ingrese los elementos que desea modificar en la cola" << endl;
        cout << "Dato: ";
        cin >> datoBuscado;
        cout << "Prioridad: ";
        cin >> prioridadBuscada;

        while(actual != NULL){
            if (strcmp(actual->dato, datoBuscado) == 0 && actual->prioridad == prioridadBuscada){
                cout << "El dato buscado se encuentra en la posicion " << i << " , con el valor " << actual->dato << " , con prioridad " << actual->prioridad << " en la cola" << endl;
                cout << "\nIngrese los nuevos elementos: " << endl;
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
        if (encontrado == false) {
            cout << "\nLo sentimos el dato no es parte de la cola" << endl;
        }
    } else {
        cout << "\nLo sentimos, la cola esta vacia" << endl;
    }
    Pause();
}

void eliminarNodo() {
    Nodo *actual = new Nodo();
    Nodo *anterior = NULL;
    actual = primero;
    int i = 0;
    bool encontrado = false;
    char datoBuscado[EXT];
    int prioridadBuscada;

    if(primero != NULL) {
        cout << "Ingrese los elementos que desea Eliminar de la cola con prioridad: " << endl;
        cout << "Dato: ";
        cin >> datoBuscado;
        cout<< "Prioridad: ";
        cin >> prioridadBuscada;

        while (actual != NULL) {
            if(strcmp(actual->dato, datoBuscado) == 0 && actual->prioridad == prioridadBuscada) {
                cout << "El dato fue encontrado en la posicion " << i << " , con el valor " << actual->dato << " , con prioridad " << actual->prioridad << " en la cola" << endl; 
                cout << "\nEliminando dato ...";

                if(anterior == NULL){
                    primero = actual->siguiente;
                } else {
                    anterior->siguiente = actual->siguiente;
                }
                
                delete(actual);
                encontrado = true;
            }
            anterior = actual;
            actual = actual->siguiente;
            i++;
        }
        if(encontrado == false) {
            cout << "Lo sentimos el dato no es parte de la cola" << endl;
        }
    } else {
        cout << "Lo sentimos, la cola esta vacia" << endl;
    }
    Pause();
}

void ordenarAscend() {
    Nodo *actual = new Nodo();
    actual = primero;

    Nodo *copia = copiarCola(actual);
    Nodo *ordenada = NULL;

    while(copia != NULL){
        Nodo *temp = copia;
        copia = copia->siguiente;
        if (ordenada == NULL || temp->prioridad < ordenada->prioridad){
            temp->siguiente = ordenada;
            ordenada = temp;
        } else {
            Nodo *reciente = ordenada;

            while (reciente->siguiente != NULL && reciente->siguiente->prioridad <= temp->prioridad)
            {
                reciente = reciente->siguiente;
            }
            temp->siguiente = reciente->siguiente;
            reciente->siguiente = temp;
        }
    }
    copia = ordenada;

    string mensaje = "Elementos ordenados ascendentemente: ";
    despliegaNodo(copia, mensaje);
    limpiarCola(copia);
    Pause();
}

void ordenarDescend() {
    Nodo *actual = new Nodo();
    actual = primero;

    Nodo *copia = copiarCola(actual);
    Nodo *ordenada = NULL;

    while(copia != NULL){
        Nodo *temp = copia;
        copia = copia->siguiente;
        if (ordenada == NULL || temp->prioridad > ordenada->prioridad){
            temp->siguiente = ordenada;
            ordenada = temp;
        } else {
            Nodo *reciente = ordenada;

            while (reciente->siguiente != NULL && reciente->siguiente->prioridad >= temp->prioridad)
            {
                reciente = reciente->siguiente;
            }
            temp->siguiente = reciente->siguiente;
            reciente->siguiente = temp;
        }
    }
    copia = ordenada;

    string mensaje = "Elementos ordenados descendentemente: ";
    despliegaNodo(copia, mensaje);
    limpiarCola(copia);
    Pause();
}

void Prioridad() {
    Nodo *actual = new Nodo();
    actual = primero;
    int prioridadBuscada;
    bool encontrado = false;
    int contador = 0;
    vector<string> datos;

    if(primero != NULL) {
        cout << "***** Busqueda por prioridad *****" << endl;
        cout << "Ingrese la prioridad de los elementos que desea buscar: ";
        cin >> prioridadBuscada;

        while (actual != NULL) {
            if (actual->prioridad == prioridadBuscada)
            {
                string str(actual->dato);
                contador++;
                datos.push_back(str);
                encontrado = true;
            }
            actual = actual->siguiente;
        }
        if (encontrado == false) {
            cout << "\nNo hay ningun elemento con esa prioridad en la cola" << endl;
        } else {
            if(datos.size() > 1){
                cout << "\nLos elementos con prioridad " << prioridadBuscada << " son:" << endl;
                for(int i = 0; i < datos.size(); i++){
                    cout << datos[i] << endl;
                }
                cout << "\nEl numero de elementos con la prioridad ingresada es: " << contador << endl;

            } else if (datos.size() == 1 ){
                cout << "Solo hay un elemento con prioridad " << prioridadBuscada << " , es: ";
                for(int i = 0; i < datos.size(); i++){
                    cout << datos[i] << endl;
                }
            }
        }
    } else {
        cout << "\nLo sentimos, la cola esta vacia" << endl; 
    }
    Pause();
}

void procesarOpcion(int opcion) {
    system("cls");

    string mensaje = "Elementos almacenados en la cola con prioridades";

    switch (opcion)
    {
    case 1:
        insertarNodo();
        break;
    case 2:
        despliegaNodo(primero, mensaje);
        break;
    case 3:
        buscarNodo();
        break;
    case 4:
        modificarNodo();
        break;
    case 5:
        eliminarNodo();
        break;
    case 6:
        ordenarAscend();
        break;
    case 7:
        ordenarDescend();
        break;
    case 8:
        Prioridad();
        break;
    case 9:
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
    system("cls");
    do
    {
        cout << "\t.:                   Menu                  :." << endl;
        cout << "\t1. Insertar datos a la Cola con prioridad" << endl;
        cout << "\t2. Mostrar datos en la Cola con prioridad" << endl;
        cout << "\t3. Buscar datos en la Cola con prioridad" << endl;
        cout << "\t4. Modificar dato en la Cola con prioridad" << endl;
        cout << "\t5. Eliminar dato en la Cola con prioridad" << endl;
        cout << "\t6. Ordenar elementos de la Cola ascendentemente por prioridad" << endl;
        cout << "\t7. Ordenar elementos de la Cola descendentemente por prioridad" << endl;
        cout << "\t8. Tipo de Prioridad y cantidad" << endl;
        cout << "\t9. Salir" << endl;
        cout << "\tPorfavor ingrese una opcion: ";
        cin >> opcion;

        procesarOpcion(opcion);
    } while (opcion != 9);
}

int main() {
    Menu();
    return 0;
}