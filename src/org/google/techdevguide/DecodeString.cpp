#include<string>
#include<vector>
#include<cctype>
using namespace std;

int findcos(int idx, string pat) {
    int ct = 1;
    for(int i = idx + 1; i < pat.size(); ++i) {
        if(pat[i] == '[') ++ct;
        else if(pat[i] == ']') {
            --ct; 
            if(ct == 0 ) return i;
        }
    }
    return -1;
}

string decode(string pat) {
    string res = "";
    // printf("decoding %s\n", pat.c_str());
    for(int idx = 0; idx < pat.size(); ++idx) {
        int j, ct;
        size_t sz;
        string app;
        if(pat[idx] >= '0' && pat[idx] <= '9') {
            string suf = pat.substr(idx);
            ct = stoi(suf);
            sz = idx;
            while(isdigit(suf[++sz]));
            // printf("idx = %d ct = %d pat[sz] = %c\n", idx, ct, pat[sz]);
            // int temp; scanf("%d", &temp);
            if(pat[sz] == '[') {
                j = findcos(sz, pat);
                app = decode(pat.substr(sz + 1, j - sz -1));             // recursively solve []
                while (ct-- > 0)
                    res += app; 
                idx = j;
            } else {
                res += pat.substr(idx, sz - idx);                        // number is a normal string
                idx = sz - 1;                                            // idx is incremented anyhow
            }
        }
        else if(pat[idx] == '[' && !isdigit(pat[idx-1])) {               // invalid brackets
            j = findcos(idx, pat);
            idx = j;
        }
        else {
            res.push_back(pat[idx]);
        }
    }
    // printf("decoded %s to %s\n", pat.c_str(), res.c_str());
    return res;
}

int main() {
    vector<string> pat;
    // c++11
    pat = {"5[a]", "a0[abc]", "a[]b", "123a", "3[abc]4[ab]c", "2[3[a]b]" ,"2[aabc]d", "2[2[abbb]c]"};
    for(string enc: pat) {
        printf("%s => %s\n", enc.c_str(), decode(enc).c_str());
        // int temp; scanf("%d", &temp);
    }
    return 0;
}