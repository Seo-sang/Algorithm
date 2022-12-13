#include <bits/stdc++.h>

using namespace std;

const int MN = 51;
int board[MN][MN];
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

int main() {
    int N, M; cin >> M >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> board[i][j];
}