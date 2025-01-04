#include <iostream>
using namespace std;



// Printing an array
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Bubble sort (using recursion)
void bubbleSort(int *arr, int n)
{

  //base case
    if (n == 0 || n == 1) {
        return;
    }

    int i = 0;
    int j = i + 1;

    // placing the first largest element in the right postiton
    while (j < n)
    {
        if (arr[i] > arr[j])
        {
            swap(arr[i], arr[j]);
        }
         i++;
         j++;
    }

    // recursive call
    bubbleSort(arr, n - 1); // since largest element already at the end, we want to pass the rest of the arr
}


// Selection sort (using recursion)
void selectionSort(int *arr, int n, int i = 0)
{
    if (i >= n)
        return; // base case

    // Place the first smallest element at the correct position
    int minIndex = i;
    for (int j = i; j < n; j++)
    {
        if (arr[j] < arr[minIndex])
        {
            minIndex = j;
        }
    }

    swap(arr[i], arr[minIndex]);

    selectionSort(arr, n - 1, i + 1); // Now the smallest element is the the ith place. Now do selectionSort in the remaining array (so size decreses by one and the i increses)
}

//Insertion Sort (using recursion)
void insertionSort(int *arr, int n)
{
    if (n == 0 || n == 1)
        return;

    insertionSort(arr, n - 1); // sort the n-1 element

    // Putting the last element at the correct location
    int j = n - 1;
    int temp = arr[j];

    while (j - 1 >= 0 && temp < arr[j - 1])
    {
        arr[j] = arr[j - 1];
        j--;
    }

    arr[j] = temp;
}

int main () {

  //code goes here
}
