#include <iostream>
using namespace std;

// estructura de la pila NODOS

struct Pilas {
    int valor; 
    Pilas *direc_sig;
}

*pila_original, *pila_aux;
int opcion = 0;

void Pause() {
    std::cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    system("clear");
}

void Push() {
    if(pila_original == NULL){
        pila_original = new(Pilas);
        cout << "\n Digite el dato a ingresar en la Pila: ";
        cin >> pila_original->valor;
        cout << "\n Se ha ingresado el primer dato en la pila";
        pila_original->direc_sig = NULL;
    } else {
        pila_aux = new(Pilas);
        cout << "\nDigite el dato a ingresar en la Pila: ";
        cin >> pila_aux->valor;
        cout << "\nSe ha ingresado el primer dato en la pila" << endl;
        pila_aux->direc_sig = pila_original;
        pila_original = pila_aux;
    }
    Pause();
}

void Pop() {
    if(pila_original == NULL) {
        cout << "\nLo sentimos la pila se encuentra vacia \n";
        Pause();
        return;
    } 

    pila_aux = new(Pilas);
    pila_aux = pila_original;

    cout << "\nEliminando dato ..." << endl;
    cout << "\nEl dato eliminado es: " << pila_aux->valor << endl;

    pila_original = pila_aux->direc_sig;
    delete(pila_aux);
    Pause();
}


void Imprimir() {
    if(pila_original == NULL) {
        cout << "\nLo sentimos la pila se encuentra vacia \n";
        Pause();
        return;
    }
        int i = 0;
        pila_aux = pila_original;

        while(pila_aux != NULL) {
            cout << "\nElemento No. " << i << ":" << pila_aux->valor << endl;
            pila_aux = pila_aux->direc_sig;
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
        cout << "\t4. Salir" << endl;
        cout << "\tPorfavor ingrese una opcion: ";
        cin >> opcion;

        procesarOpcion(opcion);

    } while (opcion != 4);
}

int main() {
    Menu();

    return 0;
}