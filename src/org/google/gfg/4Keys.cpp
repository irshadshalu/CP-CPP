// https://www.geeksforgeeks.org/how-to-print-maximum-number-of-a-using-given-four-keys/
#include<vector>
using namespace std;

int solve(int K) {
    vector<int> dp(K+1, 0);
    for(int i = 0; i <= K; ++i) {
        if(i <= 6) dp[i] = i;
        else for(int j = i - 3; j >= 0; --j)
                dp[i] = max(dp[i], (i-j-1)*dp[j]);
    }
    return dp[K];
}

int main() {
    for(int i = 0; i <= 20; ++i)
        printf("Max A's using %d strokes = %d\n", i, solve(i));
    return 0;
}