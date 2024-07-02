#include <iostream>
using namespace std;

// estructura de la pila NODOS

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
    primero = new(Pilas);
    cout << "\n Digite el dato a ingresar en la Pila: ";
    cin >> nuevo->valor;
    cout << "\n Se ha ingresado el primer dato en la pila";
    nuevo->direc_sig = primero;
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

void Imprimir() {
    if(primero == NULL) {
        cout << "\nLo sentimos la pila se encuentra vacia \n";
        Pause();
        return;
    }
        int i = 0;
        nuevo = primero;

        while(nuevo != NULL) {
            cout << "\nElemento No. " << i << ":" << nuevo->valor << endl;
            nuevo = nuevo->direc_sig;
            i++;
        }
    Pause();
}