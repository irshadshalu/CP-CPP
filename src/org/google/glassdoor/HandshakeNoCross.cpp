#include<vector>
using namespace std;

typedef long long ll;

// can use top down dp
ll recurse(int n) {
    if(n % 2) return 0;
    else if (n == 0) return 1L;
    ll res = 0;
    for(int i = 0; i < n; i += 2) {
        res += recurse(i) * recurse(n - i - 2);
    }
    return res;
}

void catalan(int N) {
    ll ans = recurse(N);
    printf("handshakes = %lld\n", ans);
}

int main() {
    // no of handshakes possible such that no two handshakes cross
    catalan(8);
    return 0;
}