#include<string>
#include<vector>
#include<bitset>
using namespace std;

typedef vector<char> vc;

bool isValidRow(int r, const vector<vc> &board) {
    bitset<10> dig;
    for(int j=0; j<9; j++) {
        char ch = board[r][j];
        if(ch != '.') {
            if(dig[ch] == 1) return false;
            else dig[ch] = 1;
        } 
    }
    return true;
}

bool isValidCol(int c, const vector<vc> &board) {
    bitset<10> dig;
    for(int i=0; i<9; ++i) {
        char ch = board[i][c];
        if(ch != '.') {
            if(dig[ch] == 1) return false;
            else dig[ch] = 1;
        }
    }
    return true;
}

bool isValidBox(int u, int v, const vector<vc> &board) {
    bitset<10> dig;
    for(int i=u; i<u+3; ++i)
    for(int j=v; j<v+3; ++j) {
        char ch = board[i][j];
        if(ch != '.') {
            if(dig[ch] == 1) return false;
            else dig[ch] = 1;
        }
    }
    return true;
}

bool isValid(const vector<vc> &board) {
    for (int i = 0; i < 9; ++i) 
        if(!isValidRow(i, board)) return false;
    for (int j =0; j < 9; ++j)
        if(!isValidCol(j, board)) return false;
    for (int i=0; i < 9; i+=3)
    for (int j=0; j < 9; j+=3)
        if(!isValidBox(i, j, board)) return false;
    return true;
}

int main() {
    // g++ std=c++11
    vector<vc> board = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' }, 
                         { '6', '.', '.', '1', '9', '5', '.', '.', '.' }, 
                         { '.', '9', '8', '.', '.', '.', '.', '6', '.' }, 
                         { '8', '.', '.', '.', '6', '.', '.', '.', '3' }, 
                         { '4', '.', '.', '8', '.', '3', '.', '.', '1' }, 
                         { '7', '.', '.', '.', '2', '.', '.', '.', '6' }, 
                         { '.', '6', '.', '.', '.', '.', '2', '8', '.' }, 
                         { '.', '.', '.', '4', '1', '9', '.', '.', '5' }, 
                         { '.', '.', '.', '.', '8', '.', '.', '7', '9' } }; 
    if(isValid(board)) printf("VALID!\n");
    else printf("INVALID!\n");
    return 0;
}