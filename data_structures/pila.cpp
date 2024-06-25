#include <iostream>
using namespace std;

const int tam_pila = 5;

struct Pila
{
    int top;
    int elementos[tam_pila];
};

struct Pila pila;

void pause()
{
    std::cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    system("clear");
}

void Inicializar() // función para inicializar la pila
{
    pila.top = -1;

    for (int i = 0; i <= tam_pila; i++)
    {
        pila.elementos[i] = 0;
    }
}

bool vacia()
{
    return pila.top == -1;
}

bool llena()
{
    return pila.top == (tam_pila - 1);
}

void Push()
{
    int dato;
    if (llena())
    {
        cout << "\nLo sentimos la pila esta llena" << endl;
    }
    else
    {
        cout << "\nEscriba el dato a insertar en la pila: " << endl;
        cin >> dato;
        pila.top++;
        pila.elementos[pila.top] = dato;

        cout << "\nEl dato fue agregado con exito a la pila!" << endl;
    }
    pause();
}

void Pop()
{
    if (vacia())
    {
        cout << "\nLo sentimos la pila no tiene datos" << endl;
    }
    else
    {
        int temp = pila.elementos[pila.top];

        cout << "\nElemento No. " << temp << " en la posición " << pila.top << " ha sido eliminado \n"
             << endl;

        pila.elementos[pila.top] = 0;
        pila.top--;
    }
    pause();
}

void Imprimir()
{
    if (vacia())
    {
        cout << "\nLo sentimos la pila no tiene datos" << endl;
    }
    else
    {
        for (int i = 0; i <= pila.top; i++)
        {
            cout << "Elemento No. " << i << ": " << pila.elementos[i] << endl;
        }
    }
    pause();
}

int main()
{
    Inicializar();

    int opc = 0;

    do
    {
        cout << "\t.:  MENU DE OPCIONES   .\n";
        cout << "1. Insertar datos a la pila \n";
        cout << "2. Eliminar datos a la pila \n";
        cout << "3. Mostrar datos de la pila  \n";
        cout << "4. salir del programa \n";
        cout << "Ingrese una opcion: ";
        cin >> opc;

        switch (opc)
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
            break;
        }

    } while (opc != 4);
}