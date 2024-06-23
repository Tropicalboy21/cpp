#include <iostream>
using namespace std;

string kangaroo(int x1, int v1, int x2, int v2)
{

    if (v1 > v2 && (x2 - x1) % (v1 - v2) == 0)
    {
        cout << "YES" << endl;
        return "YES";
    }
    else
    {
        cout << "NO" << endl;
        return "NO";
    }
}

int main()

{

    kangaroo(0, 2, 5, 3);
    kangaroo(0, 3, 4, 2);
}