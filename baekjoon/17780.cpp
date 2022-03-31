#include <bits/stdc++.h>

using namespace std;
const int MN = 13;
int board[MN][MN];
struct node {
    int x, y, d;
    //node(int a, int b, int c) : x(a), y(b), d(c) {}
};
vector<int> horse[MN][MN];
node pos[MN];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main() {
    int N, K; cin >> N >> K;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> board[i][j];

    for(int i = 1; i <= K; i++) {
        int x, y, d; cin >> x >> y >> d; d--;
        horse[x][y].push_back(i);
        node n = {x, y, d};
        pos[i] = n;
    }
    int turn = 0;
    while(true) {
        turn++;
        if(turn > 1000) {
            cout << -1;
            return 0;
        }
        for(int i = 1; i <= K; i++) {
            int x = pos[i].x, y = pos[i].y;
            if(horse[x][y].front() != i) continue;
            int nx = x + dx[pos[i].d];
            int ny = y + dy[pos[i].d];
            if(nx > 0 && nx <= N && ny > 0 && ny <= N) {
                switch(board[nx][ny]) {
                    case 0://흰색은 그냥 이동
                        for(int e : horse[x][y]) {
                            horse[nx][ny].push_back(e);
                            pos[e].x = nx, pos[e].y = ny;
                        }
                        if(horse[nx][ny].size() >= 4) {
                            cout << turn;
                            return 0;
                        }
                        horse[x][y].clear();
                        break;
                    case 1: //빨간색은 위아래 바뀜
                        while(horse[x][y].size()) {
                            int e = horse[x][y].back(); horse[x][y].pop_back();
                            horse[nx][ny].push_back(e);
                            pos[e].x = nx, pos[e].y = ny;
                        }
                        if(horse[nx][ny].size() >= 4) {
                            cout << turn;
                            return 0;
                        }
                        break;
                    case 2: //파란색
                        int nd;
                        //방향 반대로
                        if(pos[i].d <= 1) nd = (pos[i].d == 0 ? 1 : 0);
                        else nd = (pos[i].d == 2 ? 3 : 2);
                        nx = x + dx[nd];
                        ny = y + dy[nd];
                        if(nx > 0 && nx <= N && ny > 0 && ny <= N) {
                            switch(board[nx][ny]) {
                                case 0:
                                    for(int e : horse[x][y]) {
                                        horse[nx][ny].push_back(e);
                                        pos[e].x = nx, pos[e].y = ny;
                                    }
                                    if(horse[nx][ny].size() >= 4) {
                                        cout << turn;
                                        return 0;
                                    }
                                    horse[x][y].clear();
                                    break;
                                case 1:
                                    while(horse[x][y].size()) {
                                        int e = horse[x][y].back(); horse[x][y].pop_back();
                                        horse[nx][ny].push_back(e);
                                        pos[e].x = nx, pos[e].y = ny;
                                    }
                                    if(horse[nx][ny].size() >= 4) {
                                        cout << turn;
                                        return 0;
                                    }
                                    break;
                                default:
                                    break;
                            }
                        }
                        pos[i].d = nd;
                        break;
                }
            }
            else {//파란색과 같이 동작
                int nd;
                //방향 반대로
                if(pos[i].d <= 1) nd = (pos[i].d == 0) ? 1 : 0;
                else nd = (pos[i].d == 2) ? 3 : 2;
                nx = x + dx[nd];
                ny = y + dy[nd];
                if(nx > 0 && nx <= N && ny > 0 && ny <= N) {
                    switch(board[nx][ny]) {
                        case 0:
                            for(int e : horse[x][y]) {
                                horse[nx][ny].push_back(e);
                                pos[e].x = nx, pos[e].y = ny;
                            }
                            if(horse[nx][ny].size() >= 4) {
                                cout << turn;
                                return 0;
                            }
                            horse[x][y].clear();
                            break;
                        case 1:
                            while(horse[x][y].size()) {
                                int e = horse[x][y].back(); horse[x][y].pop_back();
                                horse[nx][ny].push_back(e);
                                pos[e].x = nx, pos[e].y = ny;
                            }
                            if(horse[nx][ny].size() >= 4) {
                                cout << turn;
                                return 0;
                            }
                            break;
                        default:
                            break;
                    }
                }
                pos[i].d = nd;
            }
        }
    }
}