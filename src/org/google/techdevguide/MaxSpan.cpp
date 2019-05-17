#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

// maxSpan([1, 2, 1, 1, 3]) → 4
// maxSpan([1, 4, 2, 1, 4, 1, 4]) → 6
// maxSpan([1, 4, 2, 1, 4, 4, 4]) → 6

vector<int> arr;

void maxSpan() {
    for_each(arr.begin(), arr.end(), [](int x) {
        printf(" %d", x);
    }); printf("");

    int ans = 0;
    unordered_map<int, int> occur;
    for(int i=0; i<arr.size(); i++) {
        int t = arr[i];
        if(occur.find(t) == occur.end()) {
            if(ans == 0 ) ans = 1;
            occur[t] = i;
        }
        else ans = max(ans, i - occur[t] + 1);
    }
    printf(" -> %d\n", ans);
}

int main() {
    arr = {1, 2, 1, 1, 3};
    maxSpan();
    
    arr = {1, 4, 2, 1, 4, 1, 4};
    maxSpan();

    arr = {2, 1, 0, 1, 0, 0};
    maxSpan();
    return 0;
}