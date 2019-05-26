#include<vector>
using namespace std;

typedef vector<int> vi;

int W;
vi val, wt;

// first item array to use each item only once
void solve() {
    int N = wt.size();
    vector<vi> dp;
    dp.assign(N+1, vi(W+1));
    for(int i = 0; i <= N; ++i) 
    for(int j = 0; j <= W; ++j) {
        if(i == 0) dp[i][j] = 0;
        else if(wt[i-1] > j) dp[i][j] = dp[i-1][j];
        else dp[i][j] = max(dp[i-1][j], dp[i-1][j - wt[i-1]] + val[i-1]);
    }
    printf("Maximum profit = %d\n", dp[N][W]);
}

int main() {
    val = {5, 10, 100, 120, 200}; 
    wt = {5, 10, 20, 30, 40}; 
    W = 50;

    solve(); 

    return 0;
}