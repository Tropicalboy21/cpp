#include <iostream>
#include <vector>
using namespace std;

int cookies(int k, vector<int> A)
{
    int Asize = A.size();

    std::sort(A.begin(), A.end());

    int counter = 0;

    int smallestCookie = 0;

    int secondSmallestCookie = 0;

    for (int i = 0; i < Asize; i++)
    {
        if (A[i] < k)
        {
            counter++;
        }
    }

    smallestCookie = A[0];

    secondSmallestCookie = A[1];

    A.erase(A.begin());

    A.erase(A.begin());

    cout << counter << endl;

    cout << smallestCookie << ", " << secondSmallestCookie << endl;

    int newValue = 1 * smallestCookie + 2 * secondSmallestCookie;

    A.insert(A.begin(), newValue);

    Asize = A.size();

    cout << "\n\nAfter sorting vector : ";
    for (int i = 0; i < Asize; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}

int main()
{
    int sweeterCookie = 9;

    vector<int> sweetnessValues;

    sweetnessValues.push_back(2);
    sweetnessValues.push_back(7);
    sweetnessValues.push_back(3);
    sweetnessValues.push_back(6);
    sweetnessValues.push_back(4);
    sweetnessValues.push_back(6);

    cookies(sweeterCookie, sweetnessValues);

    return 0;
}