#include<string>
#include<unordered_map>
using namespace std;

// O(N)
// longest substring with k unique characters
void solve(string str, int K) {
    printf("input = %s\n", str.c_str());
    unordered_map<char, int> hash;
    int ans = 0, N = str.size();
    int prev = 0, current = 0;
    for(int i = 0; i < N; ++i) {
        // printf("index = %d => ", i);
        // for(auto h: hash) if(h.first >= 'a' && h.first <= 'z') printf("%c(%d) ", h.first, h.second); printf("\n");
        if(hash.find(str[i]) == hash.end() || hash[str[i]] == 0) {
            hash[str[i]] = 1; ++current;
        } else {
            hash[str[i]]++;
        }
        while(current > K && prev < i) {
            hash[str[prev]]--;
            if(hash[str[prev]] == 0) --current;
            prev++;
        }
        if(current == K) ans = max(ans, i - prev + 1);      // printf("found at (%d, %d)\n", prev, i);
    }
    printf("ans = %d\n", ans);
}

int main() {
    // freopen("kUniqueChars.out", "w", stdout);
    solve("aabbcc", 3);
    solve("abcccdefghefgh", 4);
    return 0;
}