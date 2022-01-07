#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

const int MN = 51;
const int INF = 1e9;

int R, C;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
string board[MN];
int water[MN][MN];

int main() {
    cin >> R >> C;
    pair<int,int> start;
    for(int i = 0; i < R; i++) {
        cin >> board[i];
        for(int j = 0; j < C; j++) {
            if(board[i][j] == 'S')
                start = {i, j};
        }
    }
}