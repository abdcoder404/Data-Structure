#include <iostream>    
using namespace std;    
// Topic: Array Sorting    
    
int main() {    
    int arr[100], size, temp;    
    
    cout << "Enter size of array (less than 100): ";    
    cin >> size;    
    
    cout << "Enter " << size << " elements:\n";    
    for(int i = 0; i < size; i++) {    
        cin >> arr[i];    
    }    
    
    // Sorting in Ascending Order    
    for(int i = 0; i < size; i++) {    
        for(int j = i + 1; j < size; j++) {    
            if(arr[i] > arr[j]) {    
                temp = arr[i];    
                arr[i] = arr[j];    
                arr[j] = temp;    
            }    
        }    
    }    
    
    cout << "Sorted array (ascending order):\n";    
    for(int i = 0; i < size; i++) {    
        cout << arr[i] << endl;    
    }    
    
    // To sort in descending order, use:    
    // if(arr[i] < arr[j])    
    
    return 0;    
}
