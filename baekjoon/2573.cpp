#include <iostream>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

const int MN = 301;
int ice[MN][MN];
int after[MN][MN];
bool visit[MN][MN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int N, M;
set<pair<int,int>> s1;
set<pair<int,int>> s2;

int ans;

bool isEnd() {
    if(!s1.size()) {
        ans = 0;
        return true;
    }
    auto it = s1.begin();
    memset(visit, 0, sizeof(visit));
    visit[it->first][it->second] = true;
    queue<pair<int,int>> q;
    q.push({it->first, it->second});
    int count = 1;
    while(!q.empty()) {
        pair<int,int> now = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(visit[nx][ny] || ice[nx][ny] == 0) continue;
                visit[nx][ny] = true;
                count++;
                q.push({nx, ny});
            }
        }
    }
    if(s1.size() == count) return false;
    else return true;
}

void print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << ice[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    cin >> N >> M;
    for(int i = 0;  i< N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> ice[i][j];
            if(ice[i][j])
                s1.insert({i, j});
        }
    }

    while(!isEnd()) {
        s2.clear();
        for(auto it = s1.begin(); it != s1.end(); it++) {
            int x = it->first;
            int y = it->second;
            int blank = 0;
            for(int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx >= 0 && nx < N && ny >= 0 && ny < M)
                    if(ice[nx][ny] == 0) 
                        blank++;
            }
            int rst = ice[x][y] - blank;
            after[x][y] = (rst < 0 ? 0 : rst);
            if(after[x][y] != 0) s2.insert({x, y});
        }
        memcpy(ice, after, sizeof(ice));

        s1 = s2;
        ans++;
    }

    cout << ans;
}