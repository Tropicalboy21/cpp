#include <iostream>
#include <stack>
using namespace std;

// Manejo de una pila estática

stack<int> pila, pila1, pila2;

int menor = 0;
int mayor = 0;

int main()
{

    pila.push(35);
    pila.push(23);
    pila.push(12);
    pila.push(94);
    pila.push(22);

    pila1 = pila;

    pila2 = pila;

    while (!pila.empty())
    {
        cout << pila.top() << endl;
        pila.pop();
    }

    while (!pila1.empty())
    {
        if (pila1.top() > mayor)
        {
            mayor = pila1.top();
        }
        pila1.pop();
    }

    cout << "\n"
         << mayor << endl;

    menor = pila2.top();

    while (!pila2.empty())
    {
        if (pila2.top() < menor)
        {
            menor = pila2.top();
        }
        pila2.pop();
    }

    cout << "\n"
         << menor << endl;

    return 0;
}