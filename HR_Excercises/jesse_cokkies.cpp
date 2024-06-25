#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cookies(int k, vector<int> A)
{
    // for this problem we need to use priority_queue item
    // it is necessary due to the time constrain (not always satified using vector)
    priority_queue<int, vector<int>, greater<int> > myPQ;

    // fill the priority queue with out vector A
    for (size_t i = 0; i < A.size(); i++)
    {
        myPQ.push(A[i]);
    }
    int counter = 0;

    while (myPQ.top() < k && myPQ.size() >= 2)
    {
        // store and remove the first two values
        int cookie1 = myPQ.top();
        myPQ.pop();
        int cookie2 = myPQ.top();
        myPQ.pop();

        // insert the new value to priority queue
        myPQ.push(1 * cookie1 + 2 * cookie2);

        // increment the counter
        counter++;
    }
    // Check if the top value of the priotiry queu is lower than the threshold k
    if (myPQ.top() < k)
        return -1;
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