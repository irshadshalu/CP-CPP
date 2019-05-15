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
vector<vii> floors;

void printPath(int n, int k) {
    printf("%d eggs; %d floors\n", n, k);
    if(n == -1) return;
    else printPath(floors[n][k].first, floors[n][k].second);
}

// n eggs, k floors
int eggDrop(int n, int k) {
    trials.assign(n+1, vi(k+1, -1));

    floors.assign(n+1, vii(k+1, ii(-1, -1)));

    // 0 and 1 floor left
    for(int i=1; i<=n; ++i) {
        trials[i][0]=0, trials[i][1]=1;
        // -1 eggs marks end
        floors[i][1]= ii(-1, 1); 
    }

    // only 1 egg left
    for(int j=0; j<=k; ++j) {
        trials[1][j]=j;
        
        // start with 1 egg and first floor
        floors[1][j]=ii(1,1); if(j>0)
        floors[1][j-1]=ii(-1, j);
        // cover worst case
        for(int x=1; x<j-1; ++x) floors[1][x] = ii(1, x+1);
    }

    for(int i=2; i<=n; ++i) 
    for(int j=2; j<=k; ++j) {
        int t = INT_MAX;
        ii next = ii(-1, -1);
        for(int x=1; x<=j; ++x) {
            int r = trials[i-1][x-1];
            ii uv = ii(i-1, x-1);
            if(trials[i][j-x]>r) {
                r = trials[i][j-1];
                uv = ii(i, j-1);
            }
            if(r < t) {
                t = r;
                next = uv;
            }
            // t = min(t, max(trials[i-1][x-1], trials[i][j-x]));
        }
        trials[i][j] = 1 + t;
        floors[i][j] = next;
    }

    return trials[n][k];
}

int main() {
    freopen("EggDrop.out", "w", stdout);

    printf("Mininum trials: %d\n", eggDrop(2, 100));
    printPath(2, 100);
    return 0;
}