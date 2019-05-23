// https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/
#include<vector>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

typedef vector<int> vi;

vector<string> dict;
vector<vi> AdjList;
int ALP;

unordered_map<char, int> indices;
unordered_map<int, char> revindi;

stack<int> topo;
vector<bool> vis;

void topological_sort(int u) {
    vis[u] = true;
    for(int j = 0; j < AdjList[u].size(); ++j)
    if(!vis[AdjList[u][j]]) topological_sort(AdjList[u][j]);

    topo.push(u);
}

void printAdj() {
    printf("Adjacency List:\n");
    for(int i = 0; i < ALP; ++i) {
        printf("%c -> ", revindi[i]);
        for(int j = 0; j < AdjList[i].size(); ++j)
        printf("%c ", revindi[ AdjList[i][j] ]); printf("\n");
    }
}

// print one possible of characters' order
void solve() {
    indices.clear();
    ALP = 0; int N = dict.size();
    for(string s: dict)
    for(char ch: s) 
        if(indices.find(ch) == indices.end()) indices[ch] = ALP, revindi[ALP] = ch, ++ALP;
    AdjList.assign(ALP, vi{});

    for(int i = 0; i < N; ++i)
    for(int j = i+1; j < N; ++j) {
        string first = dict[i], second = dict[j];
        int ptr = 0;
        bool flag = true;
        // can only check with first umatched character
        while(ptr < first.size() && ptr < second.size() && flag) {
            if(first[ptr] != second[ptr]) AdjList[indices[first[ptr]]].push_back(indices[second[ptr]]), flag = false;
            ++ptr;
        }
    }

    // printAdj();

    topo = stack<int>();
    vis.assign(ALP, false);

    for(int i = 0; i < ALP; ++i)
    if(!vis[i]) topological_sort(i);

    printf("one possible order = ");
    while(!topo.empty()) { printf("%c ", revindi[topo.top()]); topo.pop(); } printf("\n");
}

int main() {
    dict = {"baa", "abcd", "abca", "cab", "cad"};
    solve();

    // might not be DAG
    dict = {"the", "quick", "brown", "fox", "jumps", "over", "a", "little", "lazy", "dog"};
    solve();
    return 0;
}