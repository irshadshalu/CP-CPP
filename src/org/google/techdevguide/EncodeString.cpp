#include<string>
#include<vector>
using namespace std;

// Using KMP Preprocess for each starting index: sub O(N^2)
// Stores repetition with smallest substring
void preCompute(const string &pat, vector<vector<string>> &rep) {
    int N = pat.size();
    vector<int> lps(N+1);
    for(int i = 0; i < N; ++i) {
        string sub = pat.substr(i);
        lps[0] = -1;
        int j = 0, k = -1;
        rep[i][i] = sub.substr(0, 1);
        while(j < sub.size()) {
            while(k >= 0 && sub[j] != sub[k]) k = lps[k];
            j++; k++;
            lps[j] = k;

            if(j % (j-lps[j]) == 0) 
                rep[i][i+j-1] = sub.substr(0, j-lps[j]);
            else
                rep[i][i+j-1] = sub.substr(0, j);
        }
    }

    // for(int i = 0; i < N; ++i)
    // for(int j = i; j < N; ++j) {
    //     string a = pat.substr(i, j-i+1); string b = rep[i][j];
    //     printf("%s = %lu[%s]\n", a.c_str(), a.size()/b.size(), b.c_str());
    // } printf("precompute complete!\n");
}

// DP: O(N^3)
string encode(const string &pat) {
    int N = pat.size();

    vector<vector<string>> rep;
    rep.resize(N, vector<string>(N));
    preCompute(pat, rep);                                                          // alternative: find repeating substring inside 2 loops in O(N)

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
            
            if(rep[i][j].size() < sub.size()) {                                     // check if sub can be repeated
                int u = sub.size(), v = rep[i][j].size();
                string ss = to_string(u/v) + "[" + dp[i][i+v-1] + "]";
                if(ss.size() < dp[i][j].size()) dp[i][j] = ss;
            }
        }
    }

    return dp[0][N - 1];
}

int main() {
    // freopen("EncodeString.out", "w", stdout);
    vector<string> pat;
    pat = {"aaaaa", "a", "ab", "123a", "abcabcabcababababc", "aaaaabaaaaab" ,"aabcaabcd", "abbbabbbcabbbabbbc"};
    
    for(string p: pat) {
        printf("%s => %s\n", p.c_str(), encode(p).c_str());
    }
    return 0;
}

/*
 * Output: 
 * 
 * aaaaa => 5[a]
 * a => a
 * ab => ab
 * 123a => 123a
 * abcabcabcababababc => 3[abc]4[ab]c
 * aaaaabaaaaab => 2[5[a]b]
 * aabcaabcd => 2[aabc]d
 * abbbabbbcabbbabbbc => 2[2[abbb]c]
 * 
 */