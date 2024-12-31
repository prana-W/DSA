#include <iostream>
using namespace std;
//Done by Binary Search (using Recursion)

//doing by recursion
    int firstOccurrence (int* arr, int size, int key, int s, int e, int ans = -1) {
        if (s > e) return ans; //base case

        int mid = s + (e-s)/2;

        //Recursive calls
        if (arr[mid] == key) {
            ans = mid;
            return firstOccurrence(arr, size, key, s, mid-1, ans); // e = mid-1
        }

        else if (arr[mid] < key) {
            return firstOccurrence (arr, size, key, mid+1, e, ans); // s = mid+1
        }

        else {
            return firstOccurrence (arr, size, key, s, mid-1, ans); // e= mid-1
        }
    }


int main() {
int arr[] = {2,3, 6, 6, 6, 8, 8, 9, 9, 10};
int n = sizeof(arr)/sizeof(int);

int key;
cin >> key;

cout << "By recursion: " << firstOccurrence (arr, n, key, 0, n-1) << endl; //gives the index of first occurence of a key


}
