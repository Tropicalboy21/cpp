#include <iostream>
using namespace std;

void pause()
{
    std::cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
    system("clear");
}

int main()
{
    int valor = 1200;
    int *valorPtr;
    *valorPtr = 78;

    cout << "\nLa variable Valor contiene: " << valor << endl;

    cout << "\nvalorPtr es igual a : " << valorPtr << endl;

    cout << "\nvalor Ptr es igual a : " << *valorPtr << endl;

    pause();
}
