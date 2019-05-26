#include<vector>
using namespace std;

typedef vector<int> vi;

int W;
vi val, wt;

// Repetition allowed: 2loops first value to maximize, second each 'item' (a item will be already used in previous value to maximize) 
// Unbounded can use any no of times
void solve() {
    int N = wt.size();
    vi dp;
    dp.assign(W+1, 0);
    for(int i = 0; i <= W; ++i) {
        for(int j = 0; j < N; ++j)
        if(wt[j] <= i)
            dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);
    }
    printf("values array = "); for(auto v: val) printf("%d ", v); printf("\n");
    printf("weight array = "); for(auto w: wt) printf("%d ", w); printf("\n");
    printf("Intermediate results :\n"); for(int w = 5; w <= W; w+=5) printf("%d -> (%d)\n", w, dp[w]); printf("\n");
    printf("Maximum profit = %d\n", dp[W]);
}

int main() {
    freopen("UnboundedKnapsack.out", "w", stdout);

    val = {5, 60, 100, 120, 250}; 
    wt = {5, 10, 20, 30, 40}; 
    W = 60;

    solve(); 

    return 0;
}