#include<vector>
#include<cmath>
using namespace std;

typedef unsigned long long ull;

/*
 * ==== FINDINGS ====
 * 
 * Solve by including the no itself first!
 * 
 * Repetitivly no. of ways to express sum using only
 * Odd = dp(n-1) + dp(n-2) // fibonacci sequence    O(lgN)
 * Even = pow(2, n/2 - 1)                           O(lgN)
 * Natural = pow(2, n - 1) // partition problem     O(lgN)
 * 
 */




/*
 * PROBLEM => ways to express n as sum of odd integers (Repititive)
 * 
 * 0 {0} = -
 * 1 {1} = 1
 * 2 {1} = 1,1
 * 3 {2} = 1,1,1; 3
 * 4 {3} = 1,1,1,1; 1,3; 3,1                    
 * 5 {5} = 1,1,1,1,1; 1,1,3; 1,3,1; 3,1,1; 5; // 1[4]; 3[2]; 5[0]
 * 6 {8} = 1,1,1,1,1,1; 1,1,1,3; 1,1,3,1; 1,3,1,1; 1,5; 3,1,1,1; 3,3; 5,1 // 1[5]; 3[3]; 5[1]
 * 7 {13}= 1[6]; 3[4]; 5[2]; 7[0]                                          
 * dp[1] = 1
 * dp[2] = dp[1] = 1
 * dp[3] = dp[2] + dp[1] = 2
 * dp[4] = dp[3] + dp[1] = dp[3] + dp[2] = 3
 * dp[5] = dp[4] + dp[2] + dp[0] = dp[4] + dp[3] = 5
 * dp[6] = dp[5] + dp[3] + dp[1] = dp[5] + dp[4] = 8
 * dp[n] = dp[n-1] + dp[n-2]                                            // fibonacci!
 * 
 * Note: subtract 1 if don't want to use no itself in case of odd
 */

int waysOddRep(int N) {
    vector<int> dp;
    dp.resize(N+1);
    dp[0]=0; dp[1]=1;
    for(int i=2; i<=N; ++i) dp[i] = dp[i-1] + dp[i-2];
    return dp[N];
}

int waysOddRep1(int N) {
    vector<int> dp;
    dp.assign(N+1, 0);
    dp[0]=1; // base case 
    for(int i=1; i<=N; ++i) 
    for(int use=1; use<=i; use+=2) 
        dp[i] += dp[i-use];
    
    // printf("waysOddRep1: ");
    // for(int i=0; i<=N; ++i) printf("%d{%d} ", i,dp[i]); printf("\n");
    return dp[N];
}

/*
 * PROBLEM => ways to express n as sum of even integers (Repititive)
 * 
 * 0 {0} = -
 * 1 {0} = -
 * 2 {1} = 2
 * 3 {0} = -
 * 4 {2} = 2,2; 4                    
 * 6 {4} = 2,2,2; 2,4; 4,2; 6
 * 8 {8} = 2,2,2,2; 2,2,4; 2,4,2; 4,2,2; 4,4; 2,6; 6,2; 8
 * 
 * Note: subtract 1 if don't want to use no itself in case of odd
 */

int waysEvenRep(int N) {
    if(N<=0 || N%2) return 0;
    return (int) pow(2.0, N/2 - 1);
}

int waysEvenRep1(int N) {
    if(N<=0 || N%2) return 0;
    vector<int> dp;
    dp.assign(N+1, 0);
    dp[0] = 1; // base case
    dp[2] = 1;
    for(int i = 4; i <= N; i+=2)
    for(int use= 2; use<=i; use+=2)
        dp[i] += dp[i-use];
    return dp[N];
}

/*
 * PROBLEM =>  ways to express a no as sum of natural nos (Repititive)
 * 
 * repetitive = partition problem
 * 0 {0} = -
 * 1 {1} = 1
 * 2 {2} = 1,1; 2
 * 3 {4} = 1,1,1; 1,2; 2,1; 3
 * 4 {8}= 1,1,1,1; 1,1,2; 1,2,1; 2,1,1; 1,3; 3,1; 2,2; 4
 * for n = (n-1)C0 + (n-1)C1 + (n-1)C2 + (n-1)C3 +...+ (n-1)C(n-1) = 2^(n-1)
 * 
 * Note: subtract 1 if don't want to use no itself
 */

int waysNaturalRep(int N) {
    if(N <= 1) return 0;
    return (int)pow(2.0, N-1);
}

