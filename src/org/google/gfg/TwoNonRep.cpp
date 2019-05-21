#include<vector>
#include<unordered_set>
using namespace std;

typedef vector<int> vi;

vi arr;

// Time = O(N) and Space = O(N)
void approach1() {
    unordered_set<int> hash;
    for(auto a: arr) {
        if(hash.find(a) == hash.end()) hash.insert(a);
        else hash.erase(a);
    }
    printf("Elements occuring odd no of times = ");
    for(auto x: hash) printf("%d ", x); printf("\n");
}

// least significant 1 for x => x & (-x) => x & ~(x-1)

void approach2() {
    int xori = arr[0];                                                // variable xor throws error?
    for(int i = 1; i < arr.size(); ++i) xori = xori ^ arr[i];

    int lsOne = xori & (-xori);                                       // this is set in one of x & y
    int x = -1, y = -1;
    for(int i = 0; i < arr.size(); ++i) {
        if(arr[i] & lsOne) {
            if(x == -1) x = arr[i];
            else x = x ^ arr[i];
        }
        else {
            if(y == -1) y = arr[i];
            else y = y ^ arr[i];
        }
    }
    printf("Elements occuring odd no of times = %d %d\n", x, y);
}

int main() {
    // 2 elements occuring once and other even no times
    arr = {2, 3, 7, 9, 11, 2, 3, 11};
    approach1();
    approach2();
}