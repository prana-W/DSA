#include <algorithm>
#include <iostream>
using namespace std;


//Printing an array
void print_arr (int arr_name[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr_name[i] << " ";
    }
    cout << endl;
}

//Using in-built sorting function to sort 0, 1, 2
void sort1 (int arr[], int size) {
    sort (arr, arr+size);
}

//Using frequency calculation and then updating the array
void sort2 (int arr[], int size) {
    int f0 = 0, f1 = 0, f2 = 0;


    //Calculating frequency of 0, 1 and 2
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) f0++;
        else if (arr[i] == 1) f1++;
        else if (arr[i] == 2) f2++;
        else cout << "Error!"; // when array will have an element other than 0, 1 or 2
    }

    //Updating the array
    for (int i = 0; i < size; i++) {
        //Putting 0s
        while (f0 && i < size) {
            arr[i] = 0;
            f0--;
            i++;
        }

        //Putting 1s
        while (f1 && i < size) {
            arr[i] = 1;
            f1--;
            i++;
        }

        //Putting 2s
        while (f2 && i < size) {
            arr[i] = 2;
            f2--;
            i++;
        }
    }

}

//Using Three-Pointer method
void sort3 (int arr[], int size) {
    int start =  0;
    int end = size-1;
    int mid = 0;

    while (mid <= end) {
        while (arr[mid] == 0 && mid <= end) {
            swap(arr[mid], arr[start]);
            mid++;
            /*Agar mid = 0 and

             start = 2: 2 nahi aa sakta. since 2 agar start par hota toh wo pehele hi right side mei aa jaata! (since start = mid = 0 initially)
             start = 1: agar 1 start par hua tab swap karke mid par 1 aa gya, so do mid++
             start = 0: nahi ho sakta, since uss samay mid = 0 wala case hi trigger ho jaata
             */
            start++;
        }
        while (arr[mid] == 2 && mid <= end) {
            swap (arr[mid], arr[end]);
            end--;
        }
        while (arr[mid] == 1 && mid <= end) {
            mid++;
        }
    }

}


int main () {
    int arr[] = {1,1, 0, 0, 1};
    int size = sizeof(arr)/sizeof(int);

//here goes the fucntion
    print_arr(arr,size);
}
