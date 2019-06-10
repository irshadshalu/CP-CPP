#include<vector>
#include<string>
#include<iostream>
#include<unordered_set>
using namespace std;

typedef vector<int> vi;

int N;
string inp;

// vector<int> visit;
// vector<vector<unordered_set<int>>> memo;

vector<vi> ans;

void recursive(int idx, vi curr) {
    if(idx == N) {
        if(curr.size() == 7)
            ans.push_back(curr);
        return;
    }

    // printf("%s curr = ", inp.substr(0, idx).c_str());
    // for(int x: curr) printf("%d ", x); printf("\n");

    if(inp[idx] == '0') return;
    if(curr.size() > 7) return;

    int t = inp[idx] - '0';
    if(find(curr.begin(), curr.end(), t) == curr.end()) {
        vi temp = curr;
        temp.push_back(t);
        recursive(idx + 1, temp);
    }

    t = (idx < N - 1)? (inp[idx]-'0')*10 + (inp[idx+1]-'0'): -1;
    if (t != -1 && t <= 59 && find(curr.begin(), curr.end(), t) == curr.end()) {
        vi temp = curr;
        temp.push_back(t);
        recursive(idx + 2, temp);
    }
}

void solve() {
    N = inp.size();
    // memo.clear(); memo.resize(N+1);
    // for(int i = 0; i <= N; ++i) {
    //     vector<unordered_set<int>> t; memo[i] = t;
    // }
    // visit.assign(N+1, -1);
    
    ans.clear();
    recursive(0, vi{});
    for(int i = 0; i < ans.size(); ++i) {
        vi arr = ans[i];
        cout << inp << " -> ";
        for(int j = 0; j < arr.size(); ++j)
            if(j != arr.size() - 1) cout << arr[j] << " ";
            else cout << arr[j] << endl;
    }

}

int main() {
    freopen("WinningTicket.in", "r", stdin);
    freopen("WinningTicket.out", "w", stdout);
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> inp;
        solve();
    }
    return 0;
}