/*
 *  Floyd Warshall Algorithm for All Pair Shortest Path
 */ 
#include<vector>
using namespace std;

typedef vector<int> vi;

vector<vi> AdjMat;                  // AdjMat[i][j] contains the weight of edge (i, j), or INF (1B) if there is no such edge

// O(V^3) can be used for V <= 400
void floydwarshall() {
    int V = AdjMat.size();
    for (int k = 0; k < V; k++)     // remember that loop order is k->i->j
    for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
        AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
}

/*
 * Applications:
 * 1. Transitive closure (connected or not)
 *      AdjMat[i][j] |= (AdjMat[i][k] & AdjMat[k][j]);
 * 2. Minmax
 *      AdjMat[i][j] = min(AdjMat[i][j], max(AdjMat[i][k], AdjMat[k][j]));
 * 3. Finding cheapest(or negative) cyle
 *      set AdjMat[i][i] = INF (1B)
 *      run bellman ford
 *      if AdjMat[i][i] is no longer INF, we have a cycle; 
 *      cheapest = min(AdjMat[i][i])
 *      negative iff AdjMat[i][i] < 0
 * 4. Diameter of Graph
 *      largest AdjMat[i][j] for each i,j O(V^2)
 * 5. SCC's on Directed Graph
 *      Strongly connected component
 *      if AdjMat[i][j] && AdjMat[j][i] is true, then vertex i and j belong to the same SCC.
 */ 