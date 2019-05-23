#include<vector>
using namespace std;

typedef vector<int> vi;

vector<vi> memo;

int recur(int x, int y) {
    if(memo[x][y] != -1) return memo[x][y];

    if(x == 1) return memo[1][y] = y;
    if(y == 1) return memo[x][1] = x;
    if(x == y) return memo[x][y] = 1;

    int vc = 0, hc = 0;
    int vertical_cut = INT_MAX;
    for(int h = 1; h <= x/2; ++h) {
        int t = recur(h, y) + recur(x-h, y);
        if(t < vertical_cut) vertical_cut = t, vc = h;
    }
    
    int horizontal_cut = INT_MAX;
    for(int v = 1; v <= y/2; ++v) {
        int t = recur(x, v) + recur(x, y-v);
        if(t < horizontal_cut) horizontal_cut = t, hc = v;
    }

    // printf("%d * %d = %s cut at %d for %d squares\n", x, y, horizontal_cut < vertical_cut? "horizontal": "vertical", horizontal_cut < vertical_cut? hc: vc, min(horizontal_cut, vertical_cut));

    return memo[x][y] = min(horizontal_cut, vertical_cut);
}

// minimum no of squares
void solve(int m, int n) {
    memo.assign(m+1, vi(n+1, -1));
    int ans = recur(m, n);
    printf("Min Squares = %d\n", ans);
}

int main() {
    solve(9, 10); // 2*2, 2*2, 4*4, 4*4, 5*5, 5*5
    return 0;
}