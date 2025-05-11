#include <iostream>
using namespace std;

void selectionSort(int arr[], int length) {
    for(int i=0; i<length-1; i++) {
        int min=i;
        for(int j=i+1; j<length; j++) {
            if(arr[min] > arr[j]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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

    selectionSort(arr, length);

    cout << "Sorted array: ";
    for(int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
