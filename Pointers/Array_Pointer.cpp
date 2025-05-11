#include <iostream>
using namespace std;

int main() {
    int arr[] = {3, 9, 15, 21, 27}; // Array initialization
    int *ptr = &arr[3];            // Pointer pointing to arr[3] (21)

    cout << *ptr << endl;          // Line 3: Prints the value pointed by ptr (arr[3])
    cout << *(ptr - 2) << endl;    // Line 4: Prints the value at arr[1]
    cout << *(++ptr) << endl;      // Line 5: Moves ptr to arr[4] and prints its value
    cout << *(ptr--) << endl;      // Line 6: Prints value at arr[4], then moves ptr to arr[3]
    cout << --(*ptr) << endl;      // Line 7: Decrements value at arr[3] and prints it

    cout << "Option (A): " << arr[2] << endl; // Access using subscript notation

    // Option (B): Correct
    cout << "Option (B): " << *(arr + 2) << endl; // Access using pointer arithmetic

    // Option (D): Correct
    cout << "Option (D): " << *(&arr[2]) << endl; // Access using the address-of operator


    return 0;
}
