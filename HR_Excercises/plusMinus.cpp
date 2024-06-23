#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void plusMinus(vector<int> arr)
{
    int arrSize = arr.size();

    int numberOfNegatives = 0, numberOfPositives = 0, numberOfZeros = 0;

    double negativesRatio, positivesRatio, zerosRatio;

    for (int i = 0; i < arrSize; ++i)
    {
        if (arr[i] > 0)
        {
            numberOfPositives++;
                }
        else if (arr[i] < 0)
        {
            numberOfNegatives++;
        }
        else if (arr[i] == 0)
        {
            numberOfZeros++;
        }
    }

    positivesRatio = static_cast<double>(numberOfPositives) / arrSize;

    negativesRatio = static_cast<double>(numberOfNegatives) / arrSize;

    zerosRatio = static_cast<double>(numberOfZeros) / arrSize;

    cout << fixed << setprecision(6) << positivesRatio << endl;

    cout << fixed << setprecision(6) << negativesRatio << endl;

    cout << fixed << setprecision(6) << zerosRatio << endl;
}

int main()
{
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(0);
    numbers.push_back(-1);
    numbers.push_back(-1);

    plusMinus(numbers);
}
