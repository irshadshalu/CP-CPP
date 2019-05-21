#include<string>
#include<vector>
#include<iostream>
using namespace std;

typedef vector<bool> vb;

bool test(string a, string b, string c) {
    if(a.size() + b.size() != c.size()) return false;
    int n = a.size(), m = b.size();
    vector<vb> dp; dp.assign(n+1, vb(m+1, false));

    a = "$" + a; b = "$" + b; c = "$" + c;
    for(int i = 0; i <= n; ++i)
    for(int j = 0; j <= m; ++j) {
        if(i == 0 && j == 0) dp[0][0] = true;
        else if(i == 0) dp[0][j] = dp[0][j-1] && (b[j] == c[j]);
        else if(j == 0) dp[i][0] = dp[i-1][0] && (a[i] == c[i]);
        else dp[i][j] = (dp[i-1][j] && (a[i] == c[i+j])) 
                            || (dp[i][j-1] && (b[j] == c[i+j]));
    }

    // for(int i = 0; i <= n; ++i) {
    //     for(int j = 0; j <= m; ++j) printf("%d ", dp[i][j]? 1: 0); printf("\n");
    // }

    return dp[n][m];
}

int main() {
    cout << test("AC", "BD", "ABCD") << endl;
    cout << test("XXY", "XXZ", "XXZXXXY") << endl; 
    cout << test("XY" ,"WZ" ,"WZXY") << endl; 
    cout << test ("XY", "X", "XXY") << endl; 
    cout << test ("YX", "X", "XXY") << endl; 
    cout << test ("XXY", "XXZ", "XXXXZY") << endl;              // not a subsequence problem! 
    return 0;
}