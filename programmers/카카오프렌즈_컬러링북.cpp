#include <bits/stdc++.h>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
const int MN = 101;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
bool vst[MN][MN];

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    memset(vst, 0, sizeof(vst));
    vector<int> answer(2);
    answer[0] = answer[1] = 0;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(vst[i][j] || picture[i][j] == 0) continue;
            vst[i][j] = true;
            int color = picture[i][j];
            answer[0]++;
            queue<pair<int,int> > q;
            q.push(make_pair(i, j));
            int volume = 1;
            while(!q.empty()) {
                pair<int,int> now = q.front(); q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = now.first + dx[d];
                    int ny = now.second + dy[d];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        if(vst[nx][ny] || picture[nx][ny] != color) continue;
                        vst[nx][ny] = true;
                        volume++;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
            answer[1] = max(answer[1], volume);
        }
    }
    
    return answer;
}