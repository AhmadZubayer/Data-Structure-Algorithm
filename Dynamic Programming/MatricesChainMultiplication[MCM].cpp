#include <iostream>
#include <climits>
using namespace std;

bool checkDimension(int rows[], int cols[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (cols[i] != rows[i + 1]) {
            return false;
        }
    }
    return true;
}

void createDimensionArr(int n, int rows[], int cols[], int d[]) {
    d[0] = rows[0];
    for (int i = 0; i < n; i++) {
        d[i + 1] = cols[i];
    }
}

void matrixChainOrder(int n, int d[], int** M, int** s) {
    for (int i = 1; i <= n; i++) {
        M[i][i] = 0;
    }
    for (int length = 2; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {
            int j = i + length - 1;
            M[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (cost < M[i][j]) {
                    M[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimizedParenthesis(int** s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimizedParenthesis(s, i, s[i][j]);
        printOptimizedParenthesis(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    int n;
    cout << "Enter Number of Matrices: ";
    cin >> n;

    int* rows = new int[n];
    int* cols = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter Dimension for Matrix " << i + 1 << " : ";
        cin >> rows[i] >> cols[i];
    }

    if (!checkDimension(rows, cols, n)) {
        cout << "Error: Incompatible dimensions.\n";
        return 1;
    }

    int* d = new int[n + 1];
    createDimensionArr(n, rows, cols, d);

    int** M = new int*[n + 1];
    int** s = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        M[i] = new int[n + 1];
        s[i] = new int[n + 1];
    }

    matrixChainOrder(n, d, M, s);

    cout << M[1][n] << endl;
    printOptimizedParenthesis(s, 1, n);
    cout << endl;

    for (int i = 0; i <= n; i++) {
        delete[] M[i];
        delete[] s[i];
    }
    delete[] M;
    delete[] s;
    delete[] rows;
    delete[] cols;
    delete[] d;

    return 0;
}
