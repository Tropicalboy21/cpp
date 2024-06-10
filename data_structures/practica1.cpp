#include <iostream>
#include <cstdlib>
using namespace std;

int valor1, valor2, valor3;

void ingresarValores()
{

    cout << "Porfavor ingrese 3 valores" << endl;
    cout << "Valor 1: ";
    cin >> valor1;
    cout << "Valor 2: ";
    cin >> valor2;
    cout << "Valor 3: ";
    cin >> valor3;
}

void Ord_Num_Asc(int value1, int value2, int value3)
{

    int primerValor, segundoValor, tercerValor;

    if (value1 <= value2 && value1 <= value3)
    {
        primerValor = value1;
        if (value2 <= value3)
        {
            segundoValor = value2;
            tercerValor = value3;
        }
        else
        {
            segundoValor = value3;
            tercerValor = value2;
        }
    }
    else if (value2 <= value1 && value2 <= value3)
    {
        primerValor = value2;
        if (value1 <= value3)
        {
            segundoValor = value1;
            tercerValor = value3;
        }
        else
        {
            segundoValor = value3;
            tercerValor = value1;
        }
    }
    else
    {
        primerValor = value3;
        if (value1 <= value2)
        {
            segundoValor = value1;
            tercerValor = value2;
        }
        else
        {
            segundoValor = value2;
            tercerValor = value1;
        }
    }

    cout << "los valores en orden ascendete son: " << endl;
    cout << primerValor << " ";
    cout << segundoValor << " ";
    cout << tercerValor << endl;
}

void Ord_Num_Des(int value1, int value2, int value3)
{

    int primerValor, segundoValor, tercerValor;

    if (value1 <= value2 && value1 <= value3)
    {
        primerValor = value1;
        if (value2 <= value3)
        {
            segundoValor = value2;
            tercerValor = value3;
        }
        else
        {
            segundoValor = value3;
            tercerValor = value2;
        }
    }
    else if (value2 <= value1 && value2 <= value3)
    {
        primerValor = value2;
        if (value1 <= value3)
        {
            segundoValor = value1;
            tercerValor = value3;
        }
        else
        {
            segundoValor = value3;
            tercerValor = value1;
        }
    }
    else
    {
        primerValor = value3;
        if (value1 <= value2)
        {
            segundoValor = value1;
            tercerValor = value2;
        }
        else
        {
            segundoValor = value2;
            tercerValor = value1;
        }
    }

    cout << "los valores en orden descendente son: " << endl;
    cout << tercerValor << " ";
    cout << segundoValor << " ";
    cout << primerValor << endl;
}

void Promedio(int value1, int value2, int value3)
{

    int n = 3;
    double suma;
    double promedio;

    suma = value1 + value2 + value3;

    promedio = suma / n;

    cout << "El promedio de los numeros " << value1 << ", " << value2 << " y " << value3 << " es: " << promedio << endl;
}

void Aumentar(int value1, int value2, int value3)
{

    double suma;
    double porcentaje = 0.75;
    double aumento;

    suma = value1 + value2 + value3;

    aumento = suma + (suma * porcentaje);

    cout << "El resultado de la suma de los números " << value1 << ", " << value2 << " y " << value3 << ", aumentada en un 75% es: " << aumento << endl;
}

void Mayor(int value1, int value2, int value3)
{

    int minNum, medNum, maxNum;

    if (value1 <= value2 && value1 <= value3)
    {
        minNum = value1;
        if (value2 <= value3)
        {
            medNum = value2;
            maxNum = value3;
        }
        else
        {
            medNum = value3;
            maxNum = value2;
        }
    }
    else if (value2 <= value1 && value2 <= value3)
    {
        minNum = value2;
        if (value1 <= value3)
        {
            medNum = value1;
            maxNum = value3;
        }
        else
        {
            medNum = value3;
            maxNum = value1;
        }
    }
    else
    {
        minNum = value3;
        if (value1 <= value2)
        {
            medNum = value1;
            maxNum = value2;
        }
        else
        {
            medNum = value2;
            maxNum = value1;
        }
    }

    cout << "Entre los números " << value1 << ", " << value2 << ", " << value3 << "el mayor es: " << maxNum << "." << endl;
}

void Menor(int value1, int value2, int value3)
{

    int minNum, medNum, maxNum;

    if (value1 <= value2 && value1 <= value3)
    {
        minNum = value1;
        if (value2 <= value3)
        {
            medNum = value2;
            maxNum = value3;
        }
        else
        {
            medNum = value3;
            maxNum = value2;
        }
    }
    else if (value2 <= value1 && value2 <= value3)
    {
        minNum = value2;
        if (value1 <= value3)
        {
            medNum = value1;
            maxNum = value3;
        }
        else
        {
            medNum = value3;
            maxNum = value1;
        }
    }
    else
    {
        minNum = value3;
        if (value1 <= value2)
        {
            medNum = value1;
            maxNum = value2;
        }
        else
        {
            medNum = value2;
            maxNum = value1;
        }
    }

    cout << "Entre los números " << value1 << ", " << value2 << ", " << value3 << "el menor es: " << minNum << "." << endl;
}

void procesarOpcion(int opcion)
{

    system("clear");
    ingresarValores();
    system("clear");

    switch (opcion)
    {
    case 1:
        Ord_Num_Asc(valor1, valor2, valor3);
        break;
    case 2:
        Ord_Num_Des(valor1, valor2, valor3);
        break;
    case 3:
        Promedio(valor1, valor2, valor3);
        break;
    case 4:
        Aumentar(valor1, valor2, valor3);
        break;
    case 5:
        Mayor(valor1, valor2, valor3);
        break;
    case 6:
        Menor(valor1, valor2, valor3);
        break;
    default:
        cout << "Opcion Invalida" << endl;
        break;
    }

    if (opcion != 7)
    {
        cout << "Presione enter para continuar...";
        cin.ignore();
        cin.get();
    }
}

void menu()
{

    int opcion = -1;

    do
    {
        cout << "      Menu     " << endl;
        cout << "1. Ordenar Números Ascendentemente" << endl;
        cout << "2. Ordenar Números Descendentemente " << endl;
        cout << "3. Promedio " << endl;
        cout << "4. Aumentar " << endl;
        cout << "5. Mayor " << endl;
        cout << "6. Menor " << endl;
        cout << "7. Salir " << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 6)
        {
            procesarOpcion(opcion);
        }
        else if (opcion != 7)
        {
            cout << "Opcion invalida" << endl;
            cout << "Presione enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (opcion != 7);
    cout << "Gracias, hasta pronto" << endl;
}

int main()
{
    menu();
}
