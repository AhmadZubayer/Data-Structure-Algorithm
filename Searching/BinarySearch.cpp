#include <iostream>
using namespace std;

void inputArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void outputArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void binarySearch(int arr[], int n, int search) {
    int left = 0;
    int right = n - 1;
    int count = 0;
    bool isFound = false;
    int mid; 

    while (left <= right) {
        count++;
        mid = (left + right) / 2; 

        if (arr[mid] == search) {
            isFound = true;
            break;
        } else if (arr[mid] > search) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (isFound) {
        cout << search << " found at index " << mid << " in the sorted array." << endl;
        cout << "Number of Comparisons: " << count-1 << endl;
    } else {
        cout << search << " not found in the array." << endl;
        cout << "Number of Comparisons: " << count-1 << endl;
    }
}


int main() {
    cout << "Enter the size of the array: ";
    int n, arr[100];
    cin >> n; 

    cout << "Enter Array Elements: " << endl;
    inputArr(arr, n);

    cout << "Enter the number you want to search: ";
    int search;
    cin >> search;

    bubbleSort(arr, n);
    cout << "Sorted Array: ";
    outputArr(arr, n);

    binarySearch(arr, n, search);

    return 0;
}
