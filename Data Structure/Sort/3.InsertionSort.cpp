#include <iostream>
using namespace std;

void insertionSort(int arr[], int length) {
   for(int i=1; i<length; i++) {
    int temp = arr[i];
    int j = i-1;

    while(j>=0 && arr[j] > temp) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = temp;
   }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int length = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for(int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr, length);

    cout << "Sorted array: ";
    for(int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
