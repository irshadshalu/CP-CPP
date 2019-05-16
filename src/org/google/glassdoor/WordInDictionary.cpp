#include<string>
#include<vector>
using namespace std;


const int MAX = 26;

struct Trie {
    vector<Trie*> child;
};

Trie* createNode() {
    Trie* node = new Trie();
    node->child.assign(MAX, NULL);
    return node;
}

Trie* insertRec(Trie* node, char ch) {
    Trie* temp = createNode();
    node->child[ch - 'a'] = temp;
    return temp;
}

void insertTrie(Trie* root, string s) {
    Trie* temp = root;
    for(char ch: s) {
        temp = insertRec(temp, ch);
    }
}

Trie* buildTrie(const vector<string> &dictionary) {
    Trie *root = createNode();
    for(string s: dictionary) {
        insertTrie(root, s);
    }
    return root;
}

bool isFound(Trie* root, const string &word) {
    bool flag = true;
    Trie* temp = root;
    for(char ch: word) {
        if(temp == NULL) { flag = false; break; }
        temp = temp->child[ch - 'a'];
    }
    return flag;
}

/*
 * Dictinoary # words = D
 * Dictionary word avg size = A
 * Pattern size = P
 * 
 * Make trie to optimize query
 * 
 * Search: O(P)
 */
bool isPresent(const vector<string> &dictionary, const string &word) {
    Trie* root = buildTrie(dictionary);
    return isFound(root, word);
}

int main() {
    vector<string> dictionary{"apple", "airplane", "blue", "black"};
    string word = "black";
    if(isPresent(dictionary, word)) printf("%s is present!\n", word.c_str());
    word = "airplane";
    if(isPresent(dictionary, word)) printf("%s is present!\n", word.c_str()); else printf("%s is not present!\n", word.c_str()); 
    word = "banana";
    if(isPresent(dictionary, word)) printf("%s is present!\n", word.c_str()); else printf("%s is not present!\n", word.c_str());
}