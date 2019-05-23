// https://www.geeksforgeeks.org/maximum-absolute-difference-between-sum-of-two-contiguous-sub-arrays/
#include<vector>
#include<cstdlib>
using namespace std;

#define INF 1e9

typedef vector<int> vi;

vector<int> arr;
int N;

vi lmax, lmin, rmax, rmin;

void kadaneleft(vi &left) {
    int curr, mx;
    curr = mx = -INF;
    for(int i = 0; i < N; ++i) {
        curr = max(arr[i], curr + arr[i]);
        mx = max(mx, curr);
        left[i] = mx;
    }
}

void kadaneright(vi &right) {
    int curr, mx;
    curr = mx = -INF;
    for(int i = N-1; i >= 0; --i) {
        curr = max(arr[i], curr + arr[i]);
        mx = max(mx, curr);
        right[i] = mx;
    }
}

// 2 non overlapping subarrays with maximum sum difference!
void solve() {
    N = arr.size();
    lmax.resize(N); lmin.resize(N); rmax.resize(N); rmin.resize(N);

    printf("arr = "); for(int x: arr) printf("%d ", x); printf("\n");

    kadaneleft(lmax);
    printf("lmax subarr sum = "); for(int x: lmax) printf("%d ", x); printf("\n");

    kadaneright(rmax);
    printf("rmax subarr sum = "); for(int x: rmax) printf("%d ", x); printf("\n");

    for(int i = 0; i < N; ++i) arr[i]=-arr[i];

    kadaneleft(lmin);
    for(int i = 0; i < N; ++i) lmin[i]=-lmin[i];
    printf("lmin subarr sum = "); for(int x: lmin) printf("%d ", x); printf("\n");

    kadaneright(rmin);
    for(int i = 0; i < N; ++i) rmin[i]=-rmin[i];
    printf("rmin subarr sum = "); for(int x: rmin) printf("%d ", x); printf("\n");

    int ans = -INF;
    for(int i = 0; i < N-1; ++i)
        ans = max(ans, max(abs(lmax[i]-rmin[i+1]), abs(lmin[i] - rmax[i+1])));
    printf("ans = %d\n", ans);
}

int main() {
    arr = {2, -1, -2, 1, -4, 2, 8};
    solve();
    return 0;
}