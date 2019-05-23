// https://www.geeksforgeeks.org/sum-of-bit-differences-among-all-pairs/
#include<vector>
using namespace std;

typedef vector<int> vi;

vi arr;

// unique pair don't count twice for (i,j) i.e. (j,i)
void solve() {
    int N = arr.size(), ans = 0;
    for(int i = 0; i < 31; ++i) {
        int zero = 0, one = 0, bitp = 1 << i;
        for(int j = 0; j < N; ++j) 
            (arr[j] & bitp)? ++one: ++zero;
        ans += zero*one;
    }
    printf("ans = %d\n", ans);
}

int main() {
    arr = {1, 3, 5};
    solve(); 
    return 0;
}