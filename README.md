## Popular Algorithm Routines

#### Painter's Partition Problem
Divide an array of N elements in K (<= N) contiguous subarrays such that maximum of the sum of those subarrays is minimum.

* DP Approach O(K * N<sup>2</sup>)
    
    Let dp[i][j] minimum subarray sum possible for i partitions and upto j elements, and sum[j] be cumulative sum for first j elements, then
        
        dp[i][0] = arr[0]
        dp[1][j] = sum[j];
        dp[i][j] = min{ max(dp[i-1][l], sum[j] - sum[l]) for 0 <= l < j } 

* Binary Search O(N * log<sub>2</sub>(sum[N]))

    The required sum can be binary searched,
        
        low = min{ arr[i] }
        high = sum[N];
        find lowest mid with excatly K partitions

#### Cutting Sticks
Given stick of length L and N cuts to be made to the stick in range (0 .. L). The cost of cut is determined by lenght of stick to cut. Find minimum cost for optimal cutting sequence.

* DP Approach O(N<sup>3</sup>)

    Let dp[i][j] be the minimum cost to cut sticks between (i, j) and cuts be stored in arr with first element 0 and last L for markers, then
        
        dp[i-1][i] = 0
        dp[i][j] = min { dp[i][l] + dp[l][j] + arr[j] - arr[i] for i < l < j }

* Knuth Yao Optimization O(N<sup>2</sup>)

    Let the optimal (first) mark to begin cut for dp[i][j] be stored in pos[i][j], then
        
        dp[i][j] = min { dp[i][l] + dp[l][j] + arr[j] - arr[i] for pos[i][j-1] < l < pos[i+1][j]}
        since dp[i][j] satisfy quadrangle inequality


