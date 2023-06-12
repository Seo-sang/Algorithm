#include <bits/stdc++.h>

using namespace std;

const int MN = 4;
string arr[MN];
bool vst[MN][MN];
int N, M;

int dfs(int sum) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            //가로
            int x = i, y = j;
            while(!vst[x][y]) {
                vst[x][y] = true;

            }
            //세로
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];

    
}