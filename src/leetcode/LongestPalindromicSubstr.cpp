// https://leetcode.com/problems/longest-palindromic-substring/
// Manacher?

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty() || s == "") return "";
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        
        int ans = 0, N = s.size();
        int start = -1, end = -1;
        for(int i = 0; i < N; ++i) {
            //current odd
            int l = i, r = i;
            while(l - 1 >= 0 && r + 1 < N) {
                if(s[l-1] == s[r+1]) --l, ++r;
                else break;
            }
            int temp = r-l+1;
            if(temp > ans) { ans = temp, start = l, end = r; }
            
            //current first of 2 even's
            l = i, r = i + 1;
            if(r < N && s[l] == s[r]) {
                while(l - 1 >= 0 && r + 1 < N) {
                    if(s[l-1] == s[r+1]) --l, ++r;
                    else break;
                }
                temp = r-l+1;
                if(temp > ans) { ans = temp, start = l, end = r; }
            }
        }
        return s.substr(start, end-start+1);
    }
};