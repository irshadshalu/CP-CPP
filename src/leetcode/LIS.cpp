#include<vector>
using namespace std;

typedef vector<int> vi;

vi arr;

// using output sensitive greedy method
void lis() {
    vi l; // l[i] stores smallest last element in length-i LIS
    for(int i = 0; i < arr.size(); ++i) {
        auto pos = lower_bound(l.begin(), l.end(), arr[i]);
        if(pos == l.end()) l.push_back(arr[i]);
        else *pos = arr[i];
        printf("l at %d -> ", arr[i]); for_each(l.begin(), l.end(), [](int x){ printf("%d ", x);}); printf("\n");
    }
    printf("LIS length = %lu\n", l.size());
}

int main() {
    arr = {-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4 };
    lis();
    return 0;
}