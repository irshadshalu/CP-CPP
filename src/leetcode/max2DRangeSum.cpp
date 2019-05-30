#include<vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vvi mat;

void solve() {
  int M = mat.size(), N = mat[0].size();
  vvi sum(M, vi(N));
  for(int i = 0; i < M; ++i)
  for(int j = 0; j < N; ++j)
    sum[i][j] = (j == 0)? mat[i][0]: sum[i][j-1] + mat[i][j];

  
  int ans = INT_MIN;
  iii pos = iii(-1, ii(-1, -1));
  for(int c1 = 0; c1 < N; ++c1)
  for(int c2 = c1; c2 < N; ++c2) {
      int current = 0;
      for(int r = 0; r < M; ++r) {
          current += (c1 == 0)? sum[r][c2]: sum[r][c2] - sum[r][c1-1];
          if(current > ans) ans = current, pos = iii(r, ii(c1, c2));
          if(current < 0) current = 0;
      }
  }
  printf("Maximum sum found = %d at row %d b/w cols %d and %d\n", ans, pos.first, pos.second.first, pos.second.second);
}

int main() {
    mat = {{1, 2, -3, 4},
           {7, -5, 6, -8},
           {-4, 3, -9, -10},
           {8, 5, -6, 1},
           {-3, -12, 4, -1}};
    solve();
}
