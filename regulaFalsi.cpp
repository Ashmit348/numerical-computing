#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;  
}

int main() {
    double a, b, c;
    double fa, fb, fc;
    int maxIter;
    double tol;


    cout << "Enter the values of a and b (such that f(a)*f(b) < 0): ";
    cin >> a >> b;
    cout << "Enter the tolerance (e.g., 0.0001): ";
    cin >> tol;
    cout << "Enter maximum number of iterations: ";
    cin >> maxIter;

    fa = f(a);
    fb = f(b);

    if (fa * fb >= 0) {
        cout << "Invalid interval. f(a) and f(b) must have opposite signs." << endl;
        return 1;
    }

    cout << "\nIteration\t a\t b\t c\t f(c)\n";

    for (int i = 1; i <= maxIter; i++) {
        c = (a * fb - b * fa) / (fb - fa);
        fc = f(c);

        cout << i << "\t\t" << a << "\t" << b << "\t" << c << "\t" << fc << endl;

        if (fabs(fc) < tol) {
            cout << "\nRoot found: " << c << endl;
            return 0;
        }

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    cout << "\nMethod did not converge in " << maxIter << " iterations.\n";
    return 1;
}
