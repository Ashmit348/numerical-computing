#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter number of variables: ";
    cin >> n;

    double a[10][10], b[10], x[10], old_x[10], eps;
    int maxIter;

    cout << "Enter coefficients of the augmented matrix (A|b):\n";
    for (int i = 0; i < n; i++) {
        cout << "Equation " << i + 1 << ":\n";
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
        cin >> b[i];
    }

    cout << "Enter initial guesses:\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter error tolerance (e.g., 0.001): ";
    cin >> eps;

    cout << "Enter maximum number of iterations: ";
    cin >> maxIter;

    cout << "\nIteration\tValues\n";
    for (int iter = 1; iter <= maxIter; iter++) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            old_x[i] = x[i];
            double sum = b[i];
            for (int j = 0; j < n; j++) {
                if (j != i)
                    sum -= a[i][j] * x[j];
            }
            x[i] = sum / a[i][i];

            if (fabs(x[i] - old_x[i]) > eps)
                done = false;
        }

        cout << iter << "\t\t";
        for (int i = 0; i < n; i++) {
            cout << x[i] << "\t";
        }
        cout << endl;

        if (done)
            break;
    }

    cout << "\nApproximate Solution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
