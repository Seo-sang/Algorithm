#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 51;
int N, M;
int board[MN][MN], nxt[MN][MN];
bool dis[MN][MN]; //사라진 구름 위치 표시
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int cx[4] = {1, 1, -1, -1};
int cy[4] = {1, -1, 1, -1};
vector<P> cloud;

int main() {
    cin >> N >> M;
    for(int i  = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> board[i][j];

    cloud.push_back(make_pair(N-1, 0));
    cloud.push_back(make_pair(N-1, 1));
    cloud.push_back(make_pair(N-2, 0));
    cloud.push_back(make_pair(N-2, 1));
    while(M--) {
        int d, s; cin >> d >> s; d--;
        //구름 이동 후 비내리기
        memset(dis, 0, sizeof(dis));
        for(P &e : cloud) {
            e.first += (dx[d] * s);
            e.second += (dy[d] * s);
            e.first += N * 50, e.second += N * 50;
            e.first %= N, e.second %= N;
            board[e.first][e.second]++;
            dis[e.first][e.second]= true;
        }
        memcpy(nxt, board, sizeof(nxt));
        for(P e : cloud) {
            int cnt = 0;
            for(int c = 0; c < 4; c++) {
                int nx = e.first + cx[c];
                int ny = e.second + cy[c];
                if(nx >= 0 && nx < N && ny >= 0 && ny < N)
                    if(board[nx][ny] > 0) nxt[e.first][e.second]++;
            }
        }
        memcpy(board, nxt, sizeof(board));
        //구름 사라짐
        cloud.clear();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] >= 2 && !dis[i][j]) {
                    cloud.push_back(make_pair(i, j));
                    board[i][j] -= 2;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            ans += board[i][j];
    
    cout << ans;
}