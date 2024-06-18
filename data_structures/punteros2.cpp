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

    int *ptr, *apt, *suma;
    ptr = new int;
    *ptr = 1300;
    apt = new int;
    *apt = 700;
    suma = new int;
    *suma = (*ptr) + (*apt);

    cout << "\n \n*ptr es igual a: " << *ptr << endl;
    cout << "ptr es igual a: " << ptr << endl;
    cout << "apt es igual a: " << apt << endl;
    cout << "*apt es igual a: " << *apt << endl;
    cout << "suma es igual a: " << suma << endl;
    cout << "*suma es igual a: " << *suma << endl;

    pause();
}
