#include <iostream>
using namespace std;

// Topic: Array Binary Search (Recursive Method)

int arr[100];

// Recursive binary search function
int binarySearch(int low, int high, int search) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == search) {
        return mid;
    } else if (arr[mid] > search) {
        return binarySearch(low, mid - 1, search);
    } else {
        return binarySearch(mid + 1, high, search);
    }
}

int main() {
    int size, search, temp;

    cout << "Enter size of array (less than 100): ";
    cin >> size;

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "Enter value to search: ";
    cin >> search;

    int result = binarySearch(0, size - 1, search);

    if (result == -1) {
        cout << "Value not found!" << endl;
    } else {
        cout << "Value found at index: " << result << "." << endl;
    }

    return 0;
}
