#include <iostream>
#include <cstdlib>
using namespace std;

int numVector[50], tam, dato, i;
int izq, der, centro, banda;

// Definicion de las funciones cargar y buscar
void cargar(int vector[50], int tam)
{
    cout << "\n Cargue el Vector con los datos respectivos: \n";
    for (i = 0; i < tam; i++)
    {
        cout << "Componente No. " << i << ": ";
        cin >> vector[i];
    }
}

void mostrar(int vector[50], int tam)
{
    cout << "\n Los Componentes del Vector son: \n";
    for (i = 0; i < tam; i++)
    {
        cout << "Componente No. " << i << ": " << vector[i] << endl;
    }
}

void busqueda_binaria(int vector[50], int tam, int dato)
{
    int izq, der, centro, banda;

    izq = 0;
    der = tam - 1;
    centro = 0;
    banda = 0;

    while (izq <= der && banda == 0)
    {
        centro = (der + izq) / 2;
        if (vector[centro] == dato)
        {
            banda = 1;
        }
        else
        {
            if (dato > vector[centro])
            {
                izq = centro + 1;
            }
            else
            {
                der = centro - 1;
            }
        }
    }

    if (banda == 1)
    {
        cout << "El dato se encuentra en la posición No. " << centro << " del vector" << endl;
    }
    else
    {
        cout << "El dato buscado NO se encuentra dentro del Vector" << endl;
    }
}

void pause()
{
    std::cout << "Press Enter to continue..." << endl;
    getchar();
}

int main()
{
    system("clear");
    cout << "Ingrese el Tamano del Vector: ";
    cin >> tam;
    cargar(numVector, tam);
    system("clear");
    mostrar(numVector, tam);
    pause();
    system("clear");
    cout << "Digite el dato a buscar del vector: ";
    cin >> dato;
    busqueda_binaria(numVector, tam, dato);
}
