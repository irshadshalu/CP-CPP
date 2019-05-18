#include<string>
#include<vector>
using namespace std;

/*
 * Check if a string is repeition of some substring in O(N)
 * Hint: Use lps
 */ 

void computeLps(const string &pat, vector<int> &lps) {
    int M = pat.size();
    lps.resize(M);
    lps[0] = 0;
    int ptr = 0, j = 1;
    while(j < M) {
        if(pat[ptr] == pat[j]) {
            lps[j] = ++ptr;
            ++j;
        }
        else {
            if(ptr != 0) ptr = lps[ptr - 1];
            else lps[j++] = 0;
        }
    }
    printf("LPS for %s : ", pat.c_str());
    // std=c++11
    for(int x: lps) printf("%d ", x); printf("\n");
}

void checkRep(const string &pat) {
    printf("Pat: %s\n", pat.c_str());
    vector<int> lps;
    computeLps(pat, lps);
    int N = pat.size();
    int mxl = lps[N-1];
    if(N%(N-mxl) == 0) printf("String repeated by %s!\n\n", pat.substr(0, N - mxl).c_str());
    else printf("String is not repeated by any substring!\n\n");
}

int main() {
    vector<string> pat = {"abababab", "cbacbacba", "xyzxxyz"};
    for(string p: pat)
        checkRep(p);
    return 0;
}