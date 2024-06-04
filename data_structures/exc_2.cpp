#include <iostream>
#include <string>
using namespace std;

int main()
{
    string titulos[3];
    string autores[3];

    cout << "\n ****Por favor ingrese la siguiente información de los libros****\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "\n **** Libro " << i + 1 << "****:\n";
        cout << "titulo: ";
        cin >> titulos[i];
        cout << "autor:";
        cin >> autores[i];
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "\n **** Libro " << i + 1 << "****:\n";
        cout << "titulo:";
        cout << titulos[i];
        cout << "autores:";
        cout << titulos[i];
    }
}