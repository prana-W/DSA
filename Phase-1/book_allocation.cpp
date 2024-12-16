#include <iostream>
#include <vector>
using namespace std;

//n: number of books
//m: number of students
//arr[i]: pages in a particular book

bool isPossible (vector<int>arr, int n, int m, int mid) {

    int pageSum = 0;
    int student = 1;

    for (int i = 0; i < n; i++) {
        if (pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else {
            student++;//now distribute books to student 2
            pageSum = arr[i];// resetting the total pages for student 2
            if (pageSum > mid || student > m) {
                return false;
            }
        }
    }
    return true;
}


int allocateBooks (vector<int>arr, int n, int m) {
    int s = 0;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int e = sum;
    int ans = -1;
    
    while (s <= e) {
        int mid = s +(e-s)/2;

        if (isPossible (arr, n, m, mid)) {
            ans = mid;
            e = mid-1;
        }

        else s = mid+1;
    }
    return ans;
}

int main() {

}

