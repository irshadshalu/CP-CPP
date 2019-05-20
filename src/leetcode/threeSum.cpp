// https://leetcode.com/problems/3sum://leetcode.com/problems/3sum

#include<vector>
using namespace std;

typedef vector<int> vi;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vi> ans;        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1, r = nums.size() - 1;
            int x = -nums[i];
            while(l < r) {
                if(nums[l] + nums[r] == x) {
                    ans.push_back({-x, nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l+1]) ++l; 
                    while(l < r && nums[r-1] == nums[r]) --r;
                    ++l; --r;
                }
                else if(nums[l] + nums[r] > x) --r;
                else ++l;
            }
        }
        return ans;
    }
};