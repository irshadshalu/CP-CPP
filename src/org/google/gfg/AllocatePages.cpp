// https://www.geeksforgeeks.org/allocate-minimum-number-pages/
#include<vector>
using namespace std;

typedef vector<int> vi;

vi arr;
int K;

// subarray division with load balancing
void solve() {
    int N = arr.size();
    int low = arr[0], high = arr[0];
    for(int i = 1; i < N; ++i) {
        low = min(low, arr[i]);
        high += arr[i];
    }
    int mid = -1, ans = INT_MAX;
    while(low <= high) {                                                                // important!
        printf("low %d, high %d, ", low, high);
        mid = (low+high)>>1;
        int parts = 1, current = 0, idx = 0;
        while(idx < N) {
            if(current + arr[idx] > mid) current = arr[idx], ++parts;
            else current += arr[idx];
            ++idx;
        }
        if(parts == K) ans = min(ans, mid);                                             // important!                                             

        if(parts <= K) high = mid - 1;
        else low = mid + 1;
        printf("mid = %d, parts = %d\n", mid, parts);
    }
    printf("Minimum Pages = %d\n", ans);
}

int main() {
    arr = {12, 34, 67, 90}; K = 2;
    solve();

    return 0;
}