#include<string>
#include<vector>
using namespace std;

void computeLps(const string &pat, vector<int> &lps) {
    int M = pat.size();
    lps.resize(M);
    lps[0] = 0;
    int prv = 0, j = 1;
    while(j < M) {
        if(pat[prv] == pat[j]) {
            lps[j] = ++prv;                             // # letters matched
            ++j;
        } 
        else {
            if(prv != 0) prv = lps[prv-1];
            else lps[j++] = 0;
        }
    }
    printf("LPS for %s : ", pat.c_str());
    // std=c++11
    for(int x: lps) printf("%d ", x); printf("\n");
}

void kmpSearch(const string &pat, const string &text) {
    printf("Text: %s \nPat %s\n", text.c_str(), pat.c_str());

    vector<int> lps;
    computeLps(pat, lps);

    int M = pat.size(), N = text.size(), i = 0, j = 0;
    while(i < N) {
        if(text[i] == pat[j]) ++i, ++j;
        else {
            if(j != 0) j = lps[j-1];
            else ++i;
        }
        if(j == M) {
            printf("Found pattern at %d index!\n", i-j);
            j = lps[j-1];
        }
    }
}

int main() {
    string text = "aabaadcadaabaabaae";
    string pat = "aabaa";
    kmpSearch(pat, text);
    return 0;
}