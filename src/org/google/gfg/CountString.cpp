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
int solve0(int n) {
    // O(N) states
    for(int b = 0; b <= 1; ++b)
    for(int c = 0; c <= 2; ++c)
        dp[b][c].assign(n+1, -1);
    
    recur(n, 1, 2);
    
    return dp[1][2][n];
}

// O(N): factorial method
int solve(int n) {
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
int solve1(int n) {
    return 1 + 2*n + n*(n*n-1)/2;
}

// using a's, atmost 1 b and atmost 2 c
int main() {
    printf("%d = %d,%d,%d\n", 1, solve(1), solve1(1), solve0(1));
    printf("%d = %d,%d,%d\n", 2, solve(2), solve1(2), solve0(2));
    printf("%d = %d,%d,%d\n", 3, solve(3), solve1(3), solve0(3));
    printf("%d = %d,%d,%d\n", 4, solve(4), solve1(4), solve0(4));
    return 0;
}