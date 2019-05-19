// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<char, int> vis;
        int ans = 0, ptr = 0;
        for(int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if(vis.find(ch) == vis.end() || vis[ch] < ptr) {
                vis[ch] = i;
                ans = max(ans, i - ptr + 1);
            } else {
                ptr = vis[ch] + 1;
                vis[ch] = i;
            }
        }
        return ans;
    }
};