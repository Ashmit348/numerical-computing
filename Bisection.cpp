#include <iostream>
#include <cmath>
using namespace std;

// Define the function for which we are finding the root
double f(double x) {
    // Example: f(x) = x^3 - x - 2
    return x*x*x - x - 2;
}

// Bisection Method
void bisection(double a, double b, double tolerance) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval: f(a) and f(b) must have opposite signs." << endl;
        return;
    }

    double c;
    int iteration = 1;

    cout << "Iter\t a\t\t b\t\t c\t\t f(c)\n";
    do {
        c = (a + b) / 2;
        cout << iteration << "\t" << a << "\t" << b << "\t" << c << "\t" << f(c) << endl;

        if (f(c) == 0.0 || (b - a) / 2 < tolerance) {
            cout << "\nRoot found: " << c << endl;
            return;
        }

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        iteration++;
    } while ((b - a) >= tolerance);

    cout << "\nApproximate root: " << c << endl;
}

int main() {
    double a = 1, b = 2;        // Initial guesses (must bracket the root)
    double tolerance = 0.0001;  // Error tolerance

    bisection(a, b, tolerance);

    return 0;
}
