#include <iostream>
using namespace std;

void pause()
{
    std::cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    system("clear");
}

int main()
{

    int a, b, c;
    int *aPtr;

    a = 7;

    aPtr = &a;

    cout << "\nLa direccion de la variable a es : " << &a << endl;

    cout << "\nEl valor de aPtr es : " << aPtr << endl;

    b = *aPtr * 3;

    cout << "\nEl valor de la variable b es : " << b << endl;

    aPtr = NULL;

    cout << "\nLa direccion de la variable a es: " << &a << endl;

    cout << "\nEl valor de aPtr es : " << aPtr << endl;

    aPtr = &b;

    c = *aPtr + 1500;

    cout << "\nEl valor de la variable c es : " << c << endl;

    pause();
}
