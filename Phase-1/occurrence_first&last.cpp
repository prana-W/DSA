#include <iostream>
using namespace std;

//NOTE: Since, we are using binary search, make sure that the array that is passed is first sorted and then passed as an argument

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

//To find the index of first occurrence of an element in a sorted array
int firstOcc (int arr[], int size, int key) {
    int s = 0, e = size-1;
    int ans = -1;

    while (s<=e) {
        int mid = s + (e-s)/2; //To avoid out of bound if e+s becomes out of bound

        if (arr[mid] == key) {
            ans = mid; //storing the answer
            e = mid-1; //checking if the key also occurs somewhere on the left side
        }
        else if (key > arr[mid]) s = mid+1;
        else e = mid-1;
    }
return ans;
}

//To find the index of last occurrence of an element in a sorted array
int lastOcc (int arr[], int size, int key) {
    int s = 0, e = size-1;
    int ans = -1;

    while (s<=e) {
        int mid = s + (e-s)/2; //To avoid out of bound if e+s becomes out of bound

        if (arr[mid] == key) {
            ans = mid; //storing the answer
            s = mid+1; //checking if the key also occurs somewhere on the right side
        }
        else if (key > arr[mid]) s = mid+1;
        else e = mid-1;
    }
    return ans;
}

//To get the total number of occurrence of an element in a sorted array
int totalOcc (int arr[], int size, int key) {
    int lastIndex = lastOcc(arr, size, key);
    int firstIndex = firstOcc(arr, size, key);

    int totalOccurrence = (lastIndex-firstIndex) + 1;

    return totalOccurrence;
}

int main () {

    int size, target;
    cout << "Enter the size of array:";
    cin >> size;

    int num [1000];
    create_arr(num, size);

    cout << "Enter the target element: ";
    cin >> target;

    cout << "Index of first occurrence: " << firstOcc(num, size, target) << endl;
    cout << "Index of last occurrence: " << lastOcc(num, size, target) << endl;
    cout << "Total number of occurrences: " << totalOcc(num, size, target) << endl;

    return 0;
}
