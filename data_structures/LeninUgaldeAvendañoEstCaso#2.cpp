#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
}

*primero, *ultimo;
int opcion = 0;

void Pause() {
    cout << "\nPresione Enter para continuar." << endl;
    cin.get();
    cin.ignore();
    system("clear");
}

Nodo* copiarLista(Nodo *original){
    if(original == NULL){
        return NULL;
    }

    Nodo *copia = new Nodo();
    copia->dato = original->dato;
    copia->siguiente = copiarLista(original->siguiente);
    return copia;
}

void limpiarLista(Nodo *&lista) {
    while(lista != NULL) {
        Nodo *temp = lista;
        lista = lista->siguiente;
        delete(temp);
    }
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

void desplegarNodo(Nodo *lista, const string &mensaje) {
    if(lista == NULL){
        cout << "Lo sentimos la lista esta vacia" << endl;
        Pause();
        return;
    }

    int i = 0;
    cout << mensaje << "\n" << endl;

    while(lista != NULL) {
        cout << "Dato en la posicion " << i << "  con valor: " << lista->dato << endl;
        lista = lista->siguiente;
        i++;
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
                cout << "\n----- El Dato fue modificado con exito -----\n" << endl;
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

void eliminarNodo() {
    Nodo *actual = new Nodo();
    Nodo *anterior = NULL;
    int i = 0, datoBuscado;
    bool encontrado = false;

    actual = primero;

    if(primero != NULL) {
        cout << "Ingrese el valor que desea eliminar: ";
        cin >> datoBuscado;
        
        while(actual != NULL) {
            if(actual->dato == datoBuscado){
                cout << "El dato fue encontrado en la posicion " << i << " , con el valor: " << actual->dato << endl;

                if(anterior == NULL){
                    primero = actual->siguiente;
                    if(primero == NULL){
                        ultimo = NULL;
                    }
                } else {
                    anterior->siguiente = actual->siguiente;
                    if(anterior->siguiente == NULL){
                        ultimo = anterior;
                    }
                }

                delete(actual);
                cout << "\n----- Dato eliminado con exito -----\n";
                encontrado = true;
            }
            anterior = actual;
            actual = actual->siguiente;
            i++;
        }
        if(encontrado == false) {
            cout << "lo sentimos el dato no forma parte de la lista" << endl;
        }
    } else {
        cout << "Lo sentimos la lista se encuentra vacia" << endl;
    }
    Pause();
}

void ordenarAscend() {
    if(primero == NULL){
        cout << "Lo sentimos la lista esta vacia" << endl;
        Pause();
        return;
    }

    Nodo *actual = new Nodo();
    actual = primero;
    Nodo *copia = copiarLista(actual);
    Nodo *ordenada = NULL;

    while(copia != NULL) {
        Nodo *temp = copia;
        copia = copia->siguiente;

        if(ordenada == NULL || temp->dato < ordenada->dato){
            temp->siguiente = ordenada;
            ordenada = temp;
        } else {
            Nodo *reciente = ordenada;
            while(reciente->siguiente != NULL && reciente->siguiente->dato <= temp->dato) {
                reciente = reciente->siguiente;
            }
            temp->siguiente = reciente->siguiente;
            reciente->siguiente = temp;
        }
    }

    copia = ordenada;

    string mensaje = "Lista ordenada ascendentemente";
    desplegarNodo(copia, mensaje);
    limpiarLista(copia);
}

void ordenarDescend() {
    if(primero == NULL){
        cout << "Lo sentimos la lista esta vacia" << endl;
        Pause();
        return;
    }

        Nodo *actual = new Nodo();
    actual = primero;
    Nodo *copia = copiarLista(actual);
    Nodo *ordenada = NULL;

    while(copia != NULL) {
        Nodo *temp = copia;
        copia = copia->siguiente;

        if(ordenada == NULL || temp->dato > ordenada->dato){
            temp->siguiente = ordenada;
            ordenada = temp;
        } else {
            Nodo *reciente = ordenada;
            while(reciente->siguiente != NULL && reciente->siguiente->dato >= temp->dato) {
                reciente = reciente->siguiente;
            }
            temp->siguiente = reciente->siguiente;
            reciente->siguiente = temp;
        }
    }

    copia = ordenada;

    string mensaje = "Lista ordenada descendentemente";
    desplegarNodo(copia, mensaje);
    limpiarLista(copia);
}

void primeroUltimo() {
    if(primero == NULL){
        cout << "Lo sentimos la lista esta vacia" << endl;
        Pause();
        return;
    }

    Nodo *actual = new Nodo();
    Nodo *anterior = NULL;
    actual = primero;
    int i = 0, primerValor, ultimoValor;

    while(actual != NULL){
        if(anterior == NULL){
            primerValor = actual->dato;
            cout << "Primer dato es: " << primerValor << "          ";
        }

        if(actual->siguiente == NULL){
            ultimoValor = actual->dato;
            cout << "Ultimo dato es: " << ultimoValor << endl;
        }
        anterior = actual;
        actual = actual->siguiente;
        i++;
    }
    Pause();
}

void mayorMenor() {
        if(primero == NULL){
        cout << "Lo sentimos la lista esta vacia" << endl;
        Pause();
        return;
    }

    Nodo *actual = new Nodo();
    actual = primero;
    int i = 0, menor, mayor;

        while(actual != NULL){
            if(actual->dato < menor){
                menor = actual->dato;
            } else if(actual->dato > mayor){
                mayor = actual->dato;
            }
            actual = actual->siguiente;
            i++;
        }
    
    cout << "Dato menor de la lista: " << menor << "          " << "Dato mayor de la lista: " << mayor << endl;

    Pause();
}

void procesarOpcion(int opcion) {
    system("clear");

    string mensaje = "Datos almacenados en la lista dinamica enlazada";

    switch (opcion)
    {
    case 1:
        insertarNodo();
        break;
    case 2:
        desplegarNodo(primero, mensaje);
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
        primeroUltimo();
        break;
    case 9:
        mayorMenor();
        break;
    case 10:
        cout << "Gracias, hasta pronto\n" << endl;
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
        cout << "\t1. Insertar datos en la lista" << endl;
        cout << "\t2. Mostrar datos en la lista" << endl;
        cout << "\t3. Mostrar dato específico y posición en la Lista" << endl;
        cout << "\t4. Modificar dato específico de la lista" << endl;
        cout << "\t5. Eliminar dato específico de la lista" << endl;
        cout << "\t6. Ordenar Datos Ascendentemente de la Lista" << endl;
        cout << "\t7. Ordenar Datos Descendentemente de la Lista" << endl;
        cout << "\t8. Mostrar el primer dato y el último dato de la lista" << endl;
        cout << "\t9. Mostrar Dato Mayor y Menor de la Lista" << endl;
        cout << "\t10. Salir" << endl;
        cout << "\tPorfavor ingrese una opcion: ";
        cin >> opcion;

        procesarOpcion(opcion);
    } while (opcion != 10);
}

int main() {
    Menu();
    return 0;
}