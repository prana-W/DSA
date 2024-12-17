#include <iostream>
using namespace std;

//Printing an array
void print_arr (int arr_name[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr_name[i]<< " ";
    }
    cout << endl;
}

//Merge sort (Merge two sorted arrays- arr1[] and arr2[] into a single sorted array- arr3[])
void merge (int arr1[], int m, int arr2[], int n, int arr3[]) {
//Using two pointer approach

    int i = 0, j = 0; //i traverses in arr1[] and j traverses in arr2[]
    int k = 0; //traverses through arr3[]

    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }

        else arr3[k++] = arr2[j++];
    }

    //Copying remaining elements of arr1[] if arr2[] is exhausted
    while (i < m) {
        arr3[k++] = arr1[i++];
    }

    //Copying remaining elements of arr2[] if arr1[] is exhausted
    while (j < n) {
        arr2[k++] = arr2[j++];
    }
}

int main() {

    int arr1[3] = {5, 8, 9};
    int arr2[4] = {-5, 0, 6, 7};
    int arr[7];

    merge(arr1, 3, arr2, 4, arr);

    print_arr(arr, 7);
}
