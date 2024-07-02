#include <iostream>
using namespace std;

// Estructura de la Pila Nodos

struct Pilas {
    int valor; 
    Pilas *direc_sig;
}

*primero, *nuevo, *auxiliar;
int opcion = 0;

void Pause(){
    std::cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    system("clear");
}

void Push() {
    nuevo = new(Pilas);
    cout << "\n Digite el dato a ingresar en la Pila: ";
    cin >> nuevo->valor;
    cout << "\n Se ha ingresado el primer dato en la pila";
    nuevo->direc_sig = primero;
    primero = nuevo;
    Pause();
}

void Pop() {
    if(primero == NULL) {
        cout << "\nLo sentimos la pila se encuentra vacia \n";
        Pause();
        return;
    } 

    nuevo = new(Pilas);
    nuevo = primero;
    cout << "\nEliminando dato ..." << endl;
    cout << "\nEl dato eliminado es: " << nuevo->valor << endl;
    primero = nuevo->direc_sig;
    delete(nuevo);
    Pause();
}

void buscarNodo() {
    nuevo = new(Pilas);
    nuevo = primero;
    
    int dato,i=0;
    bool encontrado = false;

    if(nuevo != NULL){
        cout << "\n Digite el dato a buscar dentro de la Pila: ";
        cin >> dato;

        while(nuevo != NULL && encontrado != true){
            if(nuevo->valor == dato){
                cout << "\nEl dato " << dato << " fue encontrado dentro de la Pila, en la posición No. " << i << endl;
                encontrado = true;
                Pause();
                return; 
            }
            nuevo = nuevo->direc_sig;
            i++;
        }    
        if(encontrado == false) {
            cout << "\nEl dato " << dato << " no es parte de la Pila" << endl;
        }
    } else {
        cout << "\nLo sentimos la pila se encuentra vacia \n";
        Pause();
    }
}

void Imprimir() {
    if(primero == NULL) {
        cout << "\nLo sentimos la pila se encuentra vacia \n";
        Pause();
        return;
    }
        int i = 0;
        nuevo = primero;

        while(nuevo != NULL) {
            cout << "\nElemento No. " << i << ": " << nuevo->valor << endl;
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
        Push();
        break;
    case 2:
        Pop();
        break;
    case 3:
        Imprimir();
        break;
    case 4:
        buscarNodo();
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
        cout << "\t1. Insertar datos a la Pila" << endl;
        cout << "\t2. Eliminar datos de la Pila" << endl;
        cout << "\t3. Mostrar datos de la Pila" << endl;
        cout << "\t4. Buscar un dato especifico en la Pila" << endl;
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