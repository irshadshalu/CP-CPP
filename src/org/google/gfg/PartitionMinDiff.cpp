#include<string>
#include<vector>
#include<numeric>
using namespace std;

// divide in 2 such that diff b/w two is minimum
void optimallyDivide(vector<int> &arr) {
    vector<vector<bool>> dp;
    int sum = 0, N = arr.size();
    for(int a: arr) {sum += a; printf("%d ", a); } printf("\n");
    dp.resize(N+1, vector<bool>(sum));
    for(int i = 0; i <= N; ++i) dp[i][0] = true;
    for(int i = 1; i <= N; ++i)
    for(int j = 1; j <= sum; ++j) {
        dp[i][j] = dp[i-1][j];
        if(arr[i-1] <= j)
            dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
    }
    printf("Possible sums = ");
    for(int j = 1; j <= sum; ++j) if(dp[N][j]) printf("%d ", j); printf("\n");
    int x = sum%2 ? (sum+1)/2 : sum/2;
    do {
        if(dp[N][x]) {
            printf("Min diff = %d\n", 2*x - sum);
            break;
        }
    } while(!dp[N][x++]);
}

int main() {
    vector<int> arr = {4, 9, 5, 6, 15};
    optimallyDivide(arr);
    return 0;
}