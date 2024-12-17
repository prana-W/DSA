//https://www.naukri.com/code360/problems/cooking-ninjas_1164174?source=youtube&campaign=love_babbar_codestudio2&leftPanelTabValue=SUBMISSION
//Concept similar to Book Allocation Problem, done using Binary Search method

#include <bits/stdc++.h> 

bool isPossible (vector<int> &rank, int m, int mid) {
//mid represents the minimum total time (or the max. of the total time taken by each cook, we want mid to be minimum)
    int dishCount = 0;

    for (int i = 0; i < rank.size(); i++) {

        int time = 0;
        int j = 1;

        while (time + j*rank[i] <= mid) {
            time += j*rank[i];
            dishCount++;
            j++;

            if (dishCount >= m) return true;
        }
    }

    return false;
}


int minCookTime(vector<int> &rank, int m)
{
    int s = 0;
    int e = 5*m*(m+1);
  // The maximum time taken will be if the highest ranked cook (whose R is max) does all the cooking. So time taken will be= 
  // R + 2*R + 3*R .... M*R (where R is the max. rank which is 10 in the Coding ninjas platform according to constraints.
  // Now M is the total dishes. Putting all values and simplifying we get int e = 5*m*(m-1)
    int ans = -1;

    while (s <= e) {
        int mid = s + (e-s)/2;
        
        if (isPossible(rank, m, mid)) {
            ans = mid;
            e = mid-1;
        }

        else s = mid+1;
    }

    return ans;
}
