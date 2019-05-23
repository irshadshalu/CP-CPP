#include<vector>
using namespace std;

int x, y, p;

// iterative (x^y)%p in O(log y)
void modExp() {
    int res = 1;
    int _x = x%p;
    int _y = y;
    while(_y > 0) {
        if(_y & 1) res = (res * _x) % p;
        _y >>= 1;
        _x = (_x * _x) % p;
    }
    printf("(%d^%d)%%%d = %d\n", x, y, p, res);
}

int main() {
    x = 9, y = 69, p = 1000007;
    modExp();
    return 0;
}