#include <iostream>
using namespace std;

//This method has a TIME COMPLEXITY of O (log n) as compared to linear Search which has O (n).

//Printing an array
void print_arr (int arr_name[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr_name[i] << " ";
    }
    cout << endl;
}

int pivotElement (int arr[], int size) {
    int start = 0;
    int end = size-1;

    while (start <= end) {
        int mid = start + (end-start)/2;

        if (arr[mid] >= arr[0]) {
            start = mid+1;
        }

        else if (arr[mid] < arr[0] && arr[mid] > arr[mid-1]) {
            end = mid-1;
        }

        else return mid;
    }
   return -1;
}

int binarySearch (int arr[], int size, int start, int end, int key) {
    while (start <= end) {
        int mid = start + (end-start)/2;

        if (arr[mid] < key) start = mid+1;
        else if (arr[mid] > key) end = mid-1;
        else return mid;
    }
    return -1;
}

int search_sorted_rotated_array (int arr[], int size, int key) {
    if (arr[0] <= arr[size-1]) return binarySearch(arr,size, 0, size-1, key); //it means array is already fully sorted
    if (arr[0] <= key) {
        int start = 0;
        int end = pivotElement(arr,size)-1;
        return binarySearch(arr,size,start, end,key);
    }
    if (arr[0] > key) {
        int start = pivotElement(arr,size);
        int end = size-1;
        return binarySearch(arr, size, start, end, key);
    }
    return -1;
}

int main () {
    int arr[] = {}; //Enter a sorted rotated array (sorted array which is rotated)
    int size = sizeof(arr)/sizeof(int);

    int key = 0;// Enter the key here

    //to check if key is in the array or not
    bool check = false;
    if (search_sorted_rotated_array(arr, size, key) == -1) check = false;
    else check = true;

    if (check) cout << "Yes, key is present!" << endl;
}
