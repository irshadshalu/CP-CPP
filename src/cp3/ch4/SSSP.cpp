/*
 * Single Source Shortes Path on weighted graph using Dijkstra's algo
 */
#include<vector>
#include<utility>
#include<queue>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;

// O((V + E) * logV) : log for V nodes in pq and each edge is checked
// works for negative edge weights too, albeit slower
// but will stuck in infinite loop for negative cycle in graph
void dijkstra(int s) {
    int N = AdjList.size();
    vi dist(N, INT_MAX); dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(dist[s], s));
    while(!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int u = front.second, d = front.first;
        if(dist[u] < d) continue;                           // old entry, can have duplicate entries

        for(int j = 0; j < AdjList[u].size(); ++j) {
            ii v = AdjList[u][j];
            if(dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
}
