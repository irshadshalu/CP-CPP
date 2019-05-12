#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;

vector<int> arr;
int N;

void setup() {
    srand(time(NULL));
    N = 1000000;
    for(int i=0; i<N; ++i)
        arr.push_back(rand()%3000000);    
    sort(arr.begin(), arr.end());
    printf("RAND_MAX = %d\n", RAND_MAX);
}

int main() {
    freopen("E_6_BinarySearch.out", "w", stdout);
    setup();

    printf("Size = %d\n", N);
    int K = 10;
    // O(Klog(N))
    for(int i=0; i<K; ++i) {
        int t = rand() % 3000000;
        // O(log(N))
        auto it = lower_bound(arr.begin(), arr.end(), t);
        int pos = it - arr.begin();
        printf("lower_bound(%d) = %d at pos: %d\n", t, *it, pos);
    }

    return 0;
}