#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int MN = 500;
int arr[MN][MN];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
struct wind {
    int x, y, ratio;
};
wind dir[4][9] = {
    {{-1, 1, 1}, {1, 1, 1}, {-2, 0, 2}, {-1, 0, 7}, {1, 0, 7}, {2, 0, 2}, {-1, -1, 10}, {1, -1, 10}, {0, -2, 5}},
    {{-1,-1, 1}, {-1, 1,1}, {0, -2, 2}, {0, 2, 2}, {0, -1, 7}, {0, 1, 7}, {1, 1, 10}, {1, -1, 10}, {2, 0, 5}},
    {{-1, -1, 1}, {1, -1, 1}, {-2, 0, 2}, {-1, 0, 7}, {1, 0, 7}, {2, 0, 2}, {-1, 1, 10}, {1, 1, 10}, {0, 2, 5}},
    {{1, -1, 1}, {1, 1, 1}, {0, -2, 2}, {0, -1, 7}, {0, 1, 7}, {0, 2, 2}, {-1, -1, 10}, {-1, 1, 10}, {-2, 0, 5}}
};
int N, d, len, ans;


int main() {
    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];

    P x = make_pair(N/2, N/2);
    while(true) {
        if(d % 2 == 0) len++;
        for(int i = 0; i < len; i++) {
            P y = make_pair(x.first + dx[d], x.second + dy[d]);
            if(x.first == 0 && x.second == 0) {
                cout << ans;
                return 0;
            }
            int alpha = arr[y.first][y.second];
            for(int j = 0; j < 9; j++) {
                int a = y.first + dir[d][j].x;
                int b = y.second + dir[d][j].y;
                int dust = (arr[y.first][y.second] * dir[d][j].ratio) / 100;
                alpha -= dust;
                if(a >= 0 && a < N && b >= 0 && b < N)
                    arr[a][b] += dust;
                else
                    ans += dust;
            }
            if(y.first + dx[d] >= 0 && y.first + dx[d] < N && y.second + dy[d] >= 0 && y.second + dy[d] < N) 
                arr[y.first + dx[d]][y.second + dy[d]] += alpha;
            else
                ans += alpha;
            x = y;
            arr[y.first][y.second] = 0;
            //print();
        }
        d = (d + 1) % 4;
    }
    
}