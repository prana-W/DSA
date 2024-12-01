#include <iostream>
using namespace std;

//NOTE: Kindly pass a sorted array as an argument (since we are dealing with binary search)

//To create an array
void create_arr (int arr_name[], const int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr_name[i];
    }
}

//Printing an array
void print_arr (int arr_name[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr_name[i] << " ";
    }
    cout << endl;
}

//returns the index of the element that matches the key
int binarySearch (int arr[], int size, int key) {
  int start = 0;
  int end = size - 1;

  while (start <= end) {
    int mid = start + (end-start)/2; //Note: This is done to avoid error during (s+e),incase of it getting outside the range of INT.

    if (arr[mid] == key) return mid;
    else if (arr[mid] < key) start = mid+1; // going to right part;
    else end = mid-1; //going to left part
  }
  return -1; //if no such index found
}

int main () {
  
  int size, target;
  cout << "Enter the size of the elements:";
  cin >> size;

  int arr [1000];

  cout << "Enter the elements of the  array: << endl;
  create_arr(arr, size);
  print_arr(arr, size);

  cout << "Enter the target element";
  cin >> target;

  cout "Index of the element is: " << binarySearch(arr, size, target) << endl;

  return 0;
}
