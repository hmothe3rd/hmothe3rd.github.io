#include <iostream>

class IntQueue
{
private:
    int *queueArray;
    int queueSize;
    int front;
    int rear;
    int numItems;

public:
    IntQueue(int);
    ~IntQueue();
    void enqueue(int);
    void dequeue(int &);
    bool isEmpty();
    bool isFull();
    void clear();
};

//*************************
// Constructor *
//*************************
IntQueue::IntQueue(int s)
{
    queueArray = new int[s];
    queueSize = s;
    front = 0;
    rear = 0;
    numItems = 0;
}

//*************************
// Destructor *
//*************************
IntQueue::~IntQueue()
{
    delete[] queueArray;
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue. *
//********************************************
void IntQueue::enqueue(int num)
{
    if (isFull())
        std::cout << "The queue is full.\n";
    else
    {
        // Insert new item
        queueArray[rear] = num;
        // Calculate the new rear position
        rear = (rear + 1) % queueSize;
        // Update item count
        numItems++;
    }
}

//*********************************************
// Function dequeue removes the value at the *
// front of the queue, and copies it into num. *
//*********************************************
void IntQueue::dequeue(int &num)
{
    if (isEmpty())
        std::cout << "The queue is empty.\n";
    else
    {
        // Retrieve the front item
        num = queueArray[front];
        // Move front
        front = (front + 1) % queueSize;
        // Update item count
        numItems--;
    }
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise. *
//*********************************************
bool IntQueue::isEmpty()
{
    return numItems == 0;
}

//********************************************
// Function isFull returns true if the queue *
// is full, and false otherwise. *
//********************************************
bool IntQueue::isFull()
{
    return numItems == queueSize;
}

//*******************************************
// Function clear resets the front and rear *
// indices, and sets numItems to 0. *
//*******************************************
void IntQueue::clear()
{
    front = 0;
    rear = 0;
    numItems = 0;
}
