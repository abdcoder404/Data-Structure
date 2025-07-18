#include <iostream>
using namespace std;
// Topic
// Insertion at the end in array 

int main() {
    int size;

    cout << "Enter size of the array: ";
    cin >> size;

    int arr[100];

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int value;
    cout << "Enter value to insert at the end: ";
    cin >> value;

    arr[size] = value;
    size++;

    cout << "Updated array:\n";
    for (int i = 0; i < size; i++) {
        cout << "Index: " << i << "   Value: " << arr[i] << endl;
    }

    return 0;
}
