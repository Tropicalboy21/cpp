#include <iostream>
using namespace std;

struct Pila {
    int valor;
    Pila *direc_sig;
}

*primero, *auxiliar, *nuevo;
int opcion = 0;

void Pause() {
    cout << "\n\nPresione enter para continuar";
    cin.ignore();
    cin.get();
    system("clear");
}

void Insertar() {
    nuevo = new(Pila);
    cout << "Ingrese el dato en la pila: ";
    cin >> nuevo->valor;
    cout << "El Dato fue ingresado exitosamente" << endl;
    nuevo->direc_sig = primero;
    primero = nuevo;
    Pause();
}

void Eliminar() {
    if(primero == NULL) {
        cout << "Lo sentimos la pila se encuentra vacia" << endl;
        Pause();
        return;
    }

    nuevo = new(Pila);
    nuevo = primero;
    cout << "Eliminando dato ..." << endl;
    cout << "El dato eliminado es: " << nuevo->valor << endl;
    primero = nuevo->direc_sig;
    delete(nuevo);
    Pause();
}

void buscarDato() {
    nuevo = new(Pila);
    nuevo = primero;
    
    int dato, i = 0;
    bool encontrado = false;

    if (nuevo != NULL){
        cout << "Digite el valor que desea buscar: ";
        cin >> dato;

        while(encontrado != true) {
            if(nuevo->valor == dato){
                cout << "\nEl dato " << dato << " el dato encontrado dentro de la Pila, en la posicion No. " << i << endl;
                encontrado = true;
                Pause();
                return;
            }
            nuevo = nuevo->direc_sig;
            i++;
        }

        if(encontrado == false) {
            cout << "\nLo sentimos, " << dato << "no es parte de la pila." << endl;
        }
    } else {
        cout << "Lo sentimos la pila esta vacia." << endl;
        Pause();
    }
}

void modificarDato() {

}

void eliminarDato() {

}

void mayorMenor() {

}

void ascendDescend() {

}

void sumarAumentar() {

}

void promedioModa() {

}

void Mostrar() {
    if(primero == NULL) {
        cout << "Lo sentimos, la pila esta vacia." << endl;
        Pause();
        return;
    }

    int i = 0;
    nuevo = primero;

    while (nuevo != NULL)
    {
        cout << "Elemento No. " << i << " : " << nuevo->valor << endl;
        nuevo = nuevo->direc_sig;
        i++;
    }
    Pause();
}

void procesarOpcion(int opcion) {
    system("clear");
    switch (opcion)
    {
    case 1:
        Insertar();
        break;
    case 2:
        Eliminar();
        break;
    case 3:
        Mostrar();
        break;
    case 4:
        buscarDato();
        break;
    case 5:
        modificarDato();
        break;
    case 6:
        eliminarDato();
        break;
    case 7:
        mayorMenor();
        break;
    case 8:
        ascendDescend();
        break;
    case 9:
        sumarAumentar();
        break;
    case 10:
        promedioModa();
        break;
    case 11:
        cout << "\nMuchas Gracias, Hasta pronto" << endl;
        exit(EXIT_SUCCESS);
        break;
    default:
        cout << "\nOpcion digitada es invalida";
        Pause();
        break;
    }
}

void menu() {
    do
    {
        cout << "\t:.                     ~ Menu ~                    .:" << endl;
        cout << "\t1. Insertar datos a la pila" << endl;
        cout << "\t2. Eliminar datos al inicio de la pila" << endl;
        cout << "\t3. Mostrar datos de la pila" << endl;
        cout << "\t4. Buscar un dato especifico" << endl;
        cout << "\t5. Modificar un dato especifico" << endl;
        cout << "\t6. Eliminar un dato especifico" << endl;
        cout << "\t7. Mostrar dato menor y mayor de la pila" << endl;
        cout << "\t8. Ordenar ascendentemente y descendentemente la pila" << endl;
        cout << "\t9. Sumar y aumentar datos de la pila" << endl;
        cout << "\t10. Promedio y moda de la pila" << endl;
        cout << "\t11. Salir" << endl;
        cout << "\tIngrese una opcion: ";
        cin >> opcion;

        procesarOpcion(opcion);

    } while (opcion != 11);
}

int main() {
    menu();
    return 0;
}


