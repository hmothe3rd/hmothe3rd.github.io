#include <iostream>

class Queue {
private:
    int front;
    int rear;
    int arr[5];

public:
    Queue() {
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == 4);
    }

    void enqueue(int val) {
        if (isFull()) {
            std::cout << "Queue full" << std::endl;
            return;
        } else if (isEmpty()) {
            rear = 0;
            front = 0;
            arr[rear] = val;
        } else {
            rear++;
            arr[rear] = val;
        }
    }

    int dequeue() {
        int x = 0;
        if (isEmpty()) {
            std::cout << "Queue is Empty" << std::endl;
            return x;
        } else if (rear == front) {
            x = arr[rear];
            rear = -1;
            front = -1;
            return x;
        } else {
            x = arr[front];
            front++;
            return x;
        }
    }

    int count() {
        if (isEmpty()) return 0;
        return (rear - front + 1);
    }

    void display() {
        std::cout << "All values in the Queue are - ";
        for (int i = 0; i < 5; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue q1;
    int value, option;

    do {
        std::cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << std::endl;
        std::cout << "1. Enqueue()" << std::endl;
        std::cout << "2. Dequeue()" << std::endl;
        std::cout << "3. isEmpty()" << std::endl;
        std::cout << "4. isFull()" << std::endl;
        std::cout << "5. count()" << std::endl;
        std::cout << "6. display()" << std::endl;
        std::cout << "7. Clear Screen()" << std::endl;

        std::cin >> option;

        switch (option) {
            case 0:
                break;

            case 1:
                std::cout << "Enqueue Operation\nEnter an item to Enqueue in the Queue: ";
                std::cin >> value;
                q1.enqueue(value);
                break;

            case 2:
                std::cout << "Dequeue Operation\nDequeued Value: " << q1.dequeue() << std::endl;
                break;

            case 3:
                if (q1.isEmpty())
                    std::cout << "Queue is empty" << std::endl;
                else
                    std::cout << "Queue is not empty" << std::endl;
                break;

            case 4:
                if (q1.isFull())
                    std::cout << "Queue is Full" << std::endl;
                else
                    std::cout << "Queue is not Full" << std::endl;
                break;

            case 5:
                std::cout << "Count Operation\nCount of items in Queue: " << q1.count() << std::endl;
                break;

            case 6:
                std::cout << "Display Function Called - " << std::endl;
                q1.display();
                break;

            case 7:
                system("cls");  
                break;

            default:
                std::cout << "Enter Proper Option Number" << std::endl;
                break;
        }
    } while (option != 0);

    return 0;
}
