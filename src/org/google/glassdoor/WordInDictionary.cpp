#include<string>
#include<vector>
#include<numeric> //accumulate
using namespace std;

vector<string> dictionary;
string pat;

bool isSubsequence(string a, string b) {
    int i, j, m, n;
    i = j = 0;
    m = a.length(); n = b.length();
    while(i<m && j<n) {
        if(a[i]==b[j]) i++, j++;
        else j++;
    }
    return i==m;
}

// remove least no of characters from a inp for it to become dictionary word
// => translates to longest word in dictionary which is a subsequence of given inp 
void longestWordInDictionary() {
    string ans = "";
    for(string s: dictionary) {
        if(s.length() > ans.length() && isSubsequence(s, pat)) ans = s;
    }
    printf("ans = %s\n", ans.c_str());
}

int main() {
    dictionary.clear();
    
    string d[] = {"ale", "apple", "monkey", "plea"};
    dictionary.assign(d, d+4);
    
    string s = "";
    s = accumulate(begin(dictionary), end(dictionary), s, [](string &a, string &b) {
        return a.empty()? b: a+","+b;
    });

    printf("dictionary: %s\n", s.c_str());
    
    pat = "abpcplea";
    printf("pattern: %s\n", pat.c_str());

    longestWordInDictionary();
    return 0;
}