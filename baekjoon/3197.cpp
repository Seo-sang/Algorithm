#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int R, C;
const int MN = 1501;
bool water[MN][MN];
bool vst[MN][MN];
queue<P> nowswan, nxtswan;
queue<P> nowwater, nxtwater;

bool move(P swan) {
    while(!nowswan.empty()) {
        P now = nowswan.front(); nowswan.pop();
        for(int d = 0; d < 4; d++) {
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];
            if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
                if(vst[nx][ny]) continue;
                vst[nx][ny] = true;
                if(!water[nx][ny]) continue;
                if(nx == swan.first && ny == swan.second) return true;
                nowswan.push(make_pair(nx, ny));
            }
        }
    }
    return false;
}

void melt() {

    //다음 얼음 추가
    while(!nowwater.empty()) {
        P now = nowwater.front(); nowwater.pop();
        for(int d = 0; d < 4; d++) {
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];
            if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
                if(water[nx][ny]) continue;
                water[nx][ny] = true;
                if(vst[nx][ny]) nxtswan.push(make_pair(nx, ny));
                nxtwater.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string str;
    P swan;
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        cin >> str;
        for(int j = 0; j < C; j++) {
            if(str[j] == 'X') continue;
            if(str[j] == 'L') {
                if(nowswan.empty()) {
                    nowswan.push(make_pair(i, j));
                    vst[i][j] = true;
                }
                else {
                    swan = make_pair(i, j);
                }
            }
            nowwater.push(make_pair(i, j));
            water[i][j] = true;
        }
    }
    int ans = 0;
    while(true) {
        if(move(swan)) break;
        melt();
        nowswan = nxtswan;
        nxtswan = queue<P>();
        nowwater = nxtwater;
        nxtwater = queue<P>();
        ans++;
    }

    cout << ans;
}