#include <iostream>
using namespace std;

void pause()
{
    std::cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    system("cls");
}

int main()
{

    int a;
    int *aPtr;

    a = 7;

    aPtr = &a;

    cout << "\nLa direccion de la variable a es : " << &a << endl;

    cout << "\nEl valor de aPtr es : " << aPtr << endl;

    pause();
}
