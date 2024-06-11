#include <iostream>
using namespace std;

int suma = 0, aumento = 0;

// Definición de las funciones

int *llenar_arreglo(int edades[], int cant)
{
    cout << "\n***** digite las edades a almacenar *****" << endl;
    for (int i = 0; i < cant; i++)
    {
        cout << "Edad No. " << i << " : ";
        cin >> edades[i];
    }

    return (edades);
}

void mostrar_arreglo(int edades[], int cant)
{
    cout << "\n***** Edades almacenadas *****" << endl;
    for (int i = 0; i < cant; i++)
    {
        cout << "Edad No. " << i << " " << edades[i] << endl;
    }
}

void sumar_arreglo(int edades[], int cant)
{
    suma = 0, aumento = 0;
    for (int i = 0; i < cant; i++)
    {
        suma = suma + edades[i];
    }
    aumento = suma *
              +suma;
    cout << "\n La suma de las edades en el vector es igual a: " << suma << endl;
    cout << "\n Dicha suma aumentada en un 50% es igual a: " << aumento << endl;
}

void promedio(int edades[], int cant)
{

    int n = 3;
    double suma;
    double promedio;

    for (int i = 0; i < cant; i++)
    {
        suma = suma + edades[i];
    }

    promedio = suma / n;

    cout << "El promedio de los numeros  el arreglo es: " << promedio << endl;
}

void pause()
{
    std::cout << "Press Enter to continue..." << endl;
    cin.ignore();
    cin.get();
}

int main()
{
    int opcion, edades[50], cant;

    do
    {
        cout << "\n  MENU DE OPCIONES A REALIZAR \n";
        cout << "\n      1.  Llenado de datos    \n";
        cout << "\n      2.  Mostrar Datos    \n";
        cout << "\n      3.  Sumar y Aumentar   \n";
        cout << "\n      4.  Promedio   \n";
        cout << "\n      5.  Salir   \n";
        cout << "\n  Ingresa la opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("clear");
            cout << "\n Digite la cantidad de Edades ingresar: ";
            cin >> cant;
            llenar_arreglo(edades, cant);
            pause();
            break;

        case 2:
            mostrar_arreglo(edades, cant);
            pause();
            break;

        case 3:
            sumar_arreglo(edades, cant);
            pause();
            break;

        case 4:
            promedio(edades, cant);
            pause();
            break;

        case 5:
            exit(EXIT_SUCCESS);

        default:
            cout << "\n Opcion digitada es invalida  \n";
            opcion = 1;
        }

        system("clear");
    } while (opcion <= 5);
}