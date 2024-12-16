#include <iostream>
using namespace std;
int sqrtf (int n) {
    int s = 0;
    int e = n;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e-s)/2;

        if (mid*mid < n) {
            ans = mid;
            s = mid+1;
        }
        else if (mid*mid > n) e = mid-1;
        else return mid;

    }
    return ans;
}

double sqrtfPrecision (int n, int prec) {
    double factor = 1;
    double ans = sqrtf(n);
    for (int i = 0; i <= prec; i++) {
        while (ans*ans <= n) {
            ans+=factor;
        }
        ans -= factor;
        factor /= 10;
    }
return ans;
}
int main() {

    int x = 26;
    int p = 5;

    cout << sqrtf(x) << " " << sqrtfPrecision (x, p) << endl;

}
