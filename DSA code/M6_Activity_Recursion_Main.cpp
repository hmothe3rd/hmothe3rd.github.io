#include <iostream>
using namespace std;

int hcf(int n1, int n2);
int calculatePower(int base, int powerRaised);
int fib(int x);
int add(int n);
int factorial(int n);
void showMenu();
void handleMenuChoice(int choice);

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;
        system("cls");
        handleMenuChoice(choice);
    } while (choice != 6);

    return 0;
}

void showMenu() {
    cout << "\nChoose an option:\n";
    cout << "1. Calculate H.C.F\n";
    cout << "2. Calculate Power\n";
    cout << "3. Generate Fibonacci Series\n";
    cout << "4. Calculate Sum of Natural Numbers\n";
    cout << "5. Calculate Factorial\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

void handleMenuChoice(int choice) {
    switch (choice) {
        case 1: {
            int n1, n2;
            cout << "Enter two positive integers: ";
            cin >> n1 >> n2;
            cout << "H.C.F of " << n1 << " & " <<  n2 << " is: " << hcf(n1, n2) << endl;
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            int base, powerRaised;
            cout << "Enter base number: ";
            cin >> base;
            cout << "Enter power number(positive integer): ";
            cin >> powerRaised;
            int result = calculatePower(base, powerRaised);
            cout << base << "^" << powerRaised << " = " << result << endl;
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            int x;
            cout << "Enter the number of terms of series: ";
            cin >> x;
            cout << "Fibonacci Series: ";
            for (int i = 0; i < x; i++) {
                cout << fib(i) << " ";
            }
            cout << endl;
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            int n;
            cout << "Enter a positive integer: ";
            cin >> n;
            cout << "Sum = " << add(n) << endl;
            system("pause");
            system("cls");
            break;
        }
        case 5: {
            int n;
            cout << "Enter a positive integer: ";
            cin >> n;
            cout << "Factorial of " << n << " = " << factorial(n) << endl;
            system("pause");
            system("cls");
            break;
        }
        case 6:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
            system("cls");
    }
}

// Function definitions
int hcf(int n1, int n2) {
    if (n2 != 0)
        return hcf(n2, n1 % n2);
    else 
        return n1;
}

int calculatePower(int base, int powerRaised) {
    if (powerRaised != 0)
        return base * calculatePower(base, powerRaised - 1);
    else
        return 1;
}

int fib(int x) {
    if ((x == 1) || (x == 0))
        return x;
    else
        return fib(x - 1) + fib(x - 2);
}

int add(int n) {
    if (n != 0)
        return n + add(n - 1);
    return 0;
}

int factorial(int n) {
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}