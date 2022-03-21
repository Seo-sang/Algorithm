#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 21;
int N, M;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int arr[MN][MN];
int nxt[MN][MN];
bool vst[MN][MN];

void print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void gravity() {
    for(int i = N - 2; i >= 0; i--) {
        for(int j = 0; j < N; j++) {
            if(arr[i][j] < 0) continue;
            int idx = i+1;
            while(idx < N && arr[idx][j] == -100) {
                idx++;
            }
            idx--;
            arr[idx][j] = arr[i][j];
            if(idx != i)
                arr[i][j] = -100;
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];

    int ans = 0;
    while(true) {
        P pivot;
        int width = 0;
        int rainbow = 0;

        //그룹 선정
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(arr[i][j] < 1 || arr[i][j] > M) continue;
                memset(vst, 0, sizeof(vst));
                vst[i][j] = true;
                queue<P> q; q.push(make_pair(i, j));
                int cnt = 1;
                int rain = 0;
                while(!q.empty()) {
                    P now = q.front(); q.pop();
                    for(int d = 0; d < 4; d++) {
                        int nx = now.first + dx[d];
                        int ny = now.second + dy[d];
                        if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
                            if(vst[nx][ny]) continue;
                            if(arr[nx][ny] != 0 && arr[nx][ny] != arr[i][j]) continue;
                            if(arr[nx][ny] == 0) rain++;
                            vst[nx][ny] = true;
                            cnt++;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
                if(cnt > width) {
                    pivot = make_pair(i, j);
                    width = cnt;
                    rainbow = rain;
                }
                else if(cnt == width && rain > rainbow) {
                    pivot = make_pair(i, j);
                    rainbow = rain;
                }
                else if(cnt == width && rain == rainbow)
                    pivot = make_pair(i, j);
            }
        }

        //종료조건
        if(width < 2) break;

        //제거
        ans += width * width;
        memset(vst, 0, sizeof(vst));
        queue<P> q; q.push(pivot);
        vst[pivot.first][pivot.second] = true;
        while(!q.empty()) {
            P now = q.front(); q.pop();
            for(int d = 0; d < 4; d++) {
                int nx = now.first + dx[d];
                int ny = now.second + dy[d];
                if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if(vst[nx][ny]) continue;
                    if(arr[nx][ny] != 0 && arr[nx][ny] != arr[pivot.first][pivot.second]) continue;
                    vst[nx][ny] = true;
                    arr[nx][ny] = -100;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        arr[pivot.first][pivot.second] = -100;

        //중력
        gravity();

        //회전
        memset(nxt, 0, sizeof(nxt));
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                nxt[N - 1 - j][i] = arr[i][j];

        memcpy(arr, nxt, sizeof(arr));

        //중력
        gravity();
    }

    cout << ans;
}