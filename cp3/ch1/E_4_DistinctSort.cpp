#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

#define rep($, a, b) for(int $=(a); $<(b); ++$)

vector<int> arr;

// g++ -std=c++11 -o a.run a.cpp
int main() {
    freopen("E_4_DistinctSort.out", "w", stdout);

    rep(i, 0, 10) {
        int ct = rand() % 20 + 1;
        rep(j, 0, ct) arr.push_back(rand() % 10);

        printf("Original array = ");
        for_each(arr.begin(), arr.end(), [](int x) { printf("%d ", x); });
        
        // vector<int>::iterator it
        sort(arr.begin(), arr.end());
        auto it = unique(arr.begin(), arr.end());
        arr.resize(it-arr.begin());

        printf("\nDistinct Sorted Array = ");
        for_each(arr.begin(), arr.end(), [](int x) { printf("%d ", x); });
        printf("\n\n");
        arr.clear();
    }
    return 0;
}