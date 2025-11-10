#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;      

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1; 
}

void quickSort(vector<int>& arr, int low, int high, int depth = 0) {
    // Base condition
    if (low < high) {
        int pi = partition(arr, low, high);

        cout << string(depth * 2, ' ') 
             << "Pivot " << arr[pi] 
             << " placed at index " << pi << endl;
        quickSort(arr, low, pi - 1, depth + 1);   // left side
        quickSort(arr, pi + 1, high, depth + 1);  // right side
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n\nSorting steps:\n";

    quickSort(arr, 0, arr.size() - 1);

    cout << "\nSorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
