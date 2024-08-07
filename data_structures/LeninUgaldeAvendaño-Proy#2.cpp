#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
}

*primero, *ultimo;
int opcion = 0;

void Pause(){
    cout << "\nPresione enter para continuar";
    cin.ignore();
    cin.get();
    system("clear");
}

Nodo* copiarCola(Nodo *original){
    if(original == NULL){
        return NULL;
    }

    Nodo *copia = new Nodo;
    copia->dato = original->dato;
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
    cout << "Ingrese el dato del nuevo nodo: ";
    cin >> nuevo->dato;

    nuevo->siguiente = NULL;

    if(primero == NULL){
        primero = nuevo;
        ultimo = nuevo;
    } else {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
    cout << "\nNodo insertado con exito" << endl;
    Pause();
}

void Eliminar() {
    if(primero == NULL) {
        cout << "Lo sentimos la cola se encuentra vacia" << endl;
        Pause();
        return;
    }

    Nodo *actual = new Nodo();
    actual = primero;
    
    cout << "Eliminando dato..." << endl;
    cout << "El elemento eliminado es: " << actual->dato;
    primero = actual->siguiente;
    delete(actual);
    Pause();
}

void despliegaNodo(Nodo *cola, const string& mensaje) {
    if(cola == NULL) {
        cout << "\nLo sentimos, la pila esta vacia." << endl;
        Pause();
        return;
    }
    int i = 0;
    cout << mensaje << "\n" << endl;

    while(cola != NULL) {
        cout << "Elemento en posicion " << i << " de la cola: " << cola->dato << endl;
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
    int datoBuscado;

    if(primero != NULL) {
        cout << "Ingrese el elemento que desea buscar en la cola con prioridad: ";
        cin >> datoBuscado;

        while (actual != NULL) {
            if(actual->dato == datoBuscado) {
                cout << "El dato buscado se encuentra en la posicion " << i << " , con el valor " << actual->dato << " en la cola" << endl; 
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
    int datoBuscado;

    if(primero != NULL){
        cout << "Ingrese el elementos que desea modificar en la cola: ";
        cin >> datoBuscado;

        while(actual != NULL){
            if (actual->dato == datoBuscado){
                cout << "El dato buscado se encuentra en la posicion " << i << " , con el valor " << actual->dato << " en la cola" << endl;
                cout << "\nIngrese el nuevo elemento: ";
                cin >> actual->dato;
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
    int datoBuscado;

    if(primero != NULL) {
        cout << "Ingrese el elemento que desea eliminar de la cola: ";
        cin >> datoBuscado;
        while (actual != NULL) {
            if(actual->dato == datoBuscado) {
                cout << "El dato fue encontrado en la posicion " << i << " , con el valor " << actual->dato << " en la cola" << endl; 
                if(anterior == NULL){
                    primero = actual->siguiente;
                    if(primero == NULL){
                        ultimo = NULL;
                    }
                } else {
                    anterior->siguiente = actual->siguiente;
                    if (anterior->siguiente == NULL) {
                        ultimo = anterior;
                    }
                }
                Nodo *temp = actual;
                actual = actual->siguiente;

                delete(temp);
                encontrado = true;
                cout << "\n------- Nodo eliminado con exito -------\n" << endl;;
            } else {
                anterior = actual;
                actual = actual->siguiente;
                i++;
            }
        }
        if(encontrado == false) {
            cout << "\nLo sentimos el dato no es parte de la cola" << endl;
        }
    } else {
        cout << "\nLo sentimos, la cola esta vacia" << endl;
    }
    Pause();
}

void mostrarMayor() {
    if(primero == NULL) {
        cout << "Lo sentimos la cola se encuentra vacia" << endl;
        Pause();
        return;
    }

    Nodo *actual = new Nodo();
    actual = primero;
    int mayor = actual->dato, i = 0;

    while (actual != NULL)
    {
        if(actual->dato > mayor){
            mayor = actual->dato;
        }
        actual = actual->siguiente;
        i++;
    }

    cout << "El dato mayor de la cola es: " << mayor << " y se encuentra en la posición: " << i << endl;
    Pause();

}

void mostrarMenor() {
    if(primero == NULL) {
        cout << "Lo sentimos la cola se encuentra vacia" << endl;
        Pause();
        return;
    }

    Nodo *actual = new Nodo();
    actual = primero;
    int menor = actual->dato, i = 0;

    while (actual != NULL)
    {
        if(actual->dato < menor){
            menor = actual->dato;
        }
        actual = actual->siguiente;
        i++;
    }
    
    cout << "El dato menor de la cola es: " << menor << " y se encuentra en la posición: " << i << endl;
    Pause();   
}

void ordenarAscend() {
    if(primero == NULL) {
        cout << "Lo sentimos la cola se encuentra vacia" << endl;
        Pause();
        return;
    }

    Nodo *actual = new Nodo();
    actual = primero;

    Nodo *copia = copiarCola(actual);
    Nodo *ordenada = NULL;

    while(copia != NULL){
        Nodo *temp = copia;
        copia = copia->siguiente;
        if (ordenada == NULL || temp->dato < ordenada->dato){
            temp->siguiente = ordenada;
            ordenada = temp;
        } else {
            Nodo *reciente = ordenada;
            while (reciente->siguiente != NULL && reciente->siguiente->dato <= temp->dato)
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
}

void ordenarDescend() {
    if(primero == NULL) {
        cout << "Lo sentimos la cola se encuentra vacia" << endl;
        Pause();
        return;
    }

    Nodo *actual = new Nodo();
    actual = primero;

    Nodo *copia = copiarCola(actual);
    Nodo *ordenada = NULL;

    while(copia != NULL){
        Nodo *temp = copia;
        copia = copia->siguiente;
        if (ordenada == NULL || temp->dato > ordenada->dato){
            temp->siguiente = ordenada;
            ordenada = temp;
        } else {
            Nodo *reciente = ordenada;
            while (reciente->siguiente != NULL && reciente->siguiente->dato >= temp->dato)
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
}

void procesarOpcion(int opcion) {
    system("clear");

    string mensaje = "Elementos almacenados en la cola";

    switch (opcion)
    {
    case 1:
        insertarNodo();
        break;
    case 2:
        Eliminar();
        break;
    case 3:
        despliegaNodo(primero, mensaje);
        break;
    case 4:
        buscarNodo();
        break;
    case 5:
        modificarNodo(); 
        break;
    case 6:
        eliminarNodo(); // eliminar todas las repeticiones
        break;
    case 7:
        mostrarMayor();
        break;
    case 8:
        mostrarMenor();
        break;
    case 9:
        ordenarDescend();
        break;
    case 10:
        ordenarAscend();
        break;
    case 11:
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
        cout << "\t.:                   Menu                  :." << endl;
        cout << "\t1. Insertar datos a la Cola" << endl;
        cout << "\t2. Eliminar datos al inicio de la Cola" << endl;
        cout << "\t3. Mostrar datos en la Cola" << endl;
        cout << "\t4. Buscar datos en la Cola" << endl;
        cout << "\t5. Modificar dato en la Cola" << endl;
        cout << "\t6. Eliminar dato especifico de la Cola" << endl;
        cout << "\t7. Mostrar Dato Mayor de la cola y su posición" << endl;
        cout << "\t8. Mostrar Dato Menor de la cola y su posición" << endl;
        cout << "\t9. Ordenar elementos de la Cola descendentemente" << endl;
        cout << "\t10. Ordenar elementos de la Cola ascendentemente" << endl;
        cout << "\t11. Salir" << endl;
        cout << "\tPorfavor ingrese una opcion: ";
        cin >> opcion;
        procesarOpcion(opcion);
    } while (opcion != 11);
}

int main() {
    Menu();
    return 0;
}