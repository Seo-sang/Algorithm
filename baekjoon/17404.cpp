#include <iostream>

using namespace std;

const int MN = 1001;
const int INF = 1e9;

//인덱스, 현재, 처음
int home[MN][3][3];

int main() {
    int N; cin >> N;
    fill(&home[0][0][0], &home[MN-1][2][3], INF);
    int r, g, b; 
    cin >> r >> g >> b;
    home[1][0][0] = r;
    home[1][1][1] = g;
    home[1][2][2] = b;
    for(int i = 2; i <= N; i++) {
        cin >> r >> g >> b;
        home[i][0][0] = min(home[i-1][1][0], home[i-1][2][0]) + r;
        home[i][0][1] = min(home[i-1][1][1], home[i-1][2][1]) + r;
        home[i][0][2] = min(home[i-1][1][2], home[i-1][2][2]) + r;
        home[i][1][0] = min(home[i-1][0][0], home[i-1][2][0]) + g;
        home[i][1][1] = min(home[i-1][0][1], home[i-1][2][1]) + g;
        home[i][1][2] = min(home[i-1][0][2], home[i-1][2][2]) + g;
        home[i][2][0] = min(home[i-1][1][0], home[i-1][0][0]) + b;
        home[i][2][1] = min(home[i-1][1][1], home[i-1][0][1]) + b;
        home[i][2][2] = min(home[i-1][1][2], home[i-1][0][2]) + b;
    }
    int ans = INF;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == j) continue;
            ans = min(ans, home[N][i][j]);
        }
    }
    cout << ans;
}