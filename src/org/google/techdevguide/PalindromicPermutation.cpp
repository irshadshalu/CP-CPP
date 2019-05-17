#include<string>
#include<unordered_map>
using namespace std;

bool isPal(const string &str, unordered_map<char, int> &frq) {
    for(char ch: str) {
        if(frq.find(ch) == frq.end()) frq[ch] = 1;
        else frq[ch]++;
    }
    int N = str.size(), odd = 0;
    for(auto it = frq.begin(); it != frq.end(); ++it) {
        if((*it).second % 2) ++odd;
    }
    if((N % 2 == 1 && odd == 1) || (N % 2 == 0 && odd == 0)) return true;
    return false;
}

void printPal(const string &str) {
    printf("Palindromic permutataion of %s are:\n", str.c_str());
    unordered_map<char, int> frq;
    if(!isPal(str, frq)) { printf("Invalid string!\n"); return; }
    
    char oddC = '-';
    string half = "";
    for_each(frq.begin(), frq.end(), [&oddC, &half](pair<char, int> x) {
        // printf("x = %c %d\n", x.first, x.second);
        if(x.second == 1) oddC = x.first;
        half += string(x.second / 2, x.first);                                  // Remember!!!
    });
    sort(half.begin(), half.end());
    // printf("half = %s(%ld)\n", half.c_str(), half.size());
    do {
        string res = half;
        if(oddC != '-') res.push_back(oddC);
        string temp = half;
        reverse(temp.begin(), temp.end());
        res += temp;
        printf("perm = %s\n", res.c_str());
        // int t; scanf("%d", &t);
    } while(next_permutation(half.begin(), half.end()));
}

int main() {
    string str = "aabbcadad";
    printPal(str);
    return 0;
}