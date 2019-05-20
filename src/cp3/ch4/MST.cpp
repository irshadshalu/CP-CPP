/*
 * MST Applications:
 * 1. Minimax: find minimum of maximum edge weight for all paths from i to j
 */ 

#include<vector>
#include<utility>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<vector<pair<int, int>>> AdjList;                         // adjacency list input 

// UFSD complexity = O(N * inverse-ackerman-function(N))
class UFDS {
    private: int N; vi parent, rank;
    public:
        UFDS(int sz) {
            N = sz; parent.resize(N);
            rank.assign(N, 0);
            for(int i = 0; i < N; ++i) parent[i] = i;
        } 
        int findSet(int i) { return parent[i] == i ? i: (parent[i] = findSet(parent[i])); }
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        bool unionSet(int i, int j) {
            if(!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) parent[y] = x;
            else {
                parent[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }}
};

// O(ElogE + E)
// Kruskal's greedy approach using UFDS
int mst() {
    vector<iii> EdgeList;
    int N = AdjList.size();
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < AdjList[i].size(); ++j) {
            ii v = AdjList[i][j];
            if(v.first < i) continue;                           // add edge only once 
            EdgeList.push_back(iii(v.second, ii(i, v.first))); 
        }
    }

    sort(EdgeList.begin(), EdgeList.end());                     // sort in increasing order of weight;
    UFDS uf(N);

    int mst_cost = 0, edges = 0;
    for(iii e: EdgeList) {
        int u = e.second.first, v = e.second.first, w = e.first;
        if(!uf.isSameSet(u, v)) {
            uf.unionSet(u, v); mst_cost += w; edges++;
        }
        if(edges == N - 1) break;                               // V - 1 edges will be selected in mst
    }
    return mst_cost;
}

// Prims priority_queue (min heap on weights with greater<int> function or store negaive weight) with vis flag, pq mainatains 