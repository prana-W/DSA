#include <iostream>
using namespace std;

void create_arr (int arr_name[], const int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr_name[i];
    }
}

void print_arr (int arr_name[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr_name[i]<< " ";
    }
    cout << endl;
}

void bubbleSort (int arr[], int n) {
  for (int i = 1; i < n; i++) { //for round 1 to round (n-1)
    for (int j = 0; j < n-i; j++) {
      if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
    }
  }
}

int main () {
  int size;
    cout << "Enter the size of array:";
    cin >> size;

    int num [1000];

    create_arr(num, size);
    cout << "Array before sorting:" << endl;
    print_arr(num, size);

    bubbleSort(num, size);
    cout << "Array after sorting (in ascending order):" << endl;
    print_arr(num, size);
}
