#include <iostream>
using namespace std;
// Topic: Deletion at the end in array

int main() {
    int arr[100], size;

    cout << "Enter size of array (less than 100): ";
    cin >> size;

    cout << "Enter " << size << " elements:\n";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    size--;  // Remove last element

    cout << "Updated array after deletion:\n";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
