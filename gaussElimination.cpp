#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    double a[10][11], x[10];  
    cout << "Enter the augmented matrix (coefficients and constants):\n";
    for (int i = 0; i < n; i++) {
        cout << "Equation " << i + 1 << ":\n";
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            double ratio = a[k][i] / a[i][i];
            for (int j = 0; j <= n; j++) {
                a[k][j] = a[k][j] - ratio * a[i][j];
            }
        }
    }

    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    cout << fixed << setprecision(4);
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
