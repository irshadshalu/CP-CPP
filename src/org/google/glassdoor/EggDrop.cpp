#include<vector>
#include<utility>
using namespace std;

// 1 egg -> start from lowest to highest
// n eggs k floors => min trials in worst case

/*
 * trials(n, k) = 1 + min{
 *                          max{ trials(n-1, x-1), trials(n, k-x) }
 *                          where x in 1..k
 *                      }
 * max inside because we don't know if a floor breaks the egg and taking worse case for #trials from 2 scenarios
 * min to find which floor to start experiment to have min trials
*/

// Extension 1: print floors sequence for worst case? floors used for minimum trial solution

// Extension 2: two eggs https://www.geeksforgeeks.org/egg-dropping-puzzle-with-2-eggs-and-k-floors/

// Extension 3: https://www.geeksforgeeks.org/puzzle-set-35-2-eggs-and-100-floors/

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

// min trials for i eggs and j floors
vector<vi> trials;

// where to go next for min trials, just that!
vector<vii> path;

// n eggs, k floors
int eggDrop(int n, int k) {
    trials.assign(n+1, vi(k+1, -1));

    // 0 and 1 floor left
    for(int i=1; i<=n; ++i) {
        trials[i][0]=0, trials[i][1]=1;
    }

    // only 1 egg left
    for(int j=0; j<=k; ++j) {
        trials[1][j]=j;
    }

    for(int i=2; i<=n; ++i) 
    for(int j=2; j<=k; ++j) {
        int t = INT_MAX;
        for(int x=1; x<=j; ++x) {
            t = min(t, max(trials[i-1][x-1], trials[i][j-x]));
        }
        trials[i][j] = 1 + t;
    }

    return trials[n][k];
}

int main() {
    freopen("EggDrop.out", "w", stdout);

    printf("Mininum trials: %d\n", eggDrop(2, 100));
    return 0;
}