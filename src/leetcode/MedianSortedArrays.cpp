// https://leetcode.com/problems/median-of-two-sorted-arrays

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& ar, vector<int>& br) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(ar.size() > br.size()) swap(ar, br);
        int N = ar.size(), M = br.size();
        int low = 0, high = N, sz = M + N;
        int a, b; // # elements in ar and br
        double median = -1;
        
        while(low <= high) {
            a = (low + high) / 2;
            b = (sz+1)/2 - a;  
            
            // at most 1 more in first half i.e. ar[0..a-1] & br[0..b-1] in case of N+M odd
            // printf("a, b: %d, %d\n", a, b);
            
            if(a < N && b > 0 && br[b-1] > ar[a])
                low = a + 1;            
            else if (a > 0 && b < M && ar[a - 1] > br[b])         
                high = a - 1; 
            else {
                if(a == 0)
                    median = br[b - 1];             
                else if (b == 0)             
                    median = ar[a - 1];             
                else            
                    median = max(ar[a - 1], br[b - 1]);             
                break; 
            }
        }
        
        if (sz % 2) 
            return median; 
        if (a == N) 
            return (median + br[b]) / 2.0; 
        if (b == M) 
            return (median + ar[a]) / 2.0; 
      
        return (median + min(ar[a], br[b])) / 2.0;
    }
};