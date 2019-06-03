#include<string>
#include<unordered_map>
using namespace std;

// O(N)
// longest substring with k unique characters
void solve(string str, int K) {
    printf("input = %s\n", str.c_str());
    int ans = 0;
    unordered_map<char, int> mp; // count of each str[i]
    for(int ct = 0, l = 0, r = 0; r < str.size(); ++r) {
        char ch = str[r];
        if(mp.find(ch) == mp.end() || mp[ch] == 0) mp[ch] = 1, ++ct;
        else ++mp[ch];
        if(ct == K+1 && --ct) while(--mp[str[l++]] > 0);
        ans = max(ans, r-l+1);
    }
    printf("ans = %d\n", ans);
}

int main() {
    // freopen("kUniqueChars.out", "w", stdout);
    solve("aabbccddd", 2);
    solve("abcccdefghefgh", 4);
    return 0;
}