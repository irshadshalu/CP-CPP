#include<vector>
using namespace std;

int cutRod(const vector<int> &arr) {
    vector<int> price;
    int n = arr.size();
    price.assign(n+1, -1);
    price[0]=0;

    for(int i=1; i<=n; ++i) {
        // max profit for length {i}
        int mx = 0;
        for(int j=1; j<=i; ++j) mx = max(mx, arr[j-1] + price[i-j]);
        price[i] = mx;
    }

    return price[n];
}

int main() {
    // -std=c++11
    vector<int> arr{1, 5, 8, 9, 10, 17, 17, 20};
    printf("Max obtainable value: %d\n", cutRod(arr));
    return 0;
}