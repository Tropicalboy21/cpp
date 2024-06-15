#include <iostream>
#include <cstdlib>
using namespace std;

int vectorInicial[10], tam, opcion;

void pause()
{
    std::cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
    system("clear");
}

void Llenado_vector()
{
    cout << "Ingrese el tamaño del vector: ";
    cin >> tam;

    for (int i = 0; i < tam; i++)
    {
        cout << "Ingrese el valor numero " << i + 1 << ": ";
        cin >> vectorInicial[i];
    }

    pause();
}

void Ord_Num_Asc(int vectorInicial[], int tam)
{
    bool ordenado;

    for (int i = 0; i < tam; ++i)
    {
        ordenado = false;
        for (int j = 0; j < tam - i - 1; ++j)
        {
            if (vectorInicial[j] > vectorInicial[j + 1])
            {
                swap(vectorInicial[j], vectorInicial[j + 1]);
                ordenado = true;
            }
        }
        if (!ordenado)
        {
            break;
        }
    }

    cout << "Vector ordenado en forma ascendente: ";
    for (int i = 0; i < tam; i++)
    {
        cout << vectorInicial[i] << " ";
    }
    cout << endl;
    pause();
}

void Ord_Num_Des(int vectorInicial[], int tam)
{
    bool ordenado;
    for (int i = 0; i < tam; ++i)
    {
        ordenado = false;
        for (int j = 0; j < tam - i - 1; ++j)
        {
            if (vectorInicial[j] < vectorInicial[j + 1])
            {
                swap(vectorInicial[j], vectorInicial[j + 1]);
                ordenado = true;
            }
        }
        if (!ordenado)
        {
            break;
        }
    }

    cout << "Vector ordenado en forma descendente: ";
    for (int i = 0; i < tam; i++)
    {
        cout << vectorInicial[i] << " ";
    }
    cout << endl;
    pause();
}

void Promedio()
{
}

void SumarAumentar()
{
}

void Mayor()
{
}

void Menor()
{
}

void Fusionar()
{
}

void procesarOpcion(int opcion)
{
    system("clear");

    switch (opcion)
    {
    case 1:
        Llenado_vector();
        break;
    case 2:
        Ord_Num_Asc(vectorInicial, tam);
        break;
    case 3:
        Ord_Num_Des(vectorInicial, tam);
        break;
    case 4:
        Promedio();
        break;
    case 5:
        SumarAumentar();
        break;
    case 6:
        Mayor();
        break;
    case 7:
        Menor();
        break;
    case 8:
        Fusionar();
        break;
    case 9:
        cout << "Gracias, hasta pronto" << endl;
        exit(EXIT_SUCCESS);
        break;
    default:
        cout << "\n Opcion digitada es invalida  \n";
        opcion = 1;
        pause();
        break;
    }
}

void menu()
{
    do
    {
        cout << "***** Menu *****" << endl;
        cout << "1. Llenar el Vector Principal" << endl;
        cout << "2. Ordenar Números Ascendentemente" << endl;
        cout << "3. Ordenar Números Descendentemente" << endl;
        cout << "4. Obtener Promedio" << endl;
        cout << "5. Sumar y aumentar" << endl;
        cout << "6. Mostrar Dato Mayor" << endl;
        cout << "7. Mostrar Dato Menor" << endl;
        cout << "8. Fusión de vectores" << endl;
        cout << "9. Salir" << endl;
        cout << "Porfavor ingrese una opcion: ";
        cin >> opcion;

        procesarOpcion(opcion);

    } while (opcion != 9);
}

int main()
{
    menu();
}
