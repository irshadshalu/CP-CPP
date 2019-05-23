// https://www.geeksforgeeks.org/count-strings-can-formed-using-b-c-given-constraints/

#include<vector>
using namespace std;

vector<int> dp[2][3];

int recur(int n, int b, int c) {
    if(n < 0 || b < 0 || c < 0)  return 0;
    
    if(dp[b][c][n] != -1) return dp[b][c][n];

    if(n == 0) return dp[b][c][n] = 1;

    int tot = 0;
    tot += recur(n-1, b, c);
    tot += recur(n-1, b-1, c);
    tot += recur(n-1, b, c-1);
    return dp[b][c][n] = tot;
}

// O(N): top down dp
int solve(int n) {
    // O(N) states
    for(int b = 0; b <= 1; ++b)
    for(int c = 0; c <= 2; ++c)
        dp[b][c].assign(n+1, -1);
    
    recur(n, 1, 2);
    
    return dp[1][2][n];
}

// bottom up dp
int solve0(int n) {
    vector<int> bu[2][3];
    // O(N) states
    for(int b = 0; b <= 1; ++b)
    for(int c = 0; c <= 2; ++c) {
        dp[b][c].assign(n+1, 0);
        dp[b][c][0] = 1;

        for(int i = 1; i <= n; ++i) {
            dp[b][c][i] += dp[b][c][i-1];
            if(b > 0) dp[b][c][i] += dp[b-1][c][i-1];
            if(c > 0) dp[b][c][i] += dp[b][c-1][i-1];
        }
    }
    return dp[0][2][n];
}

// O(N): factorial method
int solve1(int n) {
    vector<long long> fact(n+1);
    fact[0] = fact[1] = 1LL;
    for(int f = 2; f <= n; ++f) fact[f] = f*fact[f-1];

    long long ans = 0;
    for(int b = 0; b <= 1; ++b)
    for(int c = 0; c <= 2; ++c) {
        if(b+c > n) continue;
        int a = n - (b+c);
        ans += fact[n] / (fact[a] * fact[b] * fact[c]);
    }        
    return ans;
}

// O(1): permutation
/*
 * all a + 1b + 1c + 2c + 1b1c + 1b2c ,or (n!)/((n-3)!2!
 * => 1 + n + n + n(n-1)/2 + n(n-1) + n(n-1)(n-2)/2
 * => 1 + 2n + n(n-1)(1/2 + 1 + (n-2)/2)
 * => 1 + 2n + n(n-1)(n+1)/2
 */
int solve2(int n) {
    return 1 + 2*n + n*(n*n-1)/2;
}

// using a's, atmost 1 b and atmost 2 c
int main() {
    for(int n = 0; n <= 5; ++n)
        printf("%d = %d,%d,%d\n", n, solve(n), solve1(n), solve2(n));
    return 0;
}