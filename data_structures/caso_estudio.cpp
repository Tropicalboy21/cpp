#include <iostream>
#include <cstdlib>
using namespace std;

int vectorInicial[10];

void Llenado_vector()
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
        //  Ord_Num_Asc();
        break;
    case 3:
        //  Ord_Num_Des();
        break;
    case 4:
        //  Promedio();
        break;
    case 5:
        //  SumarAumentar();
        break;
    case 6:
        //  Mayor();
        break;
    case 7:
        //  Menor();
        break;
    case 8:
        //  Fusionar();
        break;
    case 9:
        exit(EXIT_SUCCESS);
        break;
    default:
        cout << "Opcion Invalida" << endl;
        break;
    }
}

void menu()
{
    int opcion = 0;

    do
    {
        cout << "***** Menu *****" << endl;
        cout << "1. llenar el vector" << endl;
        cout << "2. Ordenar numeros ascendentemente" << endl;
        cout << "3. Ordenar Números Descendentemente" << endl;
        cout << "4. Obtener Promedio" << endl;
        cout << "5. Sumar y aumentar" << endl;
        cout << "6. Mostrar Dato Mayor" << endl;
        cout << "7. Mostrar Dato Menor" << endl;
        cout << "8. Fusion de vectores" << endl;
        cout << "9. salir" << endl;
        cout << "Porfavor ingrese una opcion: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 8)
        {
            procesarOpcion(opcion);
        }
        else if (opcion != 9)
        {
            cout << "Opcion invalida" << endl;
            cout << "Presione enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (opcion != 9);
    cout << "Gracias, hasta pronto" << endl;
}

int main()
{
    menu();
}
