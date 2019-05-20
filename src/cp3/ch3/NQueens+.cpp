#include<bitset>
#include<iostream>
using namespace std;

int N, ways;
bitset<35> rw, ld, rd;                                      // 2 * N - 1 left and right diagonals

void backtrack(int c) {
    if(c == N) { ++ways; return; }
    for(int r = 0; r < N; ++r) {
        int d1 = r - c + N - 1;                             // with offset
        int d2 = r + c;
        if(!rw[r] && !ld[d1] && !rd[d2]) {
            rw[r] = ld[d1] = rd[d2] = true; 
            backtrack(c + 1);
            rw[r] = ld[d1] = rd[d2] = false;
        }
    }
}

void solve(int q) {
    N = q;
    ways = 0;
    backtrack(0);
}

/*
 * Less than 1 second for N < 15:
 * 1(1) 0(2) 0(3) 2(4) 10(5) 4(6) 40(7) 92(8) 352(9) 724(10) 2680(11) 14200(12) 73712(13) 365596(14)
 */ 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int mx = 15;

    for(int i = 1; i <= mx; ++i) {
        solve(i);
        printf("%d(%d) ", ways, i);
    } printf("\n");

    return 0;
}