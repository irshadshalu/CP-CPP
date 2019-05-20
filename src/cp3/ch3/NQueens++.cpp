#include<bitset>
#include<iostream>
using namespace std;

int N, ways, DELIM;                                 

void backtrack(int rw, int ld, int rd) {
    if(rw == DELIM) { ++ways; return; }                     // all rows used
    int pos = DELIM & (~(rw | ld | rd));                    // available rows for this column
    while(pos) {                                            // only for 1's in pos
        int p = pos & -pos;                                 // LSOne
        pos -= p;
        backtrack(rw | p, (ld | p) << 1, (rd | p) >> 1);    // flag row, shift for left & right diagonals by 1
    }
}

void solve(int q) {
    N = q;
    ways = 0;
    DELIM = (1 << N) - 1;
    backtrack(0, 0, 0);
}

/*
 * Less than 1 second for N < 17:
 * 1(1) 0(2) 0(3) 2(4) 10(5) 4(6) 40(7) 92(8) 352(9) 724(10) 2680(11) 14200(12) 73712(13) 365596(14) 2279184(15) 14772512(16) 
 */ 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int mx = 16;

    for(int i = 1; i <= mx; ++i) {
        solve(i);
        printf("%d(%d) ", ways, i);
    } printf("\n");

    return 0;
}