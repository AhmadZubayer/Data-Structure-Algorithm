#include <iostream>
using namespace std;

void inputArr(int arr[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter element for position [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}


void outputArr(int arr[][100], int n) {
    for (int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        } 
        cout << endl;
    }
}


int mainDiagonalSummation(int arr[][100], int n) {
    int mainDiagonalSum = 0;
    for (int i = 0; i < n; i++) {
        mainDiagonalSum += arr[i][i];
    }
    return mainDiagonalSum;
}


int antiDiagonalSummation(int arr[][100], int n) {
    int antiDiagonalSum = 0;
    for (int i = 0; i < n; i++) {
        antiDiagonalSum += arr[i][n - i - 1];
    }
    return antiDiagonalSum;
}


int nonDiagonalSummation(int arr[][100], int n) {
    int nonDiagonalSum = 0;
    for (int i = 0; i < n; i++) {
        for(int j=0; j<n; j++) {
            if(i != j && i + j != n - 1) {
                nonDiagonalSum += arr[i][j];
            }
        }
    }
    return nonDiagonalSum;
}


int cornerElementSummation(int arr[][100], int n) {
    int cornerSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           if ((i == 0 || i == n - 1) && (j == 0 || j == n - 1)) {
            cornerSum += arr[i][j];
           }
        }
    }
    return cornerSum;
}


int outerElementSummation(int arr[][100], int n) {
    int outerSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           if ((i == 0 || i == n - 1) || (j == 0 || j == n - 1)) {
            outerSum += arr[i][j];
           }
        }
    }
    return outerSum;
} 


int innerElementSummation(int arr[][100], int n) {
    int innerSum = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            innerSum += arr[i][j];  
        }
    }
    return innerSum;
} 



int main() {
    cout << "Enter the size of the matrix (rows and columns): ";
    int n;
    cin >> n;

    int arr[100][100];  
    inputArr(arr, n);

    cout << "Array:" << endl;
    outputArr(arr, n);

    cout << "Main Diagonal Summation: " << mainDiagonalSummation(arr, n) << endl;
    cout << "Anti Diagonal Summation: " << antiDiagonalSummation(arr, n) << endl;
    cout << "Non Diagonal Summation: " << nonDiagonalSummation(arr, n) << endl;
    cout << "Corner Elements Summation: " << cornerElementSummation(arr, n) << endl;
    cout << "Outer Elements Summation: " << outerElementSummation(arr, n) << endl;
    cout << "Inner Elements Summation: " << innerElementSummation(arr, n) << endl;

    return 0;
}
