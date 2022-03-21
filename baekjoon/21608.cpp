#include <bits/stdc++.h>

using namespace std;
const int MN = 21;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int arr[MN][MN];
int sat[5] = {0, 1, 10, 100, 1000};
struct pos {
    int x, y, frnd, ety;
};

struct like {
    int s1, s2, s3, s4;
};

bool cmp(pos a, pos b) {
    if(a.frnd == b.frnd) {
        if(a.ety == b.ety) {
            if(a.x == b.x) return a.y < b.y;
            return a.x < b.x;
        }
        return a.ety > b.ety;
    }
    return a.frnd > b.frnd;
}

int main() {
    int N; cin >> N;
    int NN = N * N;
    vector<pos> candidate;
    map<int, like> m;
    for(int i = 0; i < NN; i++) {
        like l;
        int s; cin >> s >> l.s1 >> l.s2 >> l.s3 >> l.s4;
        m[s] = l;
        candidate.clear();
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(arr[i][j]) continue;
                int ety = 0;
                int frnd = 0;
                for(int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(nx > 0 && nx <= N && ny > 0 && ny <= N) {
                        if(arr[nx][ny] == 0) ety++;
                        else if(arr[nx][ny] == l.s1 || arr[nx][ny] == l.s2 || arr[nx][ny] == l.s3 || arr[nx][ny] == l.s4) frnd++;
                    }
                }
                pos p = {i, j, frnd, ety};
                candidate.push_back(p);
            }
        }
        sort(candidate.begin(), candidate.end(), cmp);
        arr[candidate[0].x][candidate[0].y] = s;
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            like tmp = m[arr[i][j]];
            int cnt = 0;
            for(int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(nx > 0 && nx <= N && ny > 0 && ny <= N) {
                    if(arr[nx][ny] == tmp.s1 || arr[nx][ny] == tmp.s2 || arr[nx][ny] == tmp.s3 || arr[nx][ny] == tmp.s4)
                        cnt++;
                }
            }
            ans += sat[cnt];
        }
    }
    cout << ans;
}