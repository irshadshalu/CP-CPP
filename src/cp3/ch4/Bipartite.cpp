#include<vector>
#include<utility>
#include<queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvii AdjList;

// is bi partite
bool bfs2(int s) {
    vector<int> color;
    int N = AdjList.size();
    color.assign(N, -1);        // assign either 0 or 1
    queue<int> qu;
    qu.push(s); color[s] = 0;
    bool flag = true;
    while(!qu.empty() && flag) {
        int u = qu.front(); qu.pop();
        for(int j = 0; j < AdjList[u].size(); ++j) {
            ii v = AdjList[u][j];
            if(color[v.first] == -1) {
                color[v.first] = 1 - color[u];
                qu.push(v.first);
            }
            else if(color[v.first] == color[u]) {
                flag = false; break;
            }
        }
    }
    return flag;
}