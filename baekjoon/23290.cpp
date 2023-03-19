#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;

const int MN = 5;

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int ddx[4] = {-1, 0, 1, 0};
int ddy[4] = {0, -1, 0, 1};

vector<int> arr[MN][MN];
vector<int> tmp[MN][MN];
int smell[MN][MN];
int vst[MN][MN];
int mnum;
P shark;
string path;

void level1() {
    for(int i = 1; i < MN; i++)
        for(int j = 1; j < MN; j++)
            tmp[i][j] = arr[i][j];
}

void level2() {
    vector<int> nxt[MN][MN];

    for(int i = 1; i < MN; i++)
        for(int j = 1; j < MN; j++)
            nxt[i][j].clear();

    for(int i = 1; i < MN; i++) {
        for(int j = 1; j < MN; j++) {
            for(int fish : arr[i][j]) {
                int nx, ny;
                bool chk = false;
                for(int d = 8; d > 0; d--) {
                    nx = i + dx[(fish + d) % 8];
                    ny = j + dy[(fish + d) % 8];
                    if(nx > 0 && nx < MN && ny > 0 && ny < MN) {
                        if((shark.first == nx && shark.second == ny) || smell[nx][ny] > 0) continue;
                        nxt[nx][ny].push_back((fish + d) % 8);
                        chk = true;
                        break;
                    }
                }
                if(!chk) nxt[i][j].push_back(fish);
            }
        }
    }
    
    for(int i = 1; i < MN; i++)
        for(int j = 1; j < MN; j++)
            arr[i][j] = nxt[i][j];
}


void dfs(int x, int y, string str, int cnt) {
    if(str.length() == 3) {
        if(mnum < cnt) {
            path = str;
            mnum = cnt;
        }
        return;
    }

    for(int d = 0; d < 4; d++) {
        int nx = x + ddx[d];
        int ny = y + ddy[d];
        if(nx > 0 && nx < MN && ny > 0 && ny < MN) {
            if(vst[nx][ny]) {
                vst[nx][ny]++;
                dfs(nx, ny, str + to_string(d), cnt);
                vst[nx][ny]--;
            }
            else {
                vst[nx][ny]++;
                dfs(nx, ny, str + to_string(d), cnt + arr[nx][ny].size());
                vst[nx][ny]--;
            }
        }
    }
}

void level3() {
    //상어 이동
    mnum = -1;
    memset(vst, 0, sizeof(vst));
    //vst[shark.first][shark.second]++;
    dfs(shark.first, shark.second, "", 0);
    //vst[shark.first][shark.second]--;


    for(char c : path) {
        int d = c - '0';
        shark.first += ddx[d];
        shark.second += ddy[d];
        if(arr[shark.first][shark.second].size() > 0) {
            arr[shark.first][shark.second].clear();
            smell[shark.first][shark.second] = 3;
        }
    }
}

void level4() {
    for(int i = 1; i < MN; i++)
        for(int j = 1; j < MN; j++)
            if(smell[i][j] > 0)
                smell[i][j]--;
}


void level5() {
    for(int i = 1; i < MN; i++)
        for(int j = 1; j < MN; j++)
            for(int e : tmp[i][j])
                arr[i][j].push_back(e);
}


void print() {
    for(int i = 1; i < MN; i++) {
        for(int j = 1; j < MN; j++) {
            cout << arr[i][j].size() << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int M, S; cin >> M >> S;

    for(int i = 0; i < M; i++) {
        int x, y, d; cin >> x >> y >> d;
        arr[x][y].push_back(d - 1);
    }
    cin >> shark.first >> shark.second;

    while(S--) {
        level1();
        level2();
        level3();
        level4();
        level5();
    }

    int ans = 0;

    for(int i = 1; i < MN; i++)
        for(int j = 1; j < MN; j++)
            ans += arr[i][j].size();

    cout << ans;
}