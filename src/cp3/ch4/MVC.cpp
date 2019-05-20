/*
 * Minimum vertex cover on a tree i.e. least number of nodes such that each edge is connect to that collection
 */
#include<vector>
using namespace std;

struct Node {
    int val, idx;
    vector<Node*> child;
    bool isLeaf() { return child.size() == 0? true: false; }
};

Node *root;

vector<vector<int>> memo;

// ans is min(MVC(root, 0), MVC(root, 1))
int MVC(Node *node, int flag) {                                 // Minimum Vertex Cover
    int v = node -> idx;
    int ans = 0;
    if (memo[v][flag] != -1) return memo[v][flag];              // top down DP
    else if (node->isLeaf())                                    // leaf[v] is true if v is a leaf, false otherwise
        ans = flag;
    else if (flag == 0) {                                       // if v is not taken, we must take its children
        ans = 0;                                                // Note: ‘Children’ is an Adjacency List that contains the
        for (int j = 0; j < (int)node->child.size(); j++)       // directed version of the tree (parent points to its children; but the
            ans += MVC(node->child[j], 1);                      // children does not point to parents)
    }
    else if (flag == 1) {                                       // if v is taken, take the minimum between
        ans = 1;                                                // taking or not taking its children
        for (int j = 0; j < (int)node->child.size(); j++)
            ans += min(MVC(node->child[j], 1), MVC(node->child[j], 0));
    }
    return memo[v][flag] = ans;
}