// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    return a / b;
}

int modulusOperation(int a, int b)
{
    return a % b;
}

double power(double a, double b)
{
    return pow(a, b);
}

int main()
{
    int choice = 0;
    double a, b;

    while (choice != 7)
    {
        cout << "\n1. Addition";
        cout << "\n2. Subtraction";
        cout << "\n3. Multiplication";
        cout << "\n4. Division";
        cout << "\n5. Modulus";
        cout << "\n6. Exponentiation";
        cout << "\n7. Quit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 7)
        {
            cout << "Goodbye!";
            break;
        }

        cout << "Enter first number: ";
        cin >> a;

        cout << "Enter second number: ";
        cin >> b;

        switch (choice)
        {
            case 1:
                cout << "Result: " << add(a, b);
                break;

            case 2:
                cout << "Result: " << subtract(a, b);
                break;

            case 3:
                cout << "Result: " << multiply(a, b);
                break;

            case 4:
                if (b == 0)
                    cout << "Cannot divide by zero.";
                else
                    cout << fixed << setprecision(2)
                         << "Result: " << divide(a, b);
                break;

            case 5:
                if (b == 0) {
                    cout << "Cannot divide by zero.";
                } else {
                    cout << "Result: " 
                         << modulusOperation((int)a, (int)b);
                }
                break;
            

            case 6:
                cout << "Result: " << power(a, b);
                break;

            default:
                cout << "Invalid choice!";
        }

        cout << endl;
    }

    return 0;
}
