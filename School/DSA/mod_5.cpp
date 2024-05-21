// This program demonstrates the IntQueue class
#include <iostream>
#include "IntQueue.h"

using namespace std;

int main()
{
    IntQueue iQueue(5);
    cout << "Enqueuing 5 items...\n";
    // Enqueue 5 items.
    for (int x = 0; x < 5; x++)
        iQueue.enqueue(x);
    // Attempt to enqueue a 6th item.
    cout << "Now attempting to enqueue again...\n";
    iQueue.enqueue(5);
    // Dequeue and retrieve all items in the queue
    cout << "The values in the queue were:\n";
    while (!iQueue.isEmpty())
    {
        int value;
        iQueue.dequeue(value);
        cout << value << endl;
    }
    return 0;
}
