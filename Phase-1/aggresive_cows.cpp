bool isPossible (vector<int> &stalls, int k, int mid) {
    int cowCount = 1;
    int lastPos = stalls[0];

    for (int i = 0; i < stalls.size(); i++) {
        if (stalls[i]-lastPos >= mid) {
            cowCount++;
            if (cowCount == k) return true;
            lastPos = stalls[i];
        }
    }
    return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
   sort (stalls.begin(), stalls.end());//The array is sorted

   int s = 0;
   int size = stalls.size();
   int e = stalls[size-1] - stalls[0];// end = maximum element - minimum element. Since array is sorted, therefore we directly do lastElement-firstElement
   int ans = -1;

   while (s <= e) {
       int mid = s + (e-s)/2;

       if (isPossible(stalls, k, mid)) {
           ans = mid;
           s = mid+1;
       }

       else e = mid-1;
       
       
    }
    return ans;
}

int main() {

}
