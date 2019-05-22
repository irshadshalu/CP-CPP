#include<vector>
using namespace std;

typedef vector<int> vi;

vi coins;

void solve() {
    int N = coins.size();
    vector<vi> dp; dp.resize(N, vi(N));
    for(int len = 1; len <= N; ++len)
    for(int left = 0; left < N - len + 1; ++left) {
        int right = left + len - 1;
        if(left == right) dp[left][right] = coins[left];
        else if (left+1 == right) dp[left][right] = max(coins[left], coins[right]);
        else dp[left][right] = max(coins[left] + min(dp[left+1][right-1], dp[left+2][right]),
                                    coins[right] + min(dp[left][right-2], dp[left+1][right-1]));
    }
    // for(int l = 0; l < N; ++l) {
    // for(int r = l; r < N; ++r) printf("%d,%d(%d) ", l, r, dp[l][r]); printf("\n"); }
    printf("Max value that can be obtained (in optimal game for both): %d\n", dp[0][N-1]);
}

int main() {
    coins = { 8, 15, 3, 7 };
    solve();

    coins = { 2, 2, 2, 2 };
    solve();

    coins = { 20, 30, 2, 2, 2, 10 };
    solve();

    return 0;
}

