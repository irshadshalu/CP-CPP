#include<string>
#include<vector>
using namespace std;

void computeLps(const string &pat, vector<int> &lps) {
    int M = pat.size(); lps.resize(M+1);
    int i = 0, j = -1; lps[0] = -1;
    while(i < M) {
        while(j >= 0 && pat[i] != pat[j]) j = lps[j];
        ++i; ++j;
        lps[i] = j;
    }
    printf("LPS (length-1) for %s : ", pat.c_str());
    // std=c++11
    for(int x: lps) printf("%d ", x); printf("\n");               // lenght is +1 lps is exactly the index till where prefix and suffix matches
}

void kmpSearch(const string &pat, const string &text) {
    printf("Text: %s \nPat %s\n", text.c_str(), pat.c_str());

    vector<int> lps;
    computeLps(pat, lps);

    int M = pat.size(), N = text.size(), i = 0, j = 0;
    while(i < N) {
        while(j >=0 && text[i] != pat[j]) j = lps[j];
        ++i; ++j;
        if(j == M) {
            printf("Found pattern at %d index!\n", i-j);
            j = lps[j];
        }
    }
}

int main() {
    string text = "aabaadcadaabaabaae";
    string pat = "aabaa";
    kmpSearch(pat, text);
    return 0;
}