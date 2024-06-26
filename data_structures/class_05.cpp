#include <iostream>
#include <cstdlib>
using namespace std;

int numVector[50], tam, dato, i;

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

void buscar(int vector[50], int tam, int dato)
{

    bool encontrado = true;
    for (i = 0; i < tam; i++)
    {
        if (dato == numVector[i])
        {
            cout << "El dato se encuentra en la posición No. " << i << ": " << "del vector" << endl;
        }
        else
        {
            encontrado = false;
        }
    }

    if (encontrado == false)
    {
        cout << "El dato no se encuentra dentro del vector " << endl;
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
    buscar(numVector, tam, dato);
}
