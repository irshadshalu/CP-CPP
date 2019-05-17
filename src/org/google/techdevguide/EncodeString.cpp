#include<string>
#include<vector>
using namespace std;

bool isRep(const string &rep, const string &str) {
    int m = rep.size(), n = str.size();
    int i = 0, j = 0;
    while(j < n) {
        if(rep[i] != str[j]) return false;
        i++; j++;
        if(i == m) i = 0;
    }
    return true;
}

string encode(string pat) {
    int N = pat.size();
    vector<vector<string>> dp;
    dp.resize(N + 1, vector<string>(N + 1));

    for(int len = 0; len < N; len++)
    for(int i = 0; i < N - len; i++) {
        int j = i + len;
        string sub = pat.substr(i, j - i + 1);
        if(j - i + 1 <= 4) {
            dp[i][j] = sub;                                                         // no point of encoding aaaa
        } else {
            dp[i][j] = sub;
            for(int k = i; k < j; k++) 
            if((dp[i][k] + dp[k+1][j]).size() < dp[i][j].size())                    // try all points of combining encoded subs
                dp[i][j] = dp[i][k] + dp[k+1][j];
            
            for(int k = 0; k < sub.size(); ++k) {                                   // check if sub can be repeated
                string rep = sub.substr(0, k + 1);
                if((sub.size() % rep.size() == 0) && isRep(rep, sub)) {
                    string ss = to_string(sub.size()/rep.size()) + "[" + dp[i][i + k] + "]";   // note!
                    if(ss.size() < dp[i][j].size())
                        dp[i][j] = ss;
                }
            }
        }
    }

    return dp[0][N - 1];
}

int main() {
    vector<string> pat;
    // c++11
    pat = {"aaaaa", "a", "ab", "123a", "abcabcabcababababc", "aaabaaab" ,"aabcaabcd", "abbbabbbcabbbabbbc"};
    for(string p: pat) {
        printf("%s => %s\n", p.c_str(), encode(p).c_str());
        // int temp; scanf("%d", &temp);
    }
    return 0;
}