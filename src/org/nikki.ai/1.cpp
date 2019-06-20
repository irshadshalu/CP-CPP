#include<string>
#include<vector>
#include<iostream>
using namespace std;

int n, k;
string s;

void solve() {
    int ans = 0, ct = 0;
    for(int left = -1, right = 0; right < n; ++right) {
        if(s[right] == '1') ++ct;
        while(ct > k && left < right) if(s[++left] == '1') --ct;
        ans = max(ans, right-left);
    }
    cout<< ans << endl;
}

int main() {
    freopen("1.in", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k >> s;
        solve();
    }
    return 0;
}