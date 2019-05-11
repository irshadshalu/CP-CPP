#include<iostream>
using namespace std;

// Mac Compile: g++ E_1_ReadDouble.cpp -o E_1_ReadDouble.run
int main() {
    freopen("E_1_ReadDouble.in", "r", stdin);
    freopen("E_1_ReadDouble.out", "w", stdout);

    double d;
    while(scanf("%lf", &d)!=-1) {
        printf("%7.3lf\n", d);
    }
    return 0;
}