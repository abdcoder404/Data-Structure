#include <iostream>
using namespace std;
// Topic:
// Array Binary Search (Iterative method)

// Binary Search is an efficient search algorithm that works only on sorted arrays.
// It repeatedly divides the search range in half until the element is found.

// Iterative Binary Search:

// Uses a while loop to repeatedly divide the search range.

// Steps of Binary Search:

// 1. Start with two pointers: low = 0, high = size - 1
// 2. Find the middle index: mid = (low + high) / 2
// 3. Compare the middle element:

// If arr[mid] == target, element is found
// If arr[mid] < target, search in the right half: low = mid + 1
// If arr[mid] > target, search in the left half: high = mid - 1

// 4. Repeat steps 2–3 until low > high or element is found

int main() {

int arr[100], size, search, temp;    
cout << "Enter size of array(less than 100): " << endl;    
cin >> size;    
    
cout << "Enter " << size << " elements: " << endl;    
for(int i = 0; i < size; i++) {    
    cin >> arr[i];    
}    
    
// Sorting array in ascending order     
    
for(int i = 0; i < size; i++) {    
    for(int j = i + 1; j < size; j++) {    
        if(arr[i] > arr[j]) {    
            temp = arr[i];    
            arr[i] = arr[j];    
            arr[j] = temp;    
        }    
    }    
}    
    
cout << "Enter value to search: " << endl;    
cin >> search;    
    
    
int low = 0;    
int high = size - 1;    
    
bool found = false;    
    
    
while(low <= high) {    
    int mid = (low + high)/ 2;    
        
    if(arr[mid] == search) {    
        cout << "Value found at index: " << mid << "." << endl;    
        found = true;    
        break;  
    }    
    else if(arr[mid] > search) {    
        high = mid - 1;    
    }    
    else {    
        low = mid + 1;    
    }    
}    
    
if(!found) {    
    cout << "Value not found!" << endl;    
}    
        
return 0;

}
