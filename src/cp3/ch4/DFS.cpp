#include<vector>
#include<utility>
using namespace std;

typedef pair<int, int> ii;          // node, weight
typedef vector<ii> vii;             // list of weighted edges for each node
typedef vector<vii> vvii;

vvii AdjList;

vector<bool> vis;

vector<int> ts;

void dfs(int u) {
    vis[u] = true;
    for(int j = 0; j < AdjList[u].size(); ++j) {
        ii v = AdjList[u][j];
        if(!vis[v.first]) dfs(v.first);
    }
    ts.push_back(u);                // only for topological sort stored in reverse order used in DAG: Tarjan
}