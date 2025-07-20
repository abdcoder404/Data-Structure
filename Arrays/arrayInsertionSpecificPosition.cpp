#include <iostream>
using namespace std;
// Topic:
// Insertion at specific position in array

int main() {
int size;

cout << "Enter size of the array: ";  
cin >> size;  

int arr[100];  

cout << "Enter " << size << " elements:\n";  
for (int i = 0; i < size; i++) {  
    cin >> arr[i];  
}  

int pos, value;  

do {  
    cout << "Enter position to insert: ";  
    cin >> pos;  
    if (pos < 0 || pos > size) {  
        cout << "Invalid position, please try again.\n";  
    }  
} while (pos < 0 || pos > size);  

cout << "Enter value to insert: ";  
cin >> value;  

for (int i = size; i > pos; i--) {  
    arr[i] = arr[i - 1];  
}  

arr[pos] = value;  
size++;  

cout << "Updated array:\n";  
for (int i = 0; i < size; i++) {  
    cout << "Index: " << i << "   Value: " << arr[i] << endl;  
}  

return 0;

}

