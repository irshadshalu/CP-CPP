// https://leetcode.com/problems/container-with-most-water/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& tower) {
        // 2 pointers
        int rain = 0, l = 0, r = tower.size() - 1;
        int lmx =  0, rmx = 0;
        while(l < r) {
            if(tower[l] <= tower[r]) {
                if(tower[l] >= lmx) lmx = tower[l];
                    // above each tower (fill with 0's)
                    rain += lmx - tower[l];
                l++;
            } else {
                if(tower[r] >= rmx) rmx = tower[r];
                    rain += rmx - tower[r];
                r--;
            }
        }
        return rain;    
    }
    
    int maxArea(vector<int>& height) {
        int N = height.size();
        // 2 pointers
        int l = 0, r = N - 1;
        int area = 0;
        while(l<r) {
            area = max(area, min(height[l], height[r]) * (r-l));
            if(height[l] < height[r]) ++l;
            else --r;
        }
        return area;
    }
};