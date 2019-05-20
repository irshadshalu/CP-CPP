#include<vector>
#include<iostream>
using namespace std;

typedef vector<int> vi;

int N, ways;
vi row;

bool place(int r, int c) {
    for(int prev = 0; prev < c; ++prev) 
        if(row[prev] == r || abs(row[prev] - r) == abs(prev - c))               // same row or diagonal
            return false;
    return true;
}

// recursively put in each column
void backtrack(int c) {
    if(c == N) { ++ways; return; }
    for(int r = 0; r < N; ++r)
        if(place(r,c)) 
        { row[c] = r; backtrack(c+1); }
}

// time complexity: sub-O(N!) for each row permutation
void solve(int q) {
    N = q;
    ways = 0;
    row.assign(N, -1);
    backtrack(0);
}

/*
 * Less than 1 second for N < 13:
 * 1(1) 0(2) 0(3) 2(4) 10(5) 4(6) 40(7) 92(8) 352(9) 724(10) 2680(11) 14200(12) 
 */ 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int mx = 12;
    for(int i = 1; i <= mx; ++i) {
        solve(i);
        printf("%d(%d) ", ways, i);
    } printf("\n");
    return 0;
}