#include<vector>
#include<string>
#include<utility>
using namespace std;

typedef pair<int, int> ii;

class PalindromicTree {
    private:
        struct node {
            int end;            // store end position in string
            int len;            // length of this pal node
            int next[26];       // a-z weighted edge, can be generalized using unordered_map with indices
            int suff;           // unweighted suffix i.e. longest proper palindromic suffix for this pal
            node(int l, int s, int e = -1) : len(l), suff(s), end(e) {}
        };

        int N, current, total;
        vector<node*> tree;
        string str;

        void addletter(int pos) {
            int ptr = current;                        
            int ch = str[pos] - 'a';

            while(ptr && str[pos-(tree[ptr]->len)-1] != str[pos])
                ptr = tree[ptr]->suff;                                  // iterate through suff till "str[pos] X str[pos]"

            if(tree[ptr]->next[ch] != 0) {
                current = tree[ptr]->next[ch]; return;
            }

            current = ++total;
            tree[current] = new node(tree[ptr]->len + 2, -1, pos);      // create new palindromic node with (len)
            tree[ptr]->next[ch] = current;                              // make new node child of X using str[pos]

            if(tree[current]->len == 1) {
                tree[current]->suff = 1; return;                        // single letter palindrome
            }

            ptr = tree[ptr]->suff;
            while(ptr && str[pos-(tree[ptr]->len)-1] != str[pos])
                ptr = tree[ptr]->suff;
            
            tree[current]->suff = tree[ptr]->next[ch];  
        }

    public:
        PalindromicTree(const string &inp) {
            str = "$" + inp;            // marker for intuitive implementation
            N = str.size();
            tree.resize(N+5);           // max inp.size() palindromes + 2 roots
            tree[0] = new node(-1, 0);  // root0: create imaginary string with (len, suf)
            tree[1] = new node(0, 0);   // root1: empty string w/ suf link to imaginary
            total = current = 1;        // current traverses palindromic tree
            for(int i = 1; i < N; ++i)
                addletter(i);
        }

        ~PalindromicTree() {
            for_each(tree.begin(), tree.end(), [](node *t) {
                free(t);
            });
        }

        vector<ii> returnPals() {       // returns list of staritng index and length in original input
            vector<ii> sl;
            for(int i = 2; i <= total; ++i)
                sl.push_back(ii(tree[i]->end - tree[i]->len, tree[i]->len));
            return sl;
        }
};

void testUtil(string inp) {
    PalindromicTree *pt;
    pt = new PalindromicTree(inp);      // O(inp.size())
    vector<ii> pals = pt->returnPals();
    printf("input = %s \n total unique palindromes = %lu \n palindromes = ", inp.c_str(), pals.size()); 
    string longest = "";
    for(ii sl: pals) {                  // O(inp.size())
        string s = inp.substr(sl.first, sl.second);
        printf("%s ", s.c_str());
        if(s.size() > longest.size()) longest = s;
    }
    printf("\n longest palindrome = %s\n\n",  longest.c_str());
    free(pt);
}

int main() {

    testUtil("abccba");
    testUtil("abaxyay");
    testUtil("aaaaa");
    testUtil("xyxa");

    return 0;
}

/*
Console Output:

input = abccba 
 total unique palindromes = 6 
 palindromes = a b c cc bccb abccba 
 longest palindrome = abccba

input = abaxyay 
 total unique palindromes = 6 
 palindromes = a b aba x y yay 
 longest palindrome = aba

input = aaaaa 
 total unique palindromes = 5 
 palindromes = a aa aaa aaaa aaaaa 
 longest palindrome = aaaaa

input = xyxa 
 total unique palindromes = 4 
 palindromes = x y xyx a 
 longest palindrome = xyx

*/