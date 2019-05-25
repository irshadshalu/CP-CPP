#include<string>
#include<vector>
using namespace std;

/*
 * Check if a string is repeition of some substring in O(N)
 * Hint: Use lps
 */ 

void computeLps(const string &pat, vector<int> &lps) {
    int M = pat.size();
    lps.resize(M+1); lps[0] = -1;
    int i = 0, j = -1;
    while(i < M) {
        while(j >= 0 && pat[i] != pat[j]) j = lps[j];
        i++; j++;
        lps[i] = j;
    }
    printf("LPS for %s : ", pat.c_str());
    for(int x: lps) printf("%d ", x); printf("\n");
}

void checkRep(const string &pat) {
    printf("Pat: %s\n", pat.c_str());
    vector<int> lps;
    computeLps(pat, lps);
    int N = pat.size();
    int mxl = lps[N];
    if(N % (N - mxl) == 0) printf("String repeated by %s!\n\n", pat.substr(0, N - mxl).c_str());
    else printf("String is not repeated by any substring!\n\n");
}

int main() {
    vector<string> pat = {"abababab", "cbacbacba", "xyzxxyz"};
    for(string p: pat)
        checkRep(p);
    return 0;
}