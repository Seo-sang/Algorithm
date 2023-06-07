#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;
const int MN = 51;
const int INF = 1e9;

vector<pii> car, park;
string board[MN];
bool vst[MN][MN];
bool vstpark[MN * 2];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int R, C;

struct node {
    int x, y, cnt;
    node(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {}
};

int dfs(int c) {
    for(int i = 0; i < park.size(); i++) {
        if(vstpark[i]) continue;
        vstpark[i] = true;
        memset(vst, 0, sizeof(vst));
        vst[car[c].first][car[c].second] = true;
        queue<node> q; q.push(node(car[c].first, car[c].second, 0));
        while(!q.empty()) {
            node now = q.front(); q.pop();
            for(int d = 0; d < 4; d++) {
                
            }
        }
        vstpark[i] = false;
    }
}

int f(int mid) {
    int ret = INF;
    ret = 

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        cin >> board[i];
    }

    int left = 0, right = MN * MN;
    while(left + 1 < right) {
        int mid = (left + right) / 2;
        int ret = f(mid);
    }
}