#include <iostream>

int hcf(int n1, int n2);
int calculatePower(int base, int powerRaised);
void generateFibonacciSeries(int x);
int add(int n);
int factorial(int n);
void showMenu();
void handleMenuChoice(int choice);

int main() {
    int choice;

    do {
        showMenu();
        std::cin >> choice;
        if (choice != 6) {
            system("cls");
        }
        handleMenuChoice(choice);
    } while (choice != 6);

    return 0;
}

void showMenu() {
    std::cout << "\nChoose an option:\n";
    std::cout << "1. Calculate H.C.F\n";
    std::cout << "2. Calculate Power\n";
    std::cout << "3. Generate Fibonacci Series\n";
    std::cout << "4. Calculate Sum of Natural Numbers\n";
    std::cout << "5. Calculate Factorial\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

void handleMenuChoice(int choice) {
    switch (choice) {
        case 1: {
            int n1, n2;
            std::cout << "Enter two positive integers: ";
            std::cin >> n1 >> n2;
            std::cout << "H.C.F of " << n1 << " & " << n2 << " is: " << hcf(n1, n2) << std::endl;
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            int base, powerRaised;
            std::cout << "Enter base number: ";
            std::cin >> base;
            std::cout << "Enter power number (positive integer): ";
            std::cin >> powerRaised;
            int result = calculatePower(base, powerRaised);
            std::cout << base << "^" << powerRaised << " = " << result << std::endl;
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            int x;
            std::cout << "Enter the number of terms of series: ";
            std::cin >> x;
            std::cout << "Fibonacci Series: ";
            generateFibonacciSeries(x);
            std::cout << std::endl;
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            int n;
            std::cout << "Enter a positive integer: ";
            std::cin >> n;
            std::cout << "Sum = " << add(n) << std::endl;
            system("pause");
            system("cls");
            break;
        }
        case 5: {
            int n;
            std::cout << "Enter a positive integer: ";
            std::cin >> n;
            std::cout << "Factorial of " << n << " = " << factorial(n) << std::endl;
            system("pause");
            system("cls");
            break;
        }
        case 6:
            std::cout << "Exiting the program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            system("pause");
            system("cls");
    }
}

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

void generateFibonacciSeries(int x) {
    int t1 = 0, t2 = 1, nextTerm;
    for (int i = 0; i < x; ++i) {
        std::cout << t1 << " ";
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
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