#include <iostream>
using namespace std;

//To create an array
void create_arr (int arr_name[], const int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr_name[i];
    }
}

//To print an array
void print_arr (int arr_name[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr_name[i]<< " ";
    }
    cout << endl;
}

//Sorting in ascending order (using selection sort)
void selectionSortAsc (int arr_name[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
        if (arr_name[minIndex] > arr_name[j]) minIndex = j;
        }
        swap (arr_name[i], arr_name[minIndex]);
    }
}

//Sorting in descending order (using selection sort)
void selectionSortDes (int arr_name[], int n) {
    for (int i = 0; i < n-1; i++) {
        int maxIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr_name[maxIndex] < arr_name[j]) maxIndex = j;
        }
        swap (arr_name[i], arr_name[maxIndex]);
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

    selectionSortAsc(num, size);
    cout << "Array after sorting (in ascending order):" << endl;
    print_arr(num, size);

    selectionSortDes(num, size);
    cout << "Array after sorting (in descending order):" << endl;
    print_arr(num, size);

    return 0;
}

