#include <iostream>
using namespace std;

int main() {
    int a = 10; 
    int *ptr;
    ptr = &a; 

    cout << ptr << endl;
    cout << *ptr << endl;
    cout << &a << endl;
    cout << **ptr << endl; 

}
