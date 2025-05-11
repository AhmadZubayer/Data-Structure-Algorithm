#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 3; // Define size of the 2D array (you can change this size)
    int arr[3][3]; // 2D array with 3 rows and 3 columns

    cout << "Enter the values for the array: " << endl;
    // Input values for the 2D array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    // Calculate and print row sums
    cout << "\nRow sums: " << endl;
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += arr[i][j]; // Sum up the elements in the row
        }
        cout << "Sum of row " << i + 1 << ": " << rowSum << endl;
    }

    // Calculate and print column sums
    cout << "\nColumn sums: " << endl;
    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += arr[i][j]; // Sum up the elements in the column
        }
        cout << "Sum of column " << j + 1 << ": " << colSum << endl;
    }

    return 0;
}
