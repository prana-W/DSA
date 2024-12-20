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

//Insertion sort
void insertionSort (int arr_name[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr_name[i];
        int j = i-1;

        while (j>=0) {
            if (arr_name[j] > temp) {

                //Shifting the arr[j] to the right, so as to place the space int the left for the arr[i] to be inserted
                arr_name[j+1] = arr_name[j];
            }
            else break;

            j--;
        }
        arr_name[j+1] = temp;
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

    insertionSort (num, size);
    cout << "Array after sorting (in ascending order):" << endl;
    print_arr(num, size);

    return 0;
}

