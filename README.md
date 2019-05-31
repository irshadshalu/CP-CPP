## Custom Data Structures

#### [Segment Tree](https://github.com/zanymarconi/CP-CPP/blob/master/src/cp3/ch2/SegmentTree.cpp)
Can be used for RMQ (Range Minimum Query) in dynamic array, say, of N elements.
* Build Routine: O(N) as total nodes in tree 1+2+4+8+...+2<sup>log<sub>2</sub>N</sup> &asymp; 2N
* Query: O(log<sub>2</sub>N) as, if required, need to traverse either left or right subtree at each node
* Update: O(log<sub>2</sub>N)

#### [Sparse Table](https://github.com/zanymarconi/CP-CPP/blob/master/src/cp3/ch2/SparseTable.cpp)
Can be used for RMQ in static array i.e. frequent queries and rare updation
* Build Routine: O(N * log<sub>2</sub>N) as total different lengths for segment 1+2+4+..+log<sub>2</sub>N &asymp; 2*log<sub>2</sub>N for each starting index
* Query: O(1), for rmq(i, j) just need to compare two segments of length &lfloor;log<sub>2</sub>(j-i+1)&rfloor; one starting at i and another ending at j
* Update: O(N * log<sub>2</sub>N)

#### [Union Find DS](https://github.com/zanymarconi/CP-CPP/blob/master/src/cp3/ch2/UFDS.cpp)
To model collection of disjoint sets. Used in Kruskal.
* Build: O(M * &alpha;(n)) using path compression and union by rank heuristics for M operations where &alpha;(n) is inverse ackerman function grows very slowly, typically <5 for 1M inputs can treat as constant.
* Query: &asymp; O(1) which set item belong to

## Pop Algorithm Routines

#### [Painter's Partition Problem](https://github.com/zanymarconi/CP-CPP/blob/master/src/org/google/glassdoor/PainterPartition.cpp)
Divide an array of N elements in K (<= N) contiguous subarrays such that maximum of the sum of those subarrays is minimum.

* DP Approach O(K * N<sup>2</sup>)
    
    Let dp[i][j] minimum subarray sum possible for i partitions and upto j elements, and sum[j] be cumulative sum for first j elements, then
        
        dp[i][0] = arr[0]
        dp[1][j] = sum[j];
        dp[i][j] = min{ max(dp[i-1][l], sum[j] - sum[l]) for 0 <= l < j } 

* Binary Search O(N * log<sub>2</sub>(&sum;<sub>0<=i<N</sub> arr[i]))

    The required sum can be binary searched,
        
        low = min{ arr[i] }
        high = sum[N];
        find lowest mid with excatly K partitions

#### [Cutting Sticks](https://github.com/zanymarconi/CP-CPP/blob/master/src/org/google/glassdoor/CutRodMarks.cpp)
Given stick of length L and N cuts to be made to the stick in range (0 .. L). The cost of cut is determined by lenght of stick to cut. Find minimum cost for optimal cutting sequence.

* DP Approach O(N<sup>3</sup>)

    Let dp[i][j] be the minimum cost to cut sticks between (i, j) and cuts be stored in arr with first element 0 and last L for markers, then
        
        dp[i-1][i] = 0
        dp[i][j] = min { dp[i][l] + dp[l][j] + arr[j] - arr[i] for i < l < j }

* Knuth Yao Optimization O(N<sup>2</sup>)

    Let the optimal (first) mark to begin cut for dp[i][j] be stored in pos[i][j], then
        
        dp[i][j] = min { dp[i][l] + dp[l][j] + arr[j] - arr[i] for pos[i][j-1] < l < pos[i+1][j]}
        since dp[i][j] satisfy quadrangle inequality

#### [KMP String Matching](https://github.com/zanymarconi/CP-CPP/blob/master/src/org/google/glassdoor/KMPSearch.cpp)
Given a pattern of length M to search in text of length N.

* Preprocessing O(M)

    Let lps[i] be the length of longest prefix suffix for pattern ending at i-1 index, then

        int i = 0, j = -1; lps[0] = -1;
        while(i < M) {
            while(j >= 0 && pat[i] != pat[j]) j = lps[j];
            i++, j++;
            lps[i] = j;
        } 

* Text Search O(N)

    Basically, lps[i] has the index where to reset in case of mismatch, then

        int i = 0, j = -1;
        while(i < N) {
            while(j >= 0 && text[i] != pat[j]) j = lps[j];
            i++, j++;
            if(j == M) {
                // pattern found at i-j index
                j = lps[j];
            }
        }

#### [Max 2D Range Sum](https://github.com/zanymarconi/CP-CPP/blob/master/src/leetcode/max2DRangeSum.cpp)
Given a M * N matrix positive and negative integers, find the maximum possible sum of elements of a submatrix.

* Extend Kadane O(M * N<sup>2</sup>)

    Create a cumulative row sum matrix sum[i][j] from input matrix mat[i][j], where sum[i][j] = sum[i][j-1] + mat[i][j] and sum[i][0] = mat[i][0], then,

        int ans = INT_MIN;
        for(int c1 = 0; c1 < N; ++c1)
        for(int c2 = c1; c2 < N; ++c2) {
            int current = 0;
            for(int r = 0; r < M; ++r) {
                current += (c1 == 0)? sum[r][c2]: sum[r][c2] - sum[r][c1-1];
                ans = max(ans, current);
                if(current < 0) current = 0;
            }
        }

#### [Paper Cut](https://github.com/zanymarconi/CP-CPP/blob/master/src/org/google/gfg/PaperCut.cpp)
Cut a M * N paper into minimum number of squares, for example 5 * 6 paper can be cut optimally in 5 squares of size 2 * 2 (3) and 3 * 3 (2).

* Memoization Approach O(M * N)

    Recursively calculate minimum squares for i * j by following. Note that number of squares is always less than M * N, worst case if M == 1 || N == 1, so the recursive function calls or time complexity is bounded by same.
        
        if (i == j) return dp[i][i] = 1
        try vertical_cut (i * x) and (i * (j-x))
        try horizontal_cut (x * j) and ((i-x) * j)
        return dp[i][j] = min (vertical_cut, horizontal_cut) 

#### [Longest Increasing Subsequence](https://github.com/zanymarconi/CP-CPP/blob/master/src/leetcode/LIS.cpp)
Given an array of integers of lenght N find the length of longest increasing subsequence.

* DP + Greedy O(N * log<sub>2</sub>K)
    Here K is output sensitive length of LIS of input array. The idea is to maintain a vector l for l[i] reperesents smallest last element in length-i LIS. For each element in array binary search is performed in vector l.