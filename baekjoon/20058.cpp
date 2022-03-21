#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int MN = 65;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int arr[MN][MN], tmp[MN][MN];
bool vst[MN][MN];

void rotate(int x, int y, int len) {

    for(int i = 0; i < len; i++) 
        for(int j = 0; j < len; j++)
            tmp[x + j][y + len - 1 - i] = arr[i + x][y + j];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, Q; cin >> N >> Q;
    N = pow(2, N);
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];

    while(Q--) {
        int L; cin >> L;
        int len = pow(2, L);
        memset(tmp, 0, sizeof(tmp));
        for(int i = 0; i < N; i += len)
            for(int j = 0; j < N; j += len)
                rotate(i, j, len);

        memcpy(arr, tmp, sizeof(arr));

        memset(tmp, 0, sizeof(tmp));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                int cnt = 0;
                for(int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(nx >= 0 && nx < N && ny >= 0 && ny < N)
                        if(arr[nx][ny] > 0) cnt++;
                }
                if(cnt < 3 && arr[i][j] > 0) tmp[i][j] = arr[i][j] - 1;
                else tmp[i][j] = arr[i][j];
            }
        }

        memcpy(arr, tmp, sizeof(arr));
    }

    int sum = 0;
    int mnum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            sum += arr[i][j];
            if(vst[i][j] || arr[i][j] == 0) continue;
            int cnt = 1;
            queue<P> q;
            vst[i][j] = true;
            q.push(make_pair(i, j));
            while(!q.empty()) {
                P now = q.front(); q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = now.first + dx[d];
                    int ny = now.second + dy[d];
                    if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
                        if(vst[nx][ny] || arr[nx][ny] == 0) continue;
                        vst[nx][ny] = true;
                        cnt++;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
            mnum = max(mnum, cnt);
        }
    }
    cout << sum << '\n' << mnum;
}