int waysNaturalRep1(int N) {
    if(N<=0) return 0;
    vector<int> dp;
    dp.assign(N+1, 0);
    dp[0]=1; // for base case 
    dp[1]=1;
    for(int i=2; i<=N; ++i)
    for(int use=1; use<=i; use++) 
        dp[i] += dp[i-use];
    // printf("waysNaturalRep1: ");
    // for(int i=0; i<=N; ++i) printf("%d{%d} ", i,dp[i]); printf("\n");
    return dp[N];
}

/*
 * https://oeis.org/A000009
 * 
 * Extension: non repetitive for odd
 * 0 {0} = -
 * 1 {1} = 1
 * 2 {1} = 1,1
 * 3 {2} = 1,1,1; 3
 * 4 {2} = 1,1,1,1; 1,3
 * 5 {3} = 1,1,1,1,1; 1,1,3; 3
 * 6 {4} = 1,1,1,1,1,1; 1,1,1,3; 3,3; 1,5 // 1,[5]; 3,3; 1,5
 * 7 {5} = 1,[6]; 7
 * 8 {6} = 1,[7]; 3,5; 1,7
 * 9 {8} = 1,[8]; 3,3,3; 9                                                            
 * 10 {10} = 1,[9]; 5,5; 3,7
 */
int waysOddNonRep(int N) {
    vector<int> dp;
    dp.assign(N+1, 0);
    dp[0] = 1; // base case
    for(int use = 1; use <= N; use += 2)
    for(int i = use; i <= N; ++i) 
        dp[i] += dp[i-use];

    // printf("waysOddNonRep: ");
    // for(int i=0; i<=N; ++i) printf("%d{%d} ", i,dp[i]); printf("\n");
    return dp[N];
}

 /* 
 * Wiki: Partion (Number Theory)
 * https://oeis.org/A000041
 * 
 * Extensionn: non repetitive for natural 
 * 0 {0} = - 
 * 1 {1} = 1
 * 2 {2} = 1,1; 2
 * 3 {3} = 1,1,1; 1,2; 3
 * 4 {5} = 1,1,1,1; 1,1,2; 2,2; 1,3; 4
 * 5 {7} = 1,1,1,1,1; 1,1,1,2; 1,2,2; 1,1,3; 2,3; 1,4; 5
 * 6 {11} = 1,1,1,1,1,1; 1,1,1,1,2; 1,1,2,2; 2,2,2; 1,1,1,3; 1,2,3; 3,3; 1,1,4; 2,4; 1,5; 6
 * 7 {15} = 1,1,1,1,1,1,1; 1,1,1,1,1,2; 1,1,1,2,2; 1,2,2,2; 1,1,1,1,3; 1,1,2,3; 2,2,3; 1,3,3; 1,1,1,4; 1,2,4; 3,4; 1,1,5; 2,5; 1,6; 7
 */ 
int waysNaturalNonRep(int N) {
    return -1;
}

int waysNaturalNonRep1(int N) {
    if(N <= 0) return 0;
    vector<int> dp;
    dp.assign(N+1, 0);
    dp[0] = 1; // base case
    for(int use = 1; use <= N; use++)
    for(int i = use; i <= N; ++i)
        dp[i] += dp[i-use];

    // printf("waysNaturalNonRep: ");
    // for(int i=0; i<=N; ++i) printf("%d{%d} ", i,dp[i]); printf("\n");
    return dp[N];
}

int main() {
    int N;

    N = 20;
    printf("waysOddRep(%d): %d\n", N, waysOddRep(N));
    printf("waysOddRep1(%d): %d\n\n", N, waysOddRep1(N));

    N = 20;
    printf("waysEvenRep(%d): %d\n", N, waysEvenRep(N));
    printf("waysEvenRep1(%d): %d\n\n", N, waysEvenRep1(N));

    N = 20;
    printf("waysNaturalRep(%d): %d\n", N, waysNaturalRep(N));
    printf("waysNaturalRep1(%d): %d\n\n", N, waysNaturalRep1(N));

    N = 20;
    printf("waysOddNonRep(%d): %d\n", N, waysOddNonRep(N));

    N = 20;
    // printf("waysNaturalNonRep(%d): %d\n", N, waysNaturalNonRep(N));
    printf("waysNaturalNonRep1(%d): %d\n\n", N, waysNaturalNonRep1(N));

    return 0;
}