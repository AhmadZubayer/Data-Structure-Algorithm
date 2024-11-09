/* Find the count of more-than-one elements in a 2D array
 * Find the duplicate elements
 * Find the number of unique elements
 * Find the unique elements */

#include <iostream>
using namespace std;

int main() {
    cout << "Enter the number of rows:" << endl;
    int row;
    cin >> row;
    
    cout << "Enter the number of columns:" << endl;
    int col;
    cin >> col;
    
    int arr[row][col];
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << "Enter element for position [" << i <<"][" << j << "]: ";
            cin >> arr[i][j]; 
        }
    }
    
    bool isUnique = false;
    int uniqueCount = 0;
    int multiCount = 0;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(arr[i][j] == arr[i+1][j+1]){
                isUnique = false;
                multiCount++;
            } else {
                isUnique = true;
                uniqueCount++;
            }            
        }
    }

} 