#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
    return x*x*x - x - 1;  
}

double df(double x) {
    return 3*x*x - 1;  
}

int main() {
    double x0, x1, tol;
    int maxIter;

    cout << "Enter initial guess: ";
    cin >> x0;
    cout << "Enter error tolerance (e.g., 0.0001): ";
    cin >> tol;
    cout << "Enter maximum number of iterations: ";
    cin >> maxIter;

    cout << "\nIteration\t x\t\t f(x)\n";

    for (int i = 1; i <= maxIter; i++) {
        double fx = f(x0);
        double dfx = df(x0);

        if (dfx == 0) {
            cout << "Derivative is zero. Method fails." << endl;
            return 1;
        }

        x1 = x0 - fx / dfx;

        cout << i << "\t\t" << x1 << "\t" << f(x1) << endl;

        if (fabs(x1 - x0) < tol) {
            cout << "\nRoot found: " << x1 << endl;
            return 0;
        }

        x0 = x1;
    }

    cout << "\nMethod did not converge in " << maxIter << " iterations.\n";
    return 1;
}
