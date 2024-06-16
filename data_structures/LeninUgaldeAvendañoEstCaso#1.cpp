#include <iostream>
#include <cstdlib>
using namespace std;

int vectorInicial[10], tam, opcion;
int vectorSecundario[10], tam2;
int vectorResultado[20];

void pause()
{
    std::cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    system("cls");
}

void Llenado_vector()
{
    do
    {
        cout << "\nIngrese el numero de valores del vector: ";
        cin >> tam;

        if (tam < 1 || tam > 10)
        {
            cout << "El numero de valores debe ser entre 1 y 10" << endl;
        }
    } while (tam < 1 || tam > 10);

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

void Promedio(int vectorInicial[], int tam)
{
    double sum, promedio;

    for (int i = 0; i < tam; i++)
    {
        sum += vectorInicial[i];
    }

    promedio = sum / tam;

    cout << "El resultado del promedio de los numeros contenidos en el arreglo es: " << promedio << endl;
    pause();
}

void SumarAumentar(int vectorInicial[], int tam)
{
    double sum, aumento, resultado;

    for (int i = 0; i < tam; i++)
    {
        sum += vectorInicial[i];
    }

    aumento = sum * 0.5;

    resultado = sum + aumento;

    cout << "El resultado de la suma de los numeros del vector es: " << sum << " y dicha suma aumentada en un 50% es: " << resultado << "." << endl;
    pause();
}

void ordenarVector(int vectorInicial[], int tam)
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
}

void Mayor(int vectorInicial[], int tam)
{
    int Mayor;

    ordenarVector(vectorInicial, tam);

    Mayor = vectorInicial[tam - 1];

    cout << "El dato mayor del vector es: " << Mayor << endl;
    pause();
}

void Menor(int vectorInicial[], int tam)
{
    int Menor;

    ordenarVector(vectorInicial, tam);

    Menor = vectorInicial[0];

    cout << "El dato mayor del vector es: " << Menor << endl;
    pause();
}

void Llenado_vector2()
{
    do
    {
        cout << "\nIngrese el numero de valores del segundo vector: ";
        cin >> tam2;

        if (tam2 < 1 || tam2 > 10)
        {
            cout << "El numero de valores debe ser entre 1 y 10" << endl;
        }
    } while (tam2 < 1 || tam2 > 10);

    for (int i = 0; i < tam2; i++)
    {
        cout << "Ingrese el valor numero " << i + 1 << ": ";
        cin >> vectorSecundario[i];
    }

    pause();
}

void Fusionar(int vectorInicial[], int tam, int vectorSecundario[], int tam2, int vectorResultado[])
{
    int i = 0, j = 0, k = 0;

    // Copy elements from array1 to mergedArray
    while (i < tam)
    {
        vectorResultado[k++] = vectorInicial[i++];
    }

    // Copy elements from array2 to mergedArray
    while (j < tam2)
    {
        vectorResultado[k++] = vectorSecundario[j++];
    }

    // ordenarVector(vectorResultado, tam + tam2);

    cout << "Vector fusionado: ";
    for (int l = 0; l < (tam + tam2); l++)
    {
        cout << vectorResultado[l] << "  ";
    }
    cout << endl;
    pause();
}

void procesarOpcion(int opcion)
{
    system("cls");

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
        Promedio(vectorInicial, tam);
        break;
    case 5:
        SumarAumentar(vectorInicial, tam);
        break;
    case 6:
        Mayor(vectorInicial, tam);
        break;
    case 7:
        Menor(vectorInicial, tam);
        break;
    case 8:
        Llenado_vector2();
        Fusionar(vectorInicial, tam, vectorSecundario, tam2, vectorResultado);
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
        cout << "\n***** Menu *****" << endl;
        cout << "1. Llenar el Vector Principal" << endl;
        cout << "2. Ordenar Numeros Ascendentemente" << endl;
        cout << "3. Ordenar Numeros Descendentemente" << endl;
        cout << "4. Obtener Promedio" << endl;
        cout << "5. Sumar y aumentar" << endl;
        cout << "6. Mostrar Dato Mayor" << endl;
        cout << "7. Mostrar Dato Menor" << endl;
        cout << "8. Fusion de vectores" << endl;
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
