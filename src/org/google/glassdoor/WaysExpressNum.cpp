#include<vector>
using namespace std;

typedef unsigned long long ull;

/*
 * PROBLEM :=  ways to express a no as sum of natural nos
 * 
 * Note :=
 * for distinct = outer loop is of using one by one each valid no
 * for reptitive permutation = single dp loop
 * 
 * ways to express n as sum of odd integers :=
 * n = 1 + (n-1 as odd sum)
 * 
 * repetitive
 * 0 {1}= 0
 * 1 {1}= 1
 * 2 {1}= 1 + 1
 * 3 {2}= 1 + 1 + 1; 3 + 0
 * 4 {3}= 1 + (1 + 1 + 1); 1 + 3; 3 + 1                    
 * 5 {5}= 1,1,1,1,1; 1,1,3; 1,3,1; 3,1,1, 5 + 0; // 1[4]; 3[2]; 5[0]
 * 6 {8}= 1,1,1,1,1,1; 1,1,1,3; 1,1,3,1; 1,3,1,1; 1,5; 3,1,1,1; 3,3; 5,1 // 1[5]; 3[3]; 5[1]
 * 7 {13}= 1[6]; 3[4]; 5[2]; 7[0]                                          
 * dp[0] = 1
 * dp[1] = dp[0] = 1
 * dp[2] = dp[1] = 1
 * dp[3] = dp[2] + dp[0] = dp[2] + dp[1] = 2
 * dp[4] = dp[3] + dp[1] = dp[3] + dp[2] = 3
 * dp[5] = dp[4] + dp[2] + dp[0] = dp[4] + dp[3] = 5
 * dp[6] = dp[5] + dp[3] + dp[1] = dp[5] + dp[4] = 9
 * dp[n] = dp[n-1] + dp[n-2]                                            // fibonacci!
 * subtract 1 if don't want to use no itself in case of odd
 * 
 * extension: non repetitive
 * 1 {1} = 1
 * 2 {1} = 1,1
 * 3 {1} = 1,1,1
 * 4 {2} = 1,1,1,1; 1,3
 * 5 {2} = 1,1,1,1,1; 1,1,3
 * 6 {4} = 1,1,1,1,1,1; 1,1,1,3; 3,3; 1,5 // 1,[5]; 3,3; 1,5
 * 7 {4} = 1,[6]; 
 * 8 {6} = 1,[7]; 3,5; 1,7
 * 9 {6} = 1,[8]; 3,3,3                                                             
 * 10 {8} = 1,[9]; 5,5; 1,9
 * 
 * ways to express n as sum of even integers :=
 * 
 * extension: non repetitive
 * use evens one by one
 * 1 {0} = NaN
 * 2 {0} = --
 * 3 {0} = NaN
 * 4 {1} = 2,2
 * 10 {5} = 2,2,2,2,2; 2,2,2,4; 2,4,4; 2,2,6; 4,6; // all 2s, 4s can be max 2, 6 can be max 1
 * 
 * 
 * repetivie
 */

int waysOddNonRep(int N) {
    vector<int> dp;
    dp.assign(N+1, 0);
    for(int use = 1; use < N; use+=2)
    for(int i = 1; i <= N; ++i) {
        if(use == 1) dp[i]++;                          // all 1's
        else if(i > use) dp[i] += i/use;               // other odds can be used in i # of times = i/use 
    }
    return dp[N];
}

int waysOddRep(int N) {
    vector<int> dp;
    dp.resize(N+1);
    dp[0]=0; dp[1]=1;
    for(int i=2; i<=N; ++i) dp[i] = dp[i-1] + dp[i-2];
    return dp[N];
}

int main() {
    printf("waysOddNonRep(%d): %d\n", 10, waysOddNonRep(10));
    printf("waysOddNonRep(%d): %d\n", 6, waysOddNonRep(6));
    printf("waysOddRep(%d): %d\n", 7, waysOddRep(7));
}