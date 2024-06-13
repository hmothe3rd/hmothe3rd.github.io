#include <iostream>
#include <cmath>

using namespace std;

int GCD(int &n1, int &n2);
int Exponent(int &n1, int &n2, int result);
int FibonacciSq(int &n1);
int SumNatural(int &n1);
int Factorial(int n1);

int main()
{
    int n1, n2, result;
    int choice;

    cout
        << "\n[1] - GCD"
        << "\n[2] - Exponent"
        << "\n[3] - Fibonacci Sequence"
        << "\n[4] - Sum of Natural Numbers"
        << "\n[5] - Factorial";

    cout << "\n\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter first number: ";
        cin >> n1;

        cout << "Enter second number: ";
        cin >> n2;

        GCD(n1, n2);
        cout << "\nGCD = " << GCD(n1, n2);
        break;

    case 2:
        cout << "Enter your base: ";
        cin >> n1;

        cout << "Enter your exponent: ";
        cin >> n2;

        Exponent(n1, n2, result);
        cout << "\n"
            << n1 << "^" << n2 << " = " << Exponent(n1, n2, result);
        break;

    case 3:
        cout << "Enter the number of terms: ";
        cin >> n1;

        FibonacciSq(n1);
        break;

    case 4:
        cout << "Enter a positive interger: ";
        cin >> n1;

        SumNatural(n1);

        cout << "\nSum of 1 to " << n1 << " = " << SumNatural(n1);
        break;

    case 5:
        cout << "Enter a positive interger: ";
        cin >> n1;

        Factorial(n1);

        cout << "!" << n1 << " = " << Factorial(n1);
        break;
    }
    return 0;
}

int GCD(int &n1, int &n2)
{
    while (n1 != n2)
    {
        if (n1 > n2)
        {
            n1 -= n2;
        }
        else
        {
            n2 -= n1;
        }
    }

    return n1;
}

int Exponent(int &n1, int &n2, int result)
{
    result = pow(n1, n2);

    return result;
}

int FibonacciSq(int &n1)
{
    int t1 = 0, t2 = 1, nextTerm = 0;

    for (long i = 1; i <= n1; ++i)
    {
        if (i == 1)
        {
            cout << t1 << ", ";
            continue;
        }
        else if (i == 2)
        {
            cout << t2 << ", ";
            continue;
        }

        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;

        cout << nextTerm << ", ";
    }
    return 0;
}

int SumNatural(int &n1)
{

    for (int i = 1; i <= n1; ++i)
    {
        SumNatural(n1) += i;
    }

    return SumNatural(n1);
}

// int SumNatural(int n1, int i, int total)
// {
//     if (i <= n1)
//     {
//         total += i;
//         return SumNatural(n1, i + 1, total);
//     }
//     else
//     {
//         return total;
//     }
// }

int Factorial(int n1)
{

    if (n1 > 1)
    {
        return n1 * Factorial(n1 - 1);
    }
    else
    {
        return 1;
    }
}