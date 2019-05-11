#include<iostream>
#include<cmath>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)

double pi = 2.0 * acos(0.0);

int main() {
    freopen("E_2_PrintPi.out", "w", stdout);

    rep(i, 0, 10) {
        // generates [1-15]
        int temp = rand() % 15 + 1;
        printf("%d = %.*lf\n", temp, temp, pi);
    }
    return 0;
}