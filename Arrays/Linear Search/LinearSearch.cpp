#include <iostream>
using namespace std;
// Topic: Array Linear Searching

int main() {
int arr[100], size, search;

cout << "Enter size of array (less than 100): ";
cin >> size;

cout << "Enter " << size << " elements:\n";
for(int i = 0; i < size; i++) {
cin >> arr[i];
}

cout << "Enter value to search in array: ";
cin >> search;

bool found = false;

for(int i = 0; i < size; i++) {
if(arr[i] == search) {
cout << "Element found at index: " << i << "." << endl;
found = true;
}
}

if(!found) {
cout << "Element not found in array." << endl;
}

return 0;

}

