/*
 * Max 1D Range Sum (Kadane Algo) ==> O(N)
 * Iterate by adding values to sum and if sum reaches negative reset sum to 0:
 */

/*
 * Max 2D Range Sum ==> O(N^3)
 * M x N matrix find cumulative sum rowwise
 * Iterate for 2 loops for columns [c1 to c2]
 * Run kadane rowwise
 */ 

/*
 * Longest Increasing Subsequence ==> O(Nlogk)
 * k = output sensitive longest subseq
 * Greedy srategy:
 * > L(i) represent smallest ending value of all length-i LIS's
 * > For each element arr[i], update this value to upper_bound(L)
 */ 

/*
 * Knapsack ==> sub O(NS)
 * each exclude or include
 * proceed from recur(id,remW) to either exclude recur(id+1, remW) or include recur(id+1, remW - W[id]) 
 * NOTE: here top down approach is faster as not all distinct states N*S (N items, S max weight) is visited
 */

/*
 * Coin Change ==> O(NV)
 * lets N coins, coin[i] is value of coin i and change(val) is minimum #coins to make val
 * change(val) = 1 + min(change(val - coin[i])) for i=[0..N-1] 
 * 
 * Extension: no. of ways
 * include-exclude top down
 */

/*
 * TSP ==> O(N^2 * 2^N)
 * start and end at same say 0, brute for is (N-1)! hence N at most 12 as 11! ~ 40M (10! ~ 3.6M)
 * use bitmask
 * tsp(pos, 2^N-1) = dist[pos][0]  // all visited
 * tsp(pos, vis) = min(dist[pos][nxt] + tsp(nxt, vis | (1 << nxt))) for nxt in [0..N-1], nxt != pos and vis & (1<<nxt) is 0
 * works upto N ~ 16 as 16^2*2^16 ~ 17M
 * brute force = O(N-1)!
 * dp = O(N^2 * 2^N) where one N for starting from pos, second N for loop for nxt, 2^N for vis states
 */ 

/*
 * Ways to Add ==> O(N^2 * K)
 * Given N integer, how many ways (repetition allowed) to add K non negative integers to get N
 * Mathematically = (N) C (K-1) i.e. choose k-1 partition lines in N 1's
 * or dp,
 * ways(n, 1) = 1 // to make n and 1 number left
 * ways(n, k) = Summation: ways(n - i, k - 1)  for i in [0..n]
 */ 

/*
 * Cutting Sticks ==> O(N^3) --> O(N^2)
 * Given array A where cuts need to be made (values in 1..N), for dp use index in A rather than actual length, call cut(0, N+1)
 * cut(i-1, i) = 0  for i [1..N+1] // no further divison if selected 2 points in A
 * cut(left, right) = min(cut(left, i) + cut(i, right) + (A[right]-A[left])) for i in [left+1 ... right-1]
 * above top-dow is O(N^3) with N^2 states
 * 
 * Knuth-Yao DP optimization can be applied in quadrangle inequality
 * Quadrangle inequality: dp[i][j-1] <= dp[i][j] <= dp[i][j+1]
 * Optimization: instead of i in [left+1 .. right-1] use [k[left][right-1] .. k[left+1][right]]
 *               where k(left, right) is i for which is minimum
 */ 