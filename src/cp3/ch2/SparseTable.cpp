#include<vector>
#include<cmath>
using namespace std;

typedef vector<int> vi;

/*
 * spt[i][j] = min in A[i...(i+2^j-1)] i.e. for length 1<<j segment
 */

class SparseTable {
    private:
        int N;
        vi A;
        vector<vi> spt;

        void build() {
            for(int i = 0; i < N; ++i) spt[i][0] = i;           // length 1

            for(int j = 1; (1<<j) <= N; ++j)                    // max length for segment is 2^j = N for i = 0
            for(int i = 0; i + (1<<j) - 1 < N; ++i) {           // for i where [i ... i+(2^j)-1] can be accomodated
                int ptr = i + (1 << (j-1));                     // start of next j-1 segment
                if(A[ spt[i][j-1] ] <= A[ spt[ptr][j-1] ]) 
                    spt[i][j] = spt[i][j-1];
                else 
                    spt[i][j] = spt[ptr][j-1];
            }
        }

    public:
        SparseTable(const vi &arr) {
            N = arr.size(); A = arr;
            int w = (int)ceil(log2(N));
            spt.assign(N, vi(w));

            build();
        }

        int rmq(int i, int j) {
            int k = (int)floor(log2(j - i + 1));                // largest k for which 2^k <= length of query
            int first = spt[i][k];                              // segment starting from i of length k      
            int second = spt[j-(1<<k)+1][k];                    // segment ending at j of length k
            return (A[first] <= A[second]) ? first : second;
        }
};

int main() {
    vi arr = { 18, 17, 13, 19, 15, 11, 20 }; // the original array
    SparseTable spt(arr);
    printf("RMQ(1, 3) = %d\n", spt.rmq(1, 3)); // answer = index 2
    printf("RMQ(4, 6) = %d\n", spt.rmq(4, 6)); // answer = index 5
    return 0;
}