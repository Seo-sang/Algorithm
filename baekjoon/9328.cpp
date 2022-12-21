#include <bits/stdc++.h>

using namespace std;

const int MN = 101;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
struct node {
    int x, y;
    set<char> s;
    node(int x, int y, set<char> s) : x(x), y(y), s(s) {}
};
string board[MN];
set<char> key;
set<char> dp[MN][MN];

int main() {
    int T; cin >> T;
    while(T--) {
        int H, W; cin >> H >> W;
        queue<node> q;
        for(int i = 0; i < H; i++) {
            cin >> board[i];
        }
        string keys; cin >> keys;
        sort(keys.begin(), keys.end());
        if(keys != "0")
            for(char c : keys) 
                key.insert(c);
        int ans = 0;
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(i == 0 || i == H -1  || j == 0 || j == W - 1) {
                    if(board[i][j] == '.') {
                        q.push(node(i, j, key));
                        dp[i][j] = key;
                    }
                    else if(board[i][j] == '$') {
                        q.push(node(i, j, key));
                        dp[i][j] = key;
                        ans++;
                    }
                    else if(board[i][j] != '*') {
                        if(islower(board[i][j])) {
                            set<char> tmp = key;
                            tmp.insert(board[i][j]);
                            q.push(node(i, j, tmp));
                            dp[i][j] = tmp;
                        }
                        else if(isupper(board[i][j])) {
                            if(key.find(tolower(board[i][j])) != key.end()) {
                                q.push(node(i, j, key));
                                dp[i][j] = key;
                            }
                        }
                    }
                }
            }
        }
        
        while(!q.empty()) {
            node now = q.front(); q.pop();
            for(int d = 0; d < 4; d++) {
                
            }
        }


        cout << ans << '\n';
    }
}