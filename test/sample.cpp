#include <iostream>
using namespace std;

int main() {
    int* arr = new int[10];
    arr[2] = 42;
    cout << arr[2] << endl;
    return 0;  // missing delete[] arr
}
