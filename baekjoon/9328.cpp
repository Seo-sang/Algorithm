#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 101;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
string board[MN];
bool vst[MN][MN];
map<char, vector<P>> pos;
set<char> key;
set<P> start;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;

    while(T--) {
        int H, W; cin >> H >> W;
        start.clear();
        key.clear();
        pos.clear();
        memset(vst, 0, sizeof(vst));
        for(int i = 0; i < H; i++) {
            cin >> board[i];
            for(int j = 0; j < W; j++) {
                if(i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                    if(board[i][j] == '*') continue;
                    start.insert(make_pair(i, j));
                }
            }
        }
        string str; cin >> str;
        if(str != "0")
            for(char c : str) key.insert(c);
        int ans = 0;
        for(P e : start) {
            queue<P> q;
            if(vst[e.first][e.second]) continue;
            vst[e.first][e.second] = true;
            char c = board[e.first][e.second];
            if(islower(c)) {
                key.insert(c);
                if(pos.find(toupper(c)) != pos.end()) {
                    for(P p : pos[toupper(c)])
                        q.push(p);
                }
            }
            else if(isupper(c)) {
                if(key.find(tolower(c)) == key.end()) {
                    pos[c].push_back(e);
                    continue;
                }
            }
            else if(c == '$'){
                ans++;
            }
            q.push(e);
            while(!q.empty()) {
                P now = q.front(); q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = now.first + dx[d];
                    int ny = now.second + dy[d];
                    if(nx >= 0 && nx < H && ny >= 0 && ny < W) {
                        if(vst[nx][ny] || board[nx][ny] == '*') continue;
                        vst[nx][ny] = true;
                        char c = board[nx][ny];
                        if(islower(c)) {
                            key.insert(c);
                            if(pos.find(toupper(c)) != pos.end()) {
                                for(P p : pos[toupper(c)])
                                    q.push(p);
                            }
                        }
                        else if(isupper(c)) {
                            if(key.find(tolower(c)) == key.end()) {
                                pos[c].push_back(make_pair(nx, ny));
                                continue;
                            }
                        }
                        else if(c == '$') {
                            ans++;
                        }
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}