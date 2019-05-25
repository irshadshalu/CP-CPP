#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

/*
 * ct has finite set of characters
 */
bool exhaust(string &s, unordered_map<char,int> ct) {
    bool flag = true;
    // O(A)
    for(char ch: s) {
        if(ct.find(ch) == ct.end()) {
            flag = false; break;
        } else {
            ct[ch]--;
        }
    }
    if(flag) 
    for(char ch: s) 
        if(ct[ch] != 0) 
        { flag = false; break; }
    return flag;
}

/*
 * Dictinoary # words = W
 * Avg size of dictionary word = A
 * Dictionary total characters = L
 * Pattern size = N
 * 
 * Complexity = O(N + W(A)) = O(N + L)
 * Query = O(DA)
 * 
 * If made trie of dictionary and traverse it
 * Query = O(N + reduced(L)) // as trie will have less characters than L
 */
void permuationInDictionary(const vector<string> &dictionary, const string &pat) {
    // better to use vector<char> of size 26 in case of alphabets only string
    unordered_map<char, int> ct;
    // O(P)
    for(char ch: pat) {
        if(ct.find(ch) == ct.end()) ct[ch] = 1;
        else ++ct[ch];
    }
 
    // O(D) * O(A) = O(DA)
    for(string s: dictionary) {
        // O(A)
        if(exhaust(s, ct)) 
            printf("%s: %s\n", pat.c_str(), s.c_str()); 
    }
}

int main() {
    vector<string> dictionary{"blue", "oyster", "cult", "lube"};
    string pat = "bule";

    permuationInDictionary(dictionary, pat);

    dictionary.push_back("banana");
    permuationInDictionary(dictionary, "aaabnn");


    return 0;
}

