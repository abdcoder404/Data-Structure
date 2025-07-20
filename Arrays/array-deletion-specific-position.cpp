#include <iostream>
using namespace std;
// Topic: Deletion from a specific position in array

int main() {
    int arr[100], size, pos;

    cout << "Enter size of array (less than 100): ";
    cin >> size;

    cout << "Enter " << size << " elements:\n";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    do {
        cout << "Enter position to delete value from: ";
        cin >> pos;
        if(pos < 0 || pos >= size) {
            cout << "Invalid position! Try again.\n";
        }
    } while(pos < 0 || pos >= size);

    for(int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;

    cout << "Updated array after deletion:\n";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
