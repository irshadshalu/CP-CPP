// https://leetcode.com/problems/generate-parentheses/

#include<string>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> ii;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        queue<string> pat;
        queue<ii> rem;
        pat.push(""); 
        // (i,j) = (available for open, to close)
        rem.push(ii(n, 0));
        while(!pat.empty()) {
            string p = pat.front();
            ii r = rem.front();
            pat.pop();
            rem.pop();
            
            if(r.first == 0 && r.second == 0) ans.push_back(p);
            
            if(r.first > 0) {
                pat.push(p + "(");
                rem.push(ii(r.first - 1, r.second + 1));
            }
            if(r.second > 0) {
                pat.push(p + ")");
                rem.push(ii(r.first, r.second - 1));
            }
        }
        return ans;
    }
};