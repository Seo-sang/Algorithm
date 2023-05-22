#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 251;
string arr[MN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
bool vst[MN][MN];

int main() {
    int R, C; cin >> R >> C;
    for(int i = 0; i < R; i++)
        cin >> arr[i];

    int sheep = 0, wolf = 0;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(arr[i][j] == '#' || vst[i][j]) continue;
            int sheep_tmp = 0, wolf_tmp = 0;
            if(arr[i][j] == 'o') sheep_tmp++;
            if(arr[i][j] == 'v') wolf_tmp++;
            vst[i][j] = true;
            queue<P> q;
            q.push(P(i, j));
            while(!q.empty()) {
                P now = q.front(); q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = now.first + dx[d];
                    int ny = now.second + dy[d];
                    if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
                        if(arr[nx][ny] == '#' || vst[nx][ny]) continue;
                        vst[nx][ny] = true;
                        if(arr[nx][ny] == 'o') sheep_tmp++;
                        if(arr[nx][ny] == 'v') wolf_tmp++;
                        q.push(P(nx, ny));
                    }
                }
            }
            if(sheep_tmp > wolf_tmp) sheep += sheep_tmp;
            else wolf += wolf_tmp;
        }
    }

    cout << sheep << ' ' << wolf;
}