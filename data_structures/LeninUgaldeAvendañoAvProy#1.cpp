#include <iostream>
#include <vector>
using namespace std;

struct Pila {
    int valor;
    Pila *direc_sig;
}

*primero = NULL, *auxiliar, *nuevo;
int opcion = 0;

void Pause() {
    cout << "\nPresione enter para continuar";
    cin.ignore();
    cin.get();
    system("clear");
}

void Insertar() {
    nuevo = new(Pila);
    cout << "Ingrese el dato en la pila: ";
    cin >> nuevo->valor;
    cout << "\nEl Dato fue ingresado exitosamente" << endl;
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

void Mostrar(Pila *pila, const string& mensaje) {
    if(pila == NULL) {
        cout << "Lo sentimos, la pila esta vacia." << endl;
        Pause();
        return;
    }

    int i = 0;

    cout << mensaje << endl;
    while (pila != NULL) {
        cout << "Elemento No. " << i << " : " << pila->valor << endl;
        pila = pila->direc_sig;
        i++;
    }
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
    nuevo = new(Pila);
    nuevo = primero;

    int dato, nuevoDato, i = 0;
    bool encontrado = false;

    if(primero != NULL) {
        cout << "Ingrese el valor que desea modificar: ";
        cin >> dato;

        cout << "\n\ningrese el nuevo valor: ";  
        cin >> nuevoDato;

        while(encontrado != true) {
            if(nuevo->valor == dato){
                nuevo->valor = nuevoDato;
                cout << "El dato " << dato << " fue encontrado y modificado por el nuevo valor " << nuevoDato << endl;
                encontrado = true;
                Pause();
                return;
            }
            nuevo = nuevo->direc_sig;
            i++;
        }
    } else {
        cout << "Lo sentimos, la pila esta vacia" << endl;
        Pause();
        return;
    }
}

void eliminarDato() {
    nuevo = new(Pila);
    nuevo = primero;
    auxiliar = NULL;

    int dato, i = 0;
    bool encontrado = false;

    if(nuevo != NULL) {
        cout << "Ingrese el valor que desea eliminar: ";
        cin >> dato;

        while (!encontrado) {

            if(nuevo->valor == dato) {
                cout << "Eliminando dato "<< dato <<" ..." << endl;
                cout << "El dato " << nuevo->valor << " fue eliminado." << endl;
            if (auxiliar == NULL) {
                primero = nuevo->direc_sig;
            } else {
                auxiliar->direc_sig = nuevo->direc_sig;
            }
            delete(nuevo);
            encontrado = true;
            Pause();
            return;
            }
            auxiliar = nuevo;
            nuevo = nuevo->direc_sig;
            i++;
        }
    } else {
        cout << "Lo sentimos, el valor ingresado no existe.";
        Pause();
        return;
    }
}

void mayorMenor() {
    if(primero == NULL) {
        cout << "Lo sentimos la pila se encuentra vacia" << endl;
        Pause();
        return;
    }

    nuevo = new(Pila);
    nuevo = primero;
    int mayor = nuevo->valor, menor = nuevo-> valor;

    while(nuevo != NULL){
        if(nuevo->valor > mayor){
            mayor = nuevo->valor;
        } else if(nuevo->valor < menor){
            menor = nuevo->valor;
        }
        nuevo = nuevo->direc_sig;
    }

    cout << "El valor mayor de la Pila es: " << mayor << endl << "El valor menor de la Pila es: " << menor << endl;
    Pause();
}

Pila* copiarPila(Pila *original) {
    if(original == NULL) {
        return NULL;
    }

    Pila *copia = new Pila;
    copia->valor = original->valor;
    copia->direc_sig = copiarPila(original->direc_sig);
    return copia;
}

void limpiarPila(Pila *&pila) {
    while (pila != NULL) {
        Pila *temp = pila;
        pila = pila->direc_sig;
        delete temp;
    }
}

void ordenarAscend(Pila *&copia) {
    Pila *ordenada = NULL;

    while (copia != NULL) {
        Pila *temp = copia;
        copia = copia->direc_sig;

        if(ordenada == NULL || temp->valor < ordenada->valor){
            temp->direc_sig = ordenada;
            ordenada = temp;
        } else {
            Pila *actual = ordenada;

            while (actual->direc_sig != NULL && actual->direc_sig->valor < temp->valor) {
                actual = actual->direc_sig;
            }
            temp->direc_sig = actual->direc_sig;
            actual->direc_sig = temp;
        }
    }
    copia = ordenada;
}

void ordenarDescend(Pila *&copia) {
    Pila *ordenada = NULL;

    while (copia != NULL) {
        Pila *temp = copia;
        copia = copia->direc_sig;

        if(ordenada == NULL || temp->valor > ordenada->valor){
            temp->direc_sig = ordenada;
            ordenada = temp;
        } else {
            Pila *actual = ordenada;

            while (actual->direc_sig != NULL && actual->direc_sig->valor > temp->valor) {
                actual = actual->direc_sig;
            }
            temp->direc_sig = actual->direc_sig;
            actual->direc_sig = temp;
        }
    }
    copia = ordenada;
}

void ascendDescend() {
    if(primero == NULL) {
        cout << "Lo sentimos la pila se encuentra vacia" << endl;
        Pause();
        return;
    }

    // Orden ascendente
    Pila *copia = copiarPila(primero);
    ordenarAscend(copia);
    Mostrar(copia, "La pila ordenada en orden ascendente:");
    limpiarPila(copia);

    // Orden descendente
    copia = copiarPila(primero);
    ordenarDescend(copia);
    Mostrar(copia, "\nLa pila ordenada en orden descendente:");
    limpiarPila(copia);

    Pause();
    
}

void sumarAumentar() {
    if(primero == NULL) {
        cout << "Lo sentimos, la pila esta vacia." << endl;
        Pause();
        return;
    }

    int sum = 0, aumento, resultado;
    nuevo = primero;
    while (nuevo != NULL) {
        sum = sum + nuevo->valor;
        nuevo = nuevo->direc_sig;
    }

    aumento = sum * 1.5;

    resultado = sum + aumento;

    cout << "El resultado de la suma de los datos de la pila es: " << sum << " y dicha suma aumentada en un 150% es: " << resultado << endl;
    Pause();
}

void promedioModa() {
    if(primero == NULL) {
        cout << "Lo sentimos, la pila esta vacia." << endl;
        Pause();
        return;
    }

    int largo = 0;
    double sum = 0;
    double promedio;
    nuevo = primero;

    while (nuevo != NULL) {
        sum = sum + nuevo->valor;
        nuevo = nuevo->direc_sig;
        largo++;
    }

    promedio = sum / largo;

    Pila *copia = copiarPila(primero);
    ordenarAscend(copia);

    vector<int> moda;
    int maxRepeticiones = 0;
    int repeticiones = 1;

    Pila *actual = copia;
    Pila *anterior = copia;

    while (actual->direc_sig != NULL) {
        actual = actual->direc_sig;

        if (anterior->valor == actual->valor) {
            repeticiones++;
        } else {
            if (repeticiones > maxRepeticiones) {
                maxRepeticiones = repeticiones;
                moda.clear();
                moda.push_back(anterior->valor);
            } else if (repeticiones == maxRepeticiones) {
                moda.push_back(anterior->valor);
            }
            repeticiones = 1;
        }
        anterior = actual;
    }

    if (repeticiones > maxRepeticiones) {
        maxRepeticiones = repeticiones;
        moda.clear();
        moda.push_back(anterior->valor);
    } else if (repeticiones == maxRepeticiones) {
        moda.push_back(anterior->valor);
    }

    cout << "El resultado del promedio de los datos de la pila es: " << promedio << endl;
    
    if (maxRepeticiones > 1) {
        if (moda.size() > 1){
            cout << "\nEl resultado de la moda de los datos de la pila es: { ";
            for (int i = 0; i < moda.size(); i++) {
                cout <<  moda[i] << " ";
            }
            cout << "} , con " << maxRepeticiones << " repeticiones cada uno\n";
        } else {
            cout << "\nEl resultado de la moda de los datos de la pila es: ";
            for (int i = 0; i < moda.size(); i++) {
                cout <<  moda[i] << " ";
            }
            cout << ", con " << maxRepeticiones << " repeticiones\n"; 
        }
    } else {
        cout << "\nNo hay valores repetidos en la pila\n";
    }

    limpiarPila(copia);

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
        Mostrar(primero, "Mostando datos de la pila:");
        Pause();
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
        cout << "\nOpcion digitada es invalida\n";
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


