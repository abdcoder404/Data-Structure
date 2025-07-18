#include <iostream>
using namespace std;
// Topic:
// Insertion at the beginning in array

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
cout << "Enter value to insert at beginning: ";  
cin >> value;  

for (int i = size; i > 0; i--) {  
    arr[i] = arr[i - 1];  
}  

arr[0] = value;  
size++;  

cout << "Updated array:\n";  
for (int i = 0; i < size; i++) {  
    cout << "Index: " << i << "   Value: " << arr[i] << endl;  
}  

return 0;

}

