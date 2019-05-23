// https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/
#include<vector>
using namespace std;

#define INF 1e9

typedef pair<int, int> ii;
typedef vector<int> vi;

vi arr;

// maximum j-i such that arr[j] is greater than arr[i]
void solve() {
    int N = arr.size();
    vi lmin(N, INF), rmax(N, -INF);

    lmin[0] = arr[0];
    for(int i = 1; i < N; ++i) lmin[i] = min(lmin[i-1], arr[i]);

    rmax[N-1] = arr[N-1];
    for(int j = N-2; j >= 0; --j) rmax[j] = max(rmax[j+1], arr[j]);

    int left = 0, right = 0; int ans = -1; ii idx = ii(-1, -1);
    while(left < N && right < N) {
        if(lmin[left] < rmax[right]) {
            if(ans < right-left) ans = right-left, idx = ii(left, right);
             ++right; 
        }
        else ++left;
    }
    printf("max gap = %d with index (%d,%d)\n", ans, idx.first, idx.second);
}

int main() {
    arr = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    solve();

    return 0;
}