#include<vector>
#include<utility>
#include<queue>
using namespace std;

typedef pair<int, int> ii;          // node, weight
typedef vector<ii> vii;             // list of weighted edges for each node
typedef vector<vii> vvii;

vvii AdjList;

vector<int> ts;                     // topological sort

// O(V + E)
// BFS can be used for distance calculation in unweighted (or same weight) graph
void bfs(int s) {
    vector<int> dist;
    int N = AdjList.size();
    dist.assign(N, -1);             // -1 not vis
    dist[s] = 0;

    queue<int> qu; qu.push(s);
    while(!qu.empty()) {
        int u = qu.front(); qu.pop();
        ts.push_back(u);            // kahn's ts
        for(int j = 0; j < AdjList[u].size(); ++j) {
            ii v = AdjList[u][j];
            if(dist[v.first] == -1) {
                dist[v.first] = dist[u] + 1;
                qu.push(v.first);
            }
        }
    }
}