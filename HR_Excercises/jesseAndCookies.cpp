#include <iostream>
#include <vector>
using namespace std;

int cookies(int k, vector<int> A)
{

    int counter = 0;

    int smallestCookie = 0;

    int secondSmallestCookie = 0;
    int Asize = A.size();

    std::sort(A.begin(), A.end());

    cout << "\n\nAfter sorting vector : ";
    for (int i = 0; i < Asize; i++)
    {
        cout << A[i] << " ";
    }

    while (A[0] < k)
    {
        counter++;
        smallestCookie = A[0];

        secondSmallestCookie = A[1];

        A.erase(A.begin());

        A.erase(A.begin());

        int newValue = (1 * smallestCookie) + (2 * secondSmallestCookie);

        A.insert(A.begin(), newValue);

        std::sort(A.begin(), A.end());

        Asize = A.size();

        cout << "\n\nAfter sorting vector : ";
        for (int i = 0; i < Asize; i++)
        {
            cout << A[i] << " ";
        }
    }

    cout << "\nnumber of iterations: " << counter << endl;

    return counter;
}

int main()
{
    int sweeterCookie = 7;

    vector<int> sweetnessValues;

    sweetnessValues.push_back(1);
    sweetnessValues.push_back(2);
    sweetnessValues.push_back(3);
    sweetnessValues.push_back(9);
    sweetnessValues.push_back(10);
    sweetnessValues.push_back(12);

    cookies(sweeterCookie, sweetnessValues);

    return 0;
}