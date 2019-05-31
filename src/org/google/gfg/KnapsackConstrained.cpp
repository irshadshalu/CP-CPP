#include<vector>
#include<iostream>
using namespace std;

typedef vector<int> vi;

int W, N;
vi val, wt, ct;

vector<vi> memo;

int recur(int idx, int remW) {
    if(idx == N) return 0;
    if(memo[idx][remW] != -1) return memo[idx][remW];
    
    int profit = 0;
    for(int i = 0; i <= ct[idx]; ++i) 
        if(remW >= wt[idx] * i) 
            profit = max(profit, val[idx]*i + recur(idx+1, remW-(wt[idx]*i)));
    return memo[idx][remW] = profit;
}

int topDown() {
    memo.assign(N+1, vi(W+1, -1));
    return recur(0, W);
}

int bottomUp() {
    vector<vi> dp;
    dp.assign(N+1, vi(W+1, 0));
    
    for(int i = 1; i <= N; ++i)
    for(int k = 0; k <= ct[i-1]; ++k)
    for(int j = 0; j <= W; ++j) {
        int w = k * wt[i-1];
        if(j >= w) 
            dp[i][j] = max(dp[i][j], dp[i-1][j-w] + k * val[i-1]);
    }
    return dp[N][W];
}

int main() {
    val = {10, 45, 110, 120, 160}; 
    wt = {5, 10, 20, 30, 40}; 
    ct = {4, 2, 1, 2, 1};
    W = 60; 
    N = val.size();

    // optimal = 110(x1: 20) + 120(x1: 30) + 45(x1: 10) = 275
    cout << topDown() << endl; 
    cout << bottomUp() << endl;
    
    return 0;
}