/*
 * Bellman Ford algorithm to find SSSP
 */
#include<vector>
#include<utility>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;

vi dist;

// O(VE)
void bellmanford(int s) {
    int V = AdjList.size();
    dist.assign(V, INT_MAX); dist[s] = 0;
    bool modified = true;                               // post optimization

    for (int i = 0; i < V - 1 && modified; i++) {       // relax all E edges V-1 times
        modified = false;
        for (int u = 0; u < V; u++)                     // these two loops = O(E)
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if(dist[u] + v.second < dist[v.first]) 
                dist[v.first] = dist[u] + v.second, modified = true; 
        } 
    }          
}

bool hasNegativeCycle() {
    bellmanford(0);

    int V = AdjList.size();
    bool hasNegativeCycle = false;
    for (int u = 0; u < V; u++)                         // one more pass to check
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dist[v.first] > dist[u] + v.second)         // if this is still possible
        hasNegativeCycle = true;                        // then negative cycle exists!
    }
    return hasNegativeCycle;
}