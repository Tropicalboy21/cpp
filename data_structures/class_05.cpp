#include <iostream>
using namespace std;

int vector2[50], tam, dato, i;

// Definicnio de las funciones cargar y buscar
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

int main()
{
    system("clear");
    cout << "Ingrese el Tamano del Vector: ";
    cin >> tam;
    cargar(vector2, tam);
    mostrar(vector2, tam);
}
