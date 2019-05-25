#include<vector>
using namespace std;

typedef vector<int> vi;

int N;
vi marks;

// O(T^2)
void solve() {
    marks.insert(marks.begin(), 0);
    marks.push_back(N);
    int T = marks.size();

    vector<vi> dp, pos;
    dp.resize(T, vi(T));
    pos.resize(T, vi(T));

    for(int len = 1; len < T; ++len) 
    for(int left = 0; left + len < T; ++left) {
        int right = left + len;
        if(len == 1) {
            dp[left][right] = 0;
            pos[left][right] = left;
            continue;
        }
        
        int low = pos[left][right-1];                                   // knuth-yao optimization
        int high = pos[left+1][right];                                  // instead of (low, high) = (left+1, right-1)
        
        int cost = INT_MAX, idx = -1;
        for(int i = max(left+1, low); i <= min(high, right-1); ++i) {
            int temp = dp[left][i] + dp[i][right] + marks[right] - marks[left];
            if(temp < cost) 
                cost = temp, idx = i;
        }
        dp[left][right] = cost;
        pos[left][right] = idx;
        // printf("dp[%d][%d] = %d\t", left, right, dp[left][right]);
    }
    printf("Min cost = %d start cutting at %d\n", dp[0][T-1], marks[pos[0][T-1]]);
}

int main() {
    marks = {25, 50, 75}; N = 100;
    solve();

    return 0;
}