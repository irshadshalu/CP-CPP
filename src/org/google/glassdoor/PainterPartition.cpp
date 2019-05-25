#include<vector>
using namespace std;

typedef vector<int> vi;

#define INF 1e7

int K;
vi arr;

// O(K*N^2)
void solve1() {
    int N = arr.size();
    vi cumulative(N); cumulative[0] = arr[0];
    for(int i = 1; i < N; ++i) cumulative[i] = cumulative[i-1] + arr[i];

    vector<vi> dp;
    dp.resize(K+1, vi(N));

    for(int i = 1; i <= K; ++i)
    for(int j = 0; j < N; ++j) {
        if(i == 1) { dp[1][j] = cumulative[j]; continue; }
        if(j == 0) { dp[i][0] = arr[0]; continue; }

        dp[i][j] = dp[i-1][j];
        for(int l = 0; l < j; ++l) {                                            // upto l there are i-1 partitions                    
            dp[i][j] = min(dp[i][j], max(dp[i-1][l], (cumulative[j]-cumulative[l])));
        }
    }

    // for(int i = 1; i <= K; ++i) { for(int j = 0; j < N; ++j) printf("dp[%d][%d]=%d\t", i, j, dp[i][j]); printf("\n"); }
    printf("min cost = %d\n", dp[K][N-1]);
}

// O(N*log(sum(arr)))
void solve2() {
    int N = arr.size();
    int low = arr[0], high = arr[0];
    for(int i = 1; i < N; ++i) low = min(low, arr[i]), high += arr[i];

    int mid, ans = INF;
    while(low < high) {
        mid = (low+high)>>1;
        int parts = 1, current = 0, index = 0;
        while(index < N) {
            if(current + arr[index] > mid) current = arr[index], ++parts;
            else current += arr[index];
            ++index;
        }
        if(parts == K) ans = min(ans, mid);
        if(parts <= K) high = mid - 1;
        else low = mid + 1;
    }
    printf("min cost = %d\n", ans);
}

int main() {
    arr = {10, 20, 60, 50, 30, 40 }; 
    K = 3;
    solve1();
    solve2();

    return 0;
}