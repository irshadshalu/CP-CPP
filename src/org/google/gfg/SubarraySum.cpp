#include<vector>
#include<unordered_map>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;

// O(N)
// prints all indexes
void subArrSum(const vi &arr, int sum) {
    unordered_map<int, vi> hash;
    hash[0] = vi{-1};
    int current = 0;
    vector<ii> occur;
    for(int i = 0; i < arr.size(); ++i) {
        current += arr[i];
        if(hash.find(current-sum) != hash.end()) {
            for(int x: hash[current-sum])
                occur.push_back(ii(x+1, i));
        }
        if(hash.find(current) == hash.end()) 
            hash[current] = vi{i};                                              // c++11
        else
            hash[current].push_back(i);
    }
    sort(occur.begin(), occur.end());
    for(auto a: occur) printf("Found sum between index %d and %d\n", a.first, a.second);
}

int main() {
    vi arr = {1, 2, 3, 3, 2, 1};
    subArrSum(arr, 6);
    return 0;
}