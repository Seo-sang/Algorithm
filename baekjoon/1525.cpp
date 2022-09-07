#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int MN = 4;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int answer[MN][MN] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
set<string> vst;

struct node{
    int board[MN][MN];
    int d;
};

bool isCorrect(node& input) {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(input.board[i][j] != answer[i][j]) 
                return false;

    return true;
}

P ZeroPos(node& input) {
    for(int i= 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(input.board[i][j] == 0)
                return make_pair(i, j);

    return make_pair(-1, -1);
}

string to_str(node& input) {
    string ret = "";
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            ret += to_string(input.board[i][j]);

    return ret;
}

int main() {
    node a;
    a.d = 0;
    int ans = 0;
    for(int i = 0 ; i < 3; i++)
        for(int j= 0; j < 3; j++)
            cin >> a.board[i][j];
    if(isCorrect(a)) {
        cout << 0;
        return 0;
    }
    queue<node> q; q.push(a);
    vst.insert(to_str(a));
    while(!q.empty()) {
        node now = q.front(); q.pop();
        P pos = ZeroPos(now);
        for(int d = 0; d < 4; d++) {
            int nx = pos.first + dx[d];
            int ny = pos.second + dy[d];
            if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                node nxt = now;
                nxt.d++;
                nxt.board[pos.first][pos.second] = now.board[nx][ny];
                nxt.board[nx][ny] = now.board[pos.first][pos.second];
                string str = to_str(nxt);
                if(vst.find(str) == vst.end()) {
                    if(isCorrect(nxt)) {
                        cout << now.d + 1;
                        return 0;
                    }
                    q.push(nxt);
                    vst.insert(str);
                }
            }
        }
    }

    cout << -1;
}