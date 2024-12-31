#include <iostream>
using namespace std;
//Done by Binary Search (using Recursion)

//Q.1) find the first, last and total occurence of a key
    int firstOccurrence (int* arr, int size, int key, int s, int e, int ans = -1) {//default argument of ans set to -1;
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
int lastOccurrence (int*  arr, int size, int key, int s, int e, int ans = -1) {
    if (s > e) return ans; //base case

int mid = s + (e-s)/2;

    if (arr[mid] == key) {
        ans = mid;
        return lastOccurrence (arr, size, key, mid+1, e, ans);
    }

    else if (arr[mid] < key) {
        return lastOccurrence(arr, size, key, mid+1, e, ans);
    }

    else {
        return lastOccurrence(arr, size, key, s, mid-1, ans);
    }

}
int totalOccurence (int* arr, int size, int key, int s, int e, int ans = -1) {
    if (firstOccurrence(arr, size, key, s, e, ans) == -1) return 0;
    int total = lastOccurrence(arr, size, key, s, e, ans) - firstOccurrence(arr, size, key, s, e, ans) + 1;

    return total;
}


//Q.2) Peak in a Mountain array (here array will not be sorted!)
int peakMountain (int* arr, int size, int s, int e) {

    int mid = s + (e-s)/2;
    if (s > e) {
        return mid; // base case
    }

    if (arr[mid] < arr[mid+1]) {
        return peakMountain(arr, size, mid+1, e);
    }
    else if (arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]) {
        return mid;
    }

    else {
        return peakMountain(arr, size, s, mid-1);
    }
}


//Q.3) Square root by recursion
int sqr (int n, int s, int e, int ans = -1) {

    //base case
    int mid = s + (e-s)/2;
    if (s > e) {
        return ans;
    }

    //recursive call
    if (mid*mid <= n) {
        ans = mid;
        return sqr(n, mid+1, e, ans);
    }

    if (mid*mid > n) {
        return sqr (n, s, mid-1, ans);
    } 
}


//Q.4) Book Allocation Problem
bool isPossible (int* arr, int size, int student, int mid) {
    int stuCount = 1;
    int sum = 0;
    int i = 0;

    while (i < size) {
        if (arr[i]+sum <= mid) {
            sum += arr[i];
            i++;
        }
        else {
            stuCount++;
            sum = arr[i];
            i++;
            if (stuCount > student || sum > mid) return false;
        }
    }
    return true;
}
//Book Allocation Problem
int minPage (int* arr, int size, int s, int e, int student, int ans = -1) {

    int mid = s + (e-s)/2;

    if (s > e) {
        return ans;
    }

    if (isPossible(arr, size, student, mid)) {
        ans = mid;
        return minPage (arr, size, s, mid-1, student, ans);
    }

    else {
        return minPage(arr, size, mid+1, e, student, ans);
    }
}

int main() {

}
