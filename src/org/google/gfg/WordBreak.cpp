#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

void solve(string text, const vector<string> &wlist) {
    vector<bool> flag;
    int N = text.size();
    flag.assign(N, false);                  // flag[i] true if text[0..i] can be broken
    unordered_set<string> dict(wlist.begin(), wlist.end());

    for(int i = 0; i < N; ++i) {
        if(dict.find(text.substr(0, i+1)) != dict.end()) flag[i] = true;
        else
        for(int j = 0; j < i; ++j) 
        if(flag[j] && dict.find(text.substr(j+1, i-j)) != dict.end()) {
            flag[i] = true; break;
        }
    }
    // for(int i = 0; i < N; ++i) printf("%s: %s\n", text.substr(0, i+1).c_str(), flag[i]? "true": "false");
    printf("%s\n", flag[N-1]? "true": "false");
}

int main() {
    vector<string> listw = { "i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go", "mango"};

    solve("ilikesamsung", listw);
    solve("icecream", listw);
    solve("mangoes", listw);

    return 0;
}