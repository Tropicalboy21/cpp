#include <iostream>
#include <string>

using namespace std;

int main()
{
    int cant = 0;
    cout << "Ingrese la cantidad de edades: ";
    cin >> cant;

    int edades[cant];

    for (int i = 0; i < cant; i++)
    {
        cout << "Edad posicion No " << i + 1 << ": ";
        cin >> edades[i];
    }
}