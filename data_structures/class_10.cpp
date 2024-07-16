#include <iostream>
using namespace std;

struct Nodo {
    int dato;
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

void insertarNodo(){
    Nodo *nuevo = new Nodo();
    cout << "Ingrese el dato del nuevo nodo: ";
    cin >> nuevo->dato;
    if(primero == NULL){
        primero = nuevo;
        primero->siguiente = NULL;
        ultimo = primero;
    } else {
        ultimo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        ultimo = nuevo;
    }

    cout << "\nNodo insertado con exito" << endl;
    Pause();
}

void despliegaNodo(){
    Nodo *actual = new Nodo();
    actual = primero;
    int i = 0;

    if(primero != NULL){
        cout << "datos almacenados en la cola" << endl;
    while(actual != NULL){
        cout << "Elemento en posicion " << i << " de la cola: " << actual->dato << endl;
        actual = actual->siguiente;
        i++;
    }
    } else {
        cout << "La cola esta vacia, no hay datos que mostrar" << endl;
    }

    Pause();
}

void buscarNodo(){
    Nodo *actual = new Nodo();
    actual = primero;

    int dato;
    bool encontrado = false;
    int i = 0;

    if(actual != NULL){
        cout << "\nIngrese el dato a buscar en la cola: ";
        cin >> dato;

        while(encontrado != true){
            if(actual->dato == dato){
                cout << "El dato " << dato <<" se encuentra en la posicion " << i << " de la cola" << endl;
                encontrado = true;
                Pause();
                return;
            }
            actual = actual->siguiente;
            i++;
        }
        if (encontrado == false){
            cout << "El dato " << dato << " no es parte de la cola" << endl;
        }
    } else {
        cout << "Lo sentimos la cola se encuentra vacia";
        Pause();
    }
}

void modificarNodo(){
    Nodo *actual = new Nodo();
    actual = primero;

    int dato, nuevoDato;
    bool encontrado = false;

    if(actual != NULL){
        cout << "ingrese el dato que desea modificar";
        cin >> dato;

        cout << "ingrese el nuevo valor: ";
        cin >> nuevoDato;
        while(encontrado != true){
            if(actual->dato == dato){
                actual->dato = nuevoDato;
                encontrado = true;
                Pause();
                return;
            }
            actual = actual->siguiente;
        }
        if(encontrado == false){
            cout << "El dato " << dato << " no es parte de la cola" << endl;
        }
    } else {
        cout << "Lo sentimos la pila se encuentra vacia" << endl;
        Pause();
    }
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
        cout << "\n Opcion digitada es invalida  \n";
        opcion = 1;
        Pause();
        break;
    }
}

void Menu() {
    do
    {
        cout << "\t.:           Menu          :." << endl;
        cout << "\t1. Insertar datos a la Cola" << endl;
        cout << "\t2. Mostrar datos en la Cola" << endl;
        cout << "\t3. Buscar datos en la Cola" << endl;
        cout << "\t4. Modificar dato en la Cola" << endl;
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