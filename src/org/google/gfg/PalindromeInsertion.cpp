#include<vector>
#include<string>
using namespace std;

void solve(string s) {
    vector<vector<int> > dp;
    int n = s.size();
    dp.resize(n, vector<int>(n));

    for(int len = 1; len <= n; ++len)
    for(int l = 0; l < n - len + 1; ++l) {
        int r = l + len - 1;
        if(l == r) dp[l][r] = 0;
        else if(s[l] == s[r]) dp[l][r] = (l+1 == r)? 0: dp[l+1][r-1];
        else dp[l][r] = 1 + min(dp[l+1][r], dp[l][r-1]);
    }
    printf("Min insertions = %d\n", dp[0][n-1]);
}

// minimum insertions in the string to make it palindrome
int main() {
    solve("ab");
    solve("aa");
    solve("abcd");
    solve("abcda");
    solve("abcde");
    return 0;
